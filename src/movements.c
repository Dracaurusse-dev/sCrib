#include "movements.h"
#include "paint.h"
#include "stringutils.h"

#include "raylib.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


void handle_input(InputSettings *isettings)
{
	int32_t key = GetCharPressed();

	if (IsKeyPressed(KEY_PERIOD) && !isettings->cantype)
	{
		isettings->cantype = 1;
		return;
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		isettings->cantype = 0;
		isettings->lettercount = 0;
		isettings->is_command_ready = 1;
		return;
	}

	if (IsKeyPressed(KEY_BACKSPACE) && isettings->cantype)
	{
		if (isettings->lettercount != 0)
			(isettings->lettercount)--;

		isettings->command[isettings->lettercount] = 0;
	}

	while (key > 0 && isettings->cantype)
	{
		if ((key >= 32) && (key <= 125) && (isettings->lettercount < isettings->commandlen - 1))
		{
			isettings->command[isettings->lettercount++] = (char) key;
			isettings->command[isettings->lettercount] = 0;
		}

		key = GetCharPressed();
	}

}


void handle_command(InputSettings *isettings, AppSettings *asettings)
{
	if (!isettings->is_command_ready)
		return;
	isettings->is_command_ready = 0;

	char **cmd = getcmd(isettings->command, isettings->commandlen);
	switch (cmd[0][0])
	{
		case 'c':
			change_color(&asettings->fgcolor, cmd[1]);
			break;
		case 'b':
			change_color(&asettings->bgcolor, cmd[1]);
			asettings->should_clear = 1;
			break;

		default:
			break;
	}

	free(cmd);  // TODO: check if it actually frees allocated memory { char*; char* ...};
}
