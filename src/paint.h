#ifndef PAINT_H
#define PAINT_H


#include "raylib.h"

#include "paint.h"

#include <stddef.h>
#include <stdint.h>


typedef struct
{
	Color fgcolor;
	Color bgcolor;
	int32_t thickness;
	int32_t width, height;
	uint8_t should_clear;
} AppSettings;

void clearcanva(RenderTexture2D framebuffer, Color color);

void change_color(Color *color, char *colorstr);


#endif  // PAINT_H
