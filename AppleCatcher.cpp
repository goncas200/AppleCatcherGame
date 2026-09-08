#include "AppleCatcher.h"
using namespace std;


int main() {
	Window game_window;
	fps(60);
	Bowl main_bowl((800 / 2)-(100/2), 600 - 20);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		if (IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)) {
			main_bowl.move_right();
		}
		if (IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)) {
			main_bowl.move_left();
		}
		main_bowl.draw();


		EndDrawing();
	}
	return 0;
}