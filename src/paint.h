#ifndef PAINT_H
#define PAINT_H


#include "raylib.h"

#include "paint.h"

#include <stddef.h>
#include <stdint.h>


typedef enum
{
	BRUSH_PEN,
	BRUSH_ERASER,
} Brush;

typedef struct
{
	Color fgcolor;
	Color bgcolor;
	int32_t thickness;
	int32_t width, height;
	Brush brush;
	uint8_t should_clear;
	uint8_t should_exit;
} AppSettings;


void clearcanva(RenderTexture2D framebuffer, Color color);
void paint(RenderTexture2D framebuffer, Vector2 *lastpos, AppSettings asettings);

void change_color(Color *color, char *colorstr);
void change_thickness(AppSettings *asettings, char *thickstr);


#endif  // PAINT_H
