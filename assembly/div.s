.data
    msg : .string "Num = %ld %ld\n"
    len = .-msg

.text

.global main
.global example

.extern printf

main:
    push    %rbx
    mov     $100, %rax  #dividend
    mov     $3,  %rbx   #divisor
    mov     $0,  %rdx   #reminder
    idiv    %rbx        #quotient is in %rax
    mov     $msg,%rdi
    mov     %rax,%rsi
    call    printf
    pop     %rbx
    ret
