.data
    msg : .string "Num = %ld\n"
    len = .-msg

.global main

.extern printf

.text
main:
    push   %rbx
    mov    $msg,%rdi
    mov    $len,%rsi
    call   printf
    mov    $0x10,%rax
    pop    %rbx
    ret
