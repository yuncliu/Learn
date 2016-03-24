.data
    msg : .string "Num = %ld\n"
    len = .-msg


.global main
.extern printf

.text
main:
#   push    %rbp
    mov     %rsp, %rbp
    sub     $16, %rsp
    call    fun1
    add     $16, %rsp
#   pop     %rbp
    ret

fun1:
    push    %rbp
    mov     %rsp, %rbp
    sub     $16, %rsp
    call    fun2
    add     $16, %rsp
    pop     %rbp
    ret

fun2:
    push    %rbp
    mov     %rsp, %rbp
    sub     $16, %rsp
    mov     $5, %rdi
    call    print
    add     $16, %rsp
    pop     %rbp
    ret

print:
    push    %rbp
    mov     %rsp, %rbp
    sub     $16, %rsp
    push    %rbx
    mov     %rdi, %rdx
    mov     $msg,%rdi
    mov     %rdx,%rsi
    call    printf
    pop     %rbx
    add     $16, %rsp
    pop     %rbp
    ret
