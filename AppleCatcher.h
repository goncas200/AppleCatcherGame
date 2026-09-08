#pragma once
#include "raylib.h"

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