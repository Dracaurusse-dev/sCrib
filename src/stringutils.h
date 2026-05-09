#ifndef STRINGUTILS_H
#define STRINGUTILS_H


#include <stdint.h>
#include <stddef.h>


char **getcmd(char *cmd, size_t cmdlen);

uint8_t startswith(char *s1, char *s2);
uint8_t strtou8(char *s);


#endif  // STRINGUTILS_H
