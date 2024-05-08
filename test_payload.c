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
