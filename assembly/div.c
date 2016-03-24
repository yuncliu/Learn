#include <stdio.h>

int main(int arg, char* argv[]) {
    int a = 100;
    int b = 7;
    int result = 0;
    int reminder = 0;
    /*
     * those numbers is 32bits, to must use eax, ebx ...32bits registers
     */
    __asm__ volatile ("mov %0, %%eax\n"
            "mov %1, %%ebx\n"
            "xor %%edx, %%edx\n"   // set the register to zero
            "idiv %%ebx\n"
            "mov %%eax, %2\n"
            "mov %%edx, %3\n"
            :                                            // OutputOperands
            :"m"(a), "m"(b), "m"(result), "m"(reminder)  // InputOperands
            :                                            // Clobbers
            );
    printf("result = %d,  reminder %d\n", result, reminder);
    return 0;
}
