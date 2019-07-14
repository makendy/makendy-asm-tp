#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INTEL_BEGIN "\n.intel_syntax noprefix\n"
#define INTEL_END ".att_syntax prefix\n"

/*
int bitsetnum(int size, char *buffer)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        int c = buffer[i];
        while( c > 0)
        {
            if (c % 2 == 1)
                count++;
            c /= 2;
        }
    }
    return count;
}
*/

int bitsetnum(int size, char *buffer);
__asm__(
INTEL_BEGIN
    "bitsetnum:\n"
    "push    rbp\n"
    "mov     rbp, rsp\n"
    "mov     DWORD PTR [rbp-20], edi\n"
    "mov     QWORD PTR [rbp-32], rsi\n"
    "mov     DWORD PTR [rbp-4], 0\n"
    "mov     DWORD PTR [rbp-8], 0\n"
    "jmp     .L22\n"
".L6:\n"
    "mov     eax, DWORD PTR [rbp-8]\n"
    "movsx   rdx, eax\n"
    "mov     rax, QWORD PTR [rbp-32]\n"
    "add     rax, rdx\n"
    "movzx   eax, BYTE PTR [rax]\n"
    "movsx   eax, al\n"
    "mov     DWORD PTR [rbp-12], eax\n"
    "jmp     .L33\n"
".L5:\n"
    "mov     eax, DWORD PTR [rbp-12]\n"
    "cdq\n"
    "shr     edx, 31\n"
    "add     eax, edx\n"
    "and     eax, 1\n"
    "sub     eax, edx\n"
    "cmp     eax, 1\n"
    "jne     .L4\n"
    "add     DWORD PTR [rbp-4], 1\n"
".L4:\n"
    "mov     eax, DWORD PTR [rbp-12]\n"
    "mov     edx, eax\n"
    "shr     edx, 31\n"
    "add     eax, edx\n"
    "sar     eax\n"
    "mov     DWORD PTR [rbp-12], eax\n"
".L33:\n"
    "cmp     DWORD PTR [rbp-12], 0\n"
    "jg      .L5\n"
    "add     DWORD PTR [rbp-8], 1\n"
".L22:\n"
    "mov     eax, DWORD PTR [rbp-8]\n"
    "cmp     eax, DWORD PTR [rbp-20]\n"
    "jl      .L6\n"
    "mov     eax, DWORD PTR [rbp-4]\n"
    "pop     rbp\n"
    "ret\n"
INTEL_END
);

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        printf("Number of bits set to 1 in %s : %d\n",
            argv[i], bitsetnum(strlen(argv[i]), argv[i]));
    return 0;
}