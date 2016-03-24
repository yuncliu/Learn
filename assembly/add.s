.data
    msg : .string "Num = %ld\n"
    len = .-msg

.global main

.extern printf

.text

main:
    push   %rbx
    mov    $10, %rdx
    mov    $20, %rcx
    add    %rcx, %rdx
    mov    $msg,%rdi
    mov    %rdx,%rsi
    call   printf
    mov    $0x10,%rax
    pop    %rbx
    ret
