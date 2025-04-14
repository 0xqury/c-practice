from pwn import *

elf = ELF('./ret2libc_test')
print("puts@got =", hex(elf.got['puts']))