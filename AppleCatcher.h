#pragma once
#include "raylib.h"
#include <random>
#include <string>
#include <vector>

int score = 0;

inline void show_score() {
	std::string score_str = ("Score: " + std::to_string(score));
	DrawText(score_str.c_str(), 700, 50, 12, WHITE);
}

inline void define_window(int x, int y) {
	InitWindow(x, y, "AppleCatcher");
}

inline void fps(int fps) {
	SetTargetFPS(fps);
}

class Window {   //Game window class
private:
	float width = 800.0f;
	float height = 600.0f;
public:
	Window() {
		define_window(this->width, this->height);
	}
	Window(float width, float height) {
		this->width = width;
		this->height = height;
		define_window(this->width, this->height);
	}

};



class Apple {
private:
	Color color = RED;
public:
	float radius = 8.0f;
	float x = 0;
	float y = 0;
	Apple(float x, float y) {
		this->x = x;
		this->y = y;
	}
	inline void draw() {
		DrawCircle(this->x, this->y, this->radius, color);
	}
	inline void gravity() {
		this->y += 2;
	}
};

class Bowl {
public:
	float x = 0.0f;
	float y = 0.0f;
	float width = 100.0f;
	float height = 20.0f;
	float speed = 8.0f;
	const Color color = WHITE;
	Bowl(float x, float y) {
		this->x = x;
		this->y = y;
	}
	inline void updatex(float x) {
		this->x = x;
	}
	inline void updatey(float y) { 
		this->y = y;
	}
	inline void updatecoord(float x, float y) {
		this->x = x;
		this->y = y;
	}
	inline void draw() {
		DrawRectangle(this->x, this->y, this->width, this->height, color);
	}

	inline void move_right() {
		if (this->x < (800-this->width))
		this->x += speed;
	}

	inline void move_left() {
		if (this->x > 0)
		this->x -= speed;
	}

};


class AppleThrower {
private:
	std::mt19937 gen{ std::random_device{}() };             //Uses random: Creates generator
	std::uniform_int_distribution<int> rand_x{ 8, 792 };    //Then distribution
	int clock = 59;
	int array = 0;
	std::vector<Apple> list;
	
public:
	inline bool call_draw_and_fall() {                      //Checks if you lose (ball goes out of bounds
		for (int i = list.size() - 1; i >= 0; --i) {		//Loop needs to start from top because of erase to avoid problems
			if (list[i].y >= 610) {							
				list.erase(list.begin() + i);				
				return true;								//true = lose
			}
			else {
				list[i].gravity();
				list[i].draw();
			}
		}
		return false;										//May continue
	}
	inline void run_clock() {								//Uses current fps to count time PROBLEM: time is fps based so cout result in weird stuff
		this->clock += 1;
	}
	inline int show_clock() {					
		return this->clock;
	}
	inline void make_apples() {
		if (this->clock == 60) { //Every 60 frames = 1 sec
			list.emplace_back(rand_x(gen), 0);
			this->clock = 0;
		}
	}
	inline void check_colisions(const Bowl& bowl) {
		for (int i = list.size() - 1; i >= 0; --i) {
			if (CheckCollisionCircleLine({ list[i].x, list[i].y }, list[i].radius, { bowl.x, 600 - bowl.height }, { bowl.x + bowl.width, 600 - bowl.height })) {   //Checks colision with the upper layer of the Bowl
				list.erase(list.begin() + i);
				score += 1;
			}
			
		}
	}
};