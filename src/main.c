#include "paint.h"
#include "movements.h"
#include "stringutils.h"

#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


#define MAX_COMMAND_LENGTH 32


int main(void)
{
	Vector2 vec2ZERO = {0, 0};
	Vector2 lastpos = {-1, -1};

	AppSettings asettings = 
	{
		.fgcolor = WHITE,
		.bgcolor = BLACK,
		.thickness = 3,
		.width = 900,
		.height = 600,
		.should_clear = 0,
		.brush = BRUSH_PEN,
		.should_exit = 0,
		.should_show_help = 0,
	};

	InputSettings isettings = 
	{
		.cantype = 0,
		.can_process_cmd = 0,
		.commandlen = MAX_COMMAND_LENGTH,
		.command = (char *) calloc(MAX_COMMAND_LENGTH, sizeof(char)),
		.lettercount = 0,
		.is_command_ready = 0,
	};


	InitWindow(asettings.width, asettings.height, "sCrib");

	int32_t display = GetCurrentMonitor();
	asettings.width = GetMonitorWidth(display);
	asettings.height = GetMonitorHeight(display);
	SetWindowSize(asettings.width, asettings.height);
	ToggleFullscreen();

	SetTargetFPS(60);
	RenderTexture2D framebuffer = LoadRenderTexture(asettings.width, asettings.height);
	RenderTexture2D helpbuffer  = LoadRenderTexture(asettings.width, asettings.height);

	clearcanva(&framebuffer, asettings.bgcolor);
	inithelpbuf(&helpbuffer);

	while (!WindowShouldClose() && !asettings.should_exit)
	{
		handle_input(&isettings);
		handle_command(&isettings, &asettings);

		uint8_t should_draw_point = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			should_draw_point = 0;
			lastpos = (Vector2) {-1, -1};
		}

		if (asettings.should_clear)
		{
			clearcanva(&framebuffer, asettings.bgcolor);
			asettings.should_clear = 0;
		}

		if (should_draw_point)
			paint(&framebuffer, &lastpos, asettings);

		Texture2D drawntexture = asettings.should_show_help ? helpbuffer.texture : framebuffer.texture;
		Rectangle bufferrect = {0, 0, (float) drawntexture.width, (float) -drawntexture.height};

		BeginDrawing();


			DrawTextureRec(drawntexture, bufferrect, vec2ZERO, WHITE);
			if (isettings.cantype)
				DrawText(TextFormat(":%s", isettings.command), 10, asettings.height - 24, 24, WHITE);
			
		EndDrawing();

	}

	UnloadRenderTexture(framebuffer);
	CloseWindow();
	free(isettings.command);

	return 0;
}
