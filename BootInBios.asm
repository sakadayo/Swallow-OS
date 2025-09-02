[BITS 16]
[ORG 0x7C00]

start:
    mov si, message

.print_char:
    lodsb
    cmp al, 0
    je .done
    mov ah, 0x0E
    int 0x10
    jmp .print_char

.done:
    cli
    hlt

message db 'Hello, World', 0

times 510 - ($ - $$) db 0
dw 0xAA55