#if defined(_WIN32) && !defined(_DEBUG)
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include "AppleCatcher.h"
#include <iostream>

using namespace std;



int main() {
	Window game_window;
	fps(60);
start_again:
	score = 0;
	Bowl main_bowl((800 / 2) - (100 / 2), 600 - 20);
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
		if (apples.call_draw_and_fall()) goto start_again;
		
		//Collisions
		apples.check_colisions(main_bowl);
		show_score();
		EndDrawing();
	}
	return 0;
}