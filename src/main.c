#include "raylib.h"

#include <stdio.h>
#include <stdint.h>


#define WIDTH 900
#define HEIGHT 600


int main(void)
{
	Vector2 nullvec2 = {0, 0};

	InitWindow(WIDTH, HEIGHT, "sCrib");

	SetTargetFPS(60);
	RenderTexture2D framebuffer = LoadRenderTexture(WIDTH, HEIGHT);

	while (!WindowShouldClose())
	{
		uint8_t should_draw_point = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
		BeginTextureMode(framebuffer);

			if (should_draw_point)
				DrawCircle(GetMouseX(), GetMouseY(), 3, RED);
			
		EndTextureMode();

		Rectangle framebufferrect = {0, 0, (float) framebuffer.texture.width, (float) -framebuffer.texture.height};

		BeginDrawing();

			DrawTextureRec(framebuffer.texture, framebufferrect , nullvec2, WHITE);
			
		EndDrawing();

	}

	CloseWindow();

	return 0;
}
