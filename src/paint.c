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

	if (startswith(colorstr, "red"))
		*color = RED;
	else if (startswith(colorstr, "white"))
		*color = WHITE;
	else
		fprintf(stderr, "Unknown color: %s\n", colorstr);
}
