; nasm -felf64 add.asm ;gcc add.o

global main

extern printf

section .text
main:
    push   rbx
    mov    rdx, 10
    mov    rcx, 20
    add    rdx, rcx
    mov    rdi, msg
    mov    rsi, rdx
    call   printf
    mov    rax, 0x10
    pop    rbx
    ret

msg :
    db "Num = %ld", 10, 0   ; 10 meanes \n
                            ; 0 string ends with 0 in C
