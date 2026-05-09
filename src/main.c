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
		.width = 900,//GetScreenWidth(),
		.height = 600,//GetScreenHeight(),
	};

	InputSettings isettings = 
	{
		.cantype = 0,
		.can_process_cmd = 0,
		.commandlen = MAX_COMMAND_LENGTH,
		.command = (char *) calloc(MAX_COMMAND_LENGTH, sizeof(char)),
		.lettercount = 0,
	};

	InitWindow(asettings.width, asettings.height, "sCrib");

	int32_t display = GetCurrentMonitor();
	asettings.width = GetMonitorWidth(display);
	asettings.height = GetMonitorHeight(display);
	SetWindowSize(asettings.width, asettings.height);
	ToggleFullscreen();

	SetTargetFPS(60);
	RenderTexture2D framebuffer = LoadRenderTexture(asettings.width, asettings.height);

	clearcanva(framebuffer, asettings.bgcolor);

	while (!WindowShouldClose())
	{
		handle_input(&isettings);
		handle_command(&isettings, &asettings);

		uint8_t should_draw_point = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			should_draw_point = 0;
			lastpos = (Vector2) {-1, -1};
		}

		BeginTextureMode(framebuffer);

			if (should_draw_point)
			{
				Vector2 currpos = GetMousePosition();
				DrawCircleV(currpos, asettings.thickness / 2, asettings.fgcolor);

				if (lastpos.x != -1 && lastpos.y != -1)
					DrawLineEx(lastpos, currpos, asettings.thickness, asettings.fgcolor);

				lastpos = currpos;
			}
			
		EndTextureMode();

		Rectangle framebufferrect = {0, 0, (float) framebuffer.texture.width, (float) -framebuffer.texture.height};

		BeginDrawing();

			DrawTextureRec(framebuffer.texture, framebufferrect, vec2ZERO, WHITE);

			if (isettings.lettercount > 0)
				DrawText(TextFormat(":%s", isettings.command), 5, asettings.height - 24, 24, WHITE);
			
		EndDrawing();

	}

	UnloadRenderTexture(framebuffer);
	CloseWindow();
	free(isettings.command);

	return 0;
}
