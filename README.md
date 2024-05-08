# Usage

## The shellcode python generator

It uses the simplest "execve /bin/sh" shellcode by default

```bash
python3 generate_shellcode.py                                                                
Shellcode: 4831c05048bf2f2f62696e2f7368574889e74831f64831d2b03b0f05
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
