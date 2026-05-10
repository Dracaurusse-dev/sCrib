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

typedef enum
{
	SHAPE_CIRCLE,
	SHAPE_TRIANGLE,
	SHAPE_SQUARE,
} Shape;

typedef struct
{
	Color fgcolor;
	Color bgcolor;
	int32_t thickness;
	int32_t width, height;
	float rotation;
	Brush brush;
	Shape shape;
	uint8_t should_clear;
	uint8_t should_show_help;
	uint8_t should_exit;
} AppSettings;


void clearcanva(RenderTexture2D *framebuffer, Color color);
void inithelpbuf(RenderTexture2D *helpbuffer);
void paint(RenderTexture2D *framebuffer, Vector2 *lastpos, AppSettings asettings);
void drawdotshape(int32_t thickness, Color color, Shape shape, Vector2 pos, float rot);

void change_color(Color *color, char *colorstr);
void change_thickness(AppSettings *asettings, char *thickstr);
void change_shape(AppSettings *asettings, char *shape);
void change_rotation(AppSettings *asettings, char *rotstr);


#endif  // PAINT_H
