#pragma once
#include "raylib.h"
#include <random>
#include <vector>

inline void define_window(int x, int y) {
	InitWindow(x, y, "AppleCatcher");
}

inline void fps(int fps) {
	SetTargetFPS(fps);
}

class Window {
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
	float radius = 8.0f;
public:
	float x = 0;
	float y = 0;
	Apple(float x, float y) {
		this->x = x;
		this->y = y;
	}
	inline void draw() {
		DrawCircle(this->x, this->y, this->radius, WHITE);
	}
	inline void gravity() {
		this->y += 2;
	}
};

class Bowl {
private:
	float x = 0.0f;
	float y = 0.0f;
	float width = 100.0f;
	float height = 20.0f;
	float speed = 8.0f;
	Color color = WHITE;
public:
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
	int clock = 0;
	int array = 0;
	std::vector<Apple> list;
	
public:
	inline void call_draw_and_fall() { // Run after make_apples
		for (int i = list.size() - 1; i >= 0; --i) {
			if (list[i].y >= 610) {
				list.erase(list.begin() + i);
			}
			else {
				list[i].gravity();
				list[i].draw();
			}
		}
	}
	inline void run_clock() {
		this->clock += 1;
	}
	inline int show_clock() {
		return this->clock;
	}
	inline void make_apples() {
		if (this->clock == 60) { //Every 60 frames = 1 sec
			list.emplace_back(rand() % 801, 0);
			this->clock = 0;
		}
	}
};