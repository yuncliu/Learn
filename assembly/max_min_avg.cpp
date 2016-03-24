/*
 * visual studio example
 * quite sample than gcc
 */
#include <iostream>
using namespace std;
#define MAX 3
int main(int argc, char const* argv[])
{
    float sum=0;
    float avg = 0;
    float max=0;
    float min = 0;
    int count = 0;
    float num = MAX;
    cout << "input" <<endl;
    for(int i = 0;i < MAX;i++)
    {
        float x = 0;
        cin >> x;
        __asm {
            movss xmm0, x
            movss xmm1, sum
            addss xmm1, xmm0
            movss sum, xmm1

            cmp i, 0
            je initmin
            jmp initminpass
            initmin:
                movss xmm0, x
                movss min, xmm0
            initminpass:

            movss xmm0, x
            movss xmm1, max
            ucomiss xmm1, xmm0
            jbe asignmax
            jmp maxpass
            asignmax:
                movss max, xmm0
                jmp maxpass
            maxpass:

            movss xmm0, x
            movss xmm1, min
            ucomiss xmm0, xmm1
            jbe asignmin
            jmp minpass
            asignmin:
                movss min, xmm0
                jmp minpass
            minpass:
        }
        printf("min is %f,  max is %f x is %f\n", min, max, x);
    }
    __asm {
        movss xmm0, num
        movss xmm1, sum
        divss xmm1, xmm0
        movss avg, xmm1
    }
    cout << "highest" << max <<endl;
    cout << "lowest:" << min <<endl;
    cout << "average:" << avg <<endl;
    return 0;
};
