#ifndef MOVEMENTS_H
#define MOVEMENTS_H


#include "paint.h"

#include <stdint.h>
#include <stddef.h>


typedef struct
{
	uint8_t cantype;
	uint8_t can_process_cmd;
	size_t commandlen;
	size_t lettercount;
	char *command;
} InputSettings;


void handle_input(InputSettings *isettings);
void handle_command(InputSettings *isettings, AppSettings *settings);


#endif  // MOVEMENTS_H
