#include "stringutils.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char **getcmd(char *cmd, size_t cmdlen)
{
	const uint8_t MAX_ARGC = 5;
	const uint8_t MAX_ARG_SIZE = 16;
	uint8_t currargsize = 0;
	size_t currargc = 0;
	char **res = (char **) calloc(MAX_ARGC, sizeof(char *));

	res[currargc] = (char *) calloc(MAX_ARG_SIZE, sizeof(char)); 

	for (size_t i = 0; i < cmdlen; i++)
	{
		if (cmd[i] == 0)
			break;

		if (cmd[i] == ' ' && currargc == 0)
		{
			res[currargc++][currargsize] = 0;
			currargsize = 0;
			res[currargc] = (char *) calloc(MAX_ARG_SIZE, sizeof(char));
			continue;
		}
		
		res[currargc][currargsize++] = cmd[i];
	}

	return res;
}


uint8_t startswith(char *s1, char *s2)
{
	size_t len = (size_t) fmin((double) strlen(s1), (double) strlen(s2));
	return strncmp(s1, s2, len) == 0;
}


uint8_t strtou8(char *s)
{
	char *c;
	for (c = s; *c; c++)
	{
		if (!isdigit(*c))
			return 0L;
	}

	return (uint8_t) strtoul(s, 0L, 10);
}
