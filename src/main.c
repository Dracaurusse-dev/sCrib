#include "raylib.h"

#include <stdio.h>
#include <stdint.h>


#define WIDTH 900
#define HEIGHT 600


int main(void)
{
	Vector2 vec2ZERO = {0, 0};
	Vector2 lastpos = {-1, -1};
	int32_t thickness = 3;

	InitWindow(WIDTH, HEIGHT, "sCrib");

	SetTargetFPS(60);
	RenderTexture2D framebuffer = LoadRenderTexture(WIDTH, HEIGHT);

	while (!WindowShouldClose())
	{
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
				DrawCircleV(currpos, thickness / 2, RED);

				if (lastpos.x != -1 && lastpos.y != -1)
					DrawLineEx(lastpos, currpos, thickness, RED);

				lastpos = currpos;
			}
			
		EndTextureMode();

		Rectangle framebufferrect = {0, 0, (float) framebuffer.texture.width, (float) -framebuffer.texture.height};

		BeginDrawing();

			DrawTextureRec(framebuffer.texture, framebufferrect , vec2ZERO, WHITE);
			
		EndDrawing();

	}

	CloseWindow();

	return 0;
}
