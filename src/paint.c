#include "paint.h"
#include "stringutils.h"

#include "raylib.h"

#include <stdio.h>


void clearcanva(RenderTexture2D framebuffer, Color color)
{
	BeginTextureMode(framebuffer);
		ClearBackground(color);
	EndTextureMode();
}


void change_fgcolor(Color *color, char *colorstr)
{
	if (color == NULL || colorstr == NULL)
		return;

	if (startswith(colorstr, "red") || startswith(colorstr, "r"))
		*color = RED;
	else if (startswith(colorstr, "white") || startswith(colorstr, "w"))
		*color = WHITE;
	else if (startswith(colorstr, "blue") || startswith(colorstr, "b"))
		*color = BLUE;
	else if (startswith(colorstr, "yellow") || startswith(colorstr, "y"))
		*color = YELLOW;
	else if (startswith(colorstr, "pink") || startswith(colorstr, "p"))
		*color = PINK;
	else if (startswith(colorstr, "green") || startswith(colorstr, "g"))
		*color = GREEN;
	else
		fprintf(stderr, "Unknown color: %s\n", colorstr);
}

