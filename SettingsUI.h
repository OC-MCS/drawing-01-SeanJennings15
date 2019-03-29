#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

class SettingsUI
{
private:
	const int CIRCLE_RADIUS = 20;	//radius for the circle button and circle color buttons
	CircleShape blueBtn;	//blue menu button
	CircleShape redBtn;		//red menu button
	CircleShape greenBtn;	//green menu button
	CircleShape circleBtn;	//menu button for circle drawing shape
	RectangleShape squareBtn; //menu button for square drawing shape
	SettingsMgr *UImgr;		//ends up pointing to the SettingMgr in order to change the settings

public:

//======================================================
// SettingUI(SettingMgr *mgr): constructor for a SettingsUI, passed a pointer to SettingsMgr in order to control the settings
// parameters: ptr to the SettingsMgr
// return type: none
//======================================================
	SettingsUI(SettingsMgr *mgr)
	{
		UImgr = mgr;
	}

//======================================================
// handleMouseUp(Vector2f mouse): handle clicking the menu buttons
// parameters: the mouses position in order to see where it is over the menu buttons
// return type: void
//======================================================
	void handleMouseUp(Vector2f mouse)
	{
		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			UImgr->setCurColor(Color::Blue);
		}
		else if (redBtn.getGlobalBounds().contains(mouse))
		{
			UImgr->setCurColor(Color::Red);
		}
		else if (greenBtn.getGlobalBounds().contains(mouse))
		{
			UImgr->setCurColor(Color::Green);
		}
		if (squareBtn.getGlobalBounds().contains(mouse))
		{
			UImgr->setCurShape(SQUARE);
		}
		else if (circleBtn.getGlobalBounds().contains(mouse))
		{
			UImgr->setCurShape(CIRCLE);
		}
	}

//======================================================
// draw(RenderWindow& win): this is the function that actually draws the menu and turns buttons on and off
// parameters: the window that everything is being drawn in
// return type: void
//======================================================
	void draw(RenderWindow& win)
	{
		Font font; //variable to hole the font we are writing in
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");
		
		Text colorTitle("Selected Color", font, 25); //menu text
		colorTitle.setPosition(30, 25);
		win.draw(colorTitle);

		Text shapeTitle("Selected Shape", font, 25); //menu text
		shapeTitle.setPosition(30, 300);
		win.draw(shapeTitle);
		
		Vector2f blueBtnPos(35, 75);
		blueBtn.setPosition(blueBtnPos);
		blueBtn.setRadius(CIRCLE_RADIUS);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		win.draw(blueBtn);

		Vector2f redBtnPos(35, 125);
		redBtn.setPosition(redBtnPos);
		redBtn.setRadius(CIRCLE_RADIUS);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		win.draw(redBtn);

		Vector2f greenBtnPos(35, 175);
		greenBtn.setPosition(greenBtnPos);
		greenBtn.setRadius(CIRCLE_RADIUS);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		win.draw(greenBtn);

		Vector2f circleBtnPos(35, 350);
		circleBtn.setPosition(circleBtnPos);
		circleBtn.setRadius(CIRCLE_RADIUS);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		win.draw(circleBtn);

		Vector2f squareBtnPos(35, 420);
		squareBtn.setSize(Vector2f(40, 40));
		squareBtn.setPosition(squareBtnPos);
		squareBtn.setOutlineThickness(2);
		squareBtn.setOutlineColor(Color::White);
		win.draw(squareBtn);

		if (UImgr->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (UImgr->getCurColor() == Color::Red)
		{
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Red);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (UImgr->getCurColor() == Color::Green)
		{
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Green);
		}

		if (UImgr->getCurShape() == SQUARE)
		{
			circleBtn.setFillColor(Color::Transparent);
			squareBtn.setFillColor(Color::White);
		}
		else if (UImgr->getCurShape() == CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
			squareBtn.setFillColor(Color::Transparent);
		}
	}
};
