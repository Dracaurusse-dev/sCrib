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


void change_color(Color *color, char *colorstr)
{
	if (color == NULL || colorstr == NULL)
		return;

	if (startswith(colorstr, "red") || startswith(colorstr, "r"))
		*color = RED;
	else if (startswith(colorstr, "white") || startswith(colorstr, "w"))
		*color = WHITE;
	else if (startswith(colorstr, "blue") || startswith(colorstr, "B"))
		*color = BLUE;
	else if (startswith(colorstr, "yellow") || startswith(colorstr, "y"))
		*color = YELLOW;
	else if (startswith(colorstr, "pink") || startswith(colorstr, "p"))
		*color = PINK;
	else if (startswith(colorstr, "green") || startswith(colorstr, "g"))
		*color = GREEN;
	else if (startswith(colorstr, "black") || startswith(colorstr, "b"))
		*color = BLACK;
	else
		fprintf(stderr, "Unknown color: %s\n", colorstr);
}


void change_thickness(AppSettings *asettings, char *thickstr)
{
	uint8_t thick = strtou8(thickstr);
	if (thick == 0)
		return;
	asettings->thickness = thick;
}
