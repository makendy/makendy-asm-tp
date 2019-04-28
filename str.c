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
       "   mov edx, [ebp + 12]\n"
       "   push edx\n"
       "   call str32len\n"

       "   push eax\n"
       "   pop  edx\n"

       "   mov ecx, eax\n"
       "   mov edi, [ebp + 8]\n"
       "   mov esi, [ebp + 12]\n"
       "   rep movsb\n"

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
    printf("4 => %d\n",str32len("cats"));
    printf("10 => %d\n",str32len("abcdefghij"));

    puts("-----STR32CPY-------");
    char *dest = malloc(sizeof(char) * (strlen("cats") + 1));
    char *dest1 = malloc(sizeof(char) * (strlen("kittens") + 1));
    char *dest2 = malloc(sizeof(char) * (strlen("cats and kittens") + 1));
    str32cpy(dest, "cats");
    str32cpy(dest1, "kittens");
    str32cpy(dest2, "cats and kittens");
    printf("copy of cats with dest => \"%s\"\n", dest);
    printf("copy of kittens with dest1 => \"%s\"\n", dest1);
    printf("copy of cats and kittens with dest2 => \"%s\"\n", dest2);

    puts("-----STR32NCPM-------");
    return 0;
}
