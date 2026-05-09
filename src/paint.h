#ifndef PAINT_H
#define PAINT_H


#include "raylib.h"

#include <stddef.h>
#include <stdint.h>


typedef struct
{
	Color fgcolor;
	Color bgcolor;
	int32_t thickness;
} AppSettings;

void clearcanva(RenderTexture2D framebuffer, Color color);

void change_fgcolor(Color *color, char *colorstr);


#endif  // PAINT_H
