; nasm -felf64 factorial.asm ;gcc factorial.o
        global  main
        extern  printf
        section .text
main:
    push    rbx
    mov     rdi, 10
    mov     rax, 0
    call    func
    mov     rdi, msg
    mov     rsi, rax
    call    printf
    mov     rax, 0
    pop     rbx
    ret

func:
    mov     rax, rdi
funcc:
    sub     rdi, 1
    imul    rax, rdi
    cmp     rdi, 1
    jne     funcc    ; jump if not qual
    ret

msg :
    db "Num = %ld", 10, 0   ; 10 meanes \n
                            ; 0 string ends with 0 in C
