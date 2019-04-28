#include "str.h"
#include <stdlib.h>
#include <string.h>

__asm__(
       INTEL_BEGIN
       "str32len:\n"
       "   push ebp\n"
       "   mov ebp, esp\n"
       "   mov edi, [ebp + 8]\n"
       "   sub ecx, ecx\n"
       "   not ecx\n"
       "   sub al, al\n"
       "   cld\n"
       "   repnz scasb\n"
       "   not ecx\n"
       "   lea eax, [ecx - 1]\n"
       "   mov esp, ebp\n"
       "   pop ebp\n"
       "   ret\n"
       INTEL_END
);

__asm__(
       INTEL_BEGIN
       "str32cpy:\n"
       "   push ebp\n"
       "   mov ebp, esp\n"
       "   mov edi, [ebp + 8]\n"
       "   mov esi, [ebp + 12]\n"
       "   sub ecx, ecx\n"
       "   not ecx\n"
       "   sub al, al\n"
       "   cld\n"
       "   repne scasb\n"
       "   not ecx\n"
       "   lea eax, [ecx - 1]\n"
       "   mov esp, ebp\n"
       "   pop ebp\n"
       "   ret\n"
       INTEL_END
);

int main()
{
    puts("-----STR32LEN-------");
    printf("0 => %d\n",str32len(""));
    printf("1 => %d\n",str32len("a"));
    printf("4 => %d\n",str32len("chat"));
    printf("10 => %d\n",str32len("abcdefghij"));

    puts("-----STR32CPY-------");
    char *dest = malloc(sizeof(char) * (strlen("chat") + 1));
    
    return 0;
}
