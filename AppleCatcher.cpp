#include "AppleCatcher.h"
#include <iostream>
using namespace std;


int main() {
	Window game_window;
	fps(60);
	Bowl main_bowl((800 / 2)-(100/2), 600 - 20);
	AppleThrower apples;
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);

		//bowl managment

		if (IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)) {
			main_bowl.move_right();
		}
		if (IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)) {
			main_bowl.move_left();
		}
		main_bowl.draw();

		//apple managment

		apples.run_clock();
		apples.make_apples();
		apples.call_draw_and_fall();
		EndDrawing();
	}
	return 0;
}