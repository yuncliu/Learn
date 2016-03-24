.data
    msg : .string "Num = %ld\n"
    len = .-msg

.text

.global main
.global example

.extern printf

main:
    push    %rbx
    mov     $5, %rdi
    call    example
    mov     $msg,%rdi
    mov     %rax,%rsi
    call    printf
    mov     $0x10,%rax
    pop     %rbx
    ret

example:
    sub     $8, %rsp
    movq     $10, (%rsp)
    mov     %edi, %eax
    imul    (%rsp), %rax
    add     $8, %rsp
    ret
