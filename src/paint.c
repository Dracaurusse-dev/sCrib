#include "paint.h"
#include "stringutils.h"

#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>


void clearcanva(RenderTexture2D *framebuffer, Color color)
{
	BeginTextureMode(*framebuffer);
		ClearBackground(color);
	EndTextureMode();
}


void inithelpbuf(RenderTexture2D *helpbuffer)
{
	clearcanva(helpbuffer, BLACK);

	BeginTextureMode(*helpbuffer);

		DrawText("Exit this help by pressing q", 10, 10, 24, WHITE);
		DrawText("Here's the manual:\nPress ':' (, on qwerty) to start a command.\nCommands are:\nq to quit\np to use the pen\ne to use the eraser\nc color to change pen color\nb color to wipe the background to color\ns shape (circle, square or triangle) to change brush shape\nh to show this help\nt thick to change brushe's thickness to thick\nr rot to change rotation of some shapes", 50, 50, 24, WHITE);

	EndTextureMode();
}


void drawdotshape(int32_t thickness, Color color, Shape shape, Vector2 lastpos, float rot)
{
	switch (shape)
	{
		case SHAPE_CIRCLE:
			DrawCircleV(lastpos, thickness, color);
			break;
		case SHAPE_SQUARE:
			DrawPoly(lastpos, 4, thickness, rot, color);
			break;
		case SHAPE_TRIANGLE:
			DrawPoly(lastpos, 3, thickness, rot, color);
			break;

		default:
			DrawCircleV(lastpos, thickness, color);
			break;
	}
}


void paint(RenderTexture2D *framebuffer, Vector2 *lastpos, AppSettings asettings)
{
	Color color = asettings.brush == BRUSH_PEN ? asettings.fgcolor : asettings.bgcolor;
	Vector2 currpos = GetMousePosition();

	BeginTextureMode(*framebuffer);
		drawdotshape(asettings.thickness / 2, color, asettings.shape, currpos, asettings.rotation);

		if (lastpos->x != -1 && lastpos->y != -1)
			DrawLineEx(*lastpos, currpos, asettings.thickness, color);

		*lastpos = currpos;
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


void change_shape(AppSettings *asettings, char *shape)
{
	if (startswith(shape, "square"))
		asettings->shape = SHAPE_SQUARE;
	else if (startswith(shape, "circle"))
		asettings->shape = SHAPE_CIRCLE;
	else if (startswith(shape, "triangle"))
		asettings->shape = SHAPE_TRIANGLE;
	else
		asettings->shape = SHAPE_CIRCLE;
}


void change_rotation(AppSettings *asettings, char *rotstr)
{
	float rot = strtof(rotstr, NULL);
	asettings->rotation = rot;
}
