#include <stdio.h>
#include <sys/types.h>

int main(int arg, char* argv[]) {
    int64_t a = 100;
    int64_t b = 7;
    int64_t result = 0;
    int64_t reminder = 0;
    __asm__ (
            "mov %0, %%rax\n"
            "mov %1, %%rbx\n"
            "xor %%rdx, %%rdx\n"
            "idiv %%rbx\n"
            "mov %%rax, %2\n"
            "mov %%rdx, %3\n"
            :                                           // OutputOperands
            :"m"(a), "m"(b),"m"(result),"m"(reminder)   // InputsOperands
            :                                           // Clobbers
            );
#ifdef linux
    printf("result = %ld,  reminder %ld\n", result, reminder);
#else
    printf("result = %lld,  reminder %lld\n", result, reminder);
#endif
    return 0;
}
