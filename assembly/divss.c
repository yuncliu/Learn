/*
 * divss usage
 */
#include <stdio.h>

int main(int arg, char* argv[]) {
    float a = 9;
    float b = 100;
    float result = 0.0;
    __asm__ volatile ("movss %0, %%xmm0\n"
            "movss %1, %%xmm1\n"
            "divss %%xmm0, %%xmm1\n"      // xmm1 = xmm1/xmm0
            "movss %%xmm1, %2\n"
            :                             // OutputOperands
            :"m"(a), "m"(b), "m"(result)  // InputOperands
            :                             // Clobbers
            );
    printf("result = %f\n", result);
    return 0;
}
