#ifndef __STR_H
#define __STR_H

#include <stdio.h>
#define INTEL_BEGIN "\n.intel_syntax noprefix\n"
#define INTEL_END ".att_syntax prefix\n"

//here __dest__ must be large enough to store the result.
char *str32cpy(char *dest, char *src);
int str32ncmp(const char *s1, const char *s2, int n);
int str32len(const char *s1);

#endif /* __STR_H */
