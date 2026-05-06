#include "raylib.h"

#include <stdio.h>


#define WIDTH 900
#define HEIGHT 600


int main(void)
{
	InitWindow(WIDTH, HEIGHT, "sCrib");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		
		BeginDrawing();

			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
				DrawCircle(GetMouseX(), GetMouseY(), 3, RED);
			
		EndDrawing();

		SwapScreenBuffer();  // Avoid flickering 
	}

	CloseWindow();

	return 0;
}
