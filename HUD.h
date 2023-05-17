#pragma once
#include "GraphicsSystem.h"
#include "Font.h"
#include "Color.h"
#include <string>
using namespace std;

//HUD � displays score, total time elapsed, and FPS counter
class HUD
{
public:
	HUD(GraphicsSystem& graphicsSystem);
	~HUD();
	void startScreen();
	void pauseScreen();
	void gameOver();
	void score(int score);
	void fps(float fps);
	void timer(int timer);
private:
	GraphicsSystem* mGraphicsSystem;
	const string ASSET_PATH = "..\\..\\shared\\assets\\";
	const string FONT_FILENAME = "cour.ttf";
	const int FONT_SIZE = 50;
	const int DISP_WIDTH = 800;
	const int DISP_HEIGHT = 600;
	Color mWhite = Color(255, 255, 255);
	Font* mpFont = new Font(ASSET_PATH + FONT_FILENAME, FONT_SIZE);
};