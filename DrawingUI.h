#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

class DrawingUI
{
private:
		RectangleShape drawingArea;		//this is the drawing canvas
		const int canvasLength = 500;	//length for each side of the square canvas
		const int canvasX = 250;	//X value of the canvas
		const int canvasY = 25;		//Y value of the canvas
		const int drawingCanvasX = canvasX - 8 + canvasLength; //max X value that can be drawn on in the canvas
		const int drawingCanvasY = canvasY - 8 + canvasLength; //max Y value that can be drawn on in the canvas

public:

//======================================================
// DrawingUI(Vector2f p): this is the constructor for DrawingUI, only draws the canvas
// parameters: coordinates for the canvas position
// return type: none
//======================================================
	DrawingUI(Vector2f p)
	{
		drawingArea.setSize(Vector2f(canvasLength, canvasLength));
		drawingArea.setPosition(p);
		drawingArea.setOutlineThickness(2);
		drawingArea.setOutlineColor(Color::White);
		drawingArea.setFillColor(Color::White);
	}

//======================================================
// draw(RenderWindow& win, ShapeMgr *mgr): draws each shape to the screen from the vector
// parameters: the window for drawing in and the ptr to a ShapeMgr in order to acces the drawing vector
// return type: void
//======================================================
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		win.draw(drawingArea);

		for (int i = 0; i < mgr->getVector().size(); i++)
		{
			mgr->getVector()[i]->drawShape(win);
		}
	}
	
//======================================================
// isMouseInCanvas(Vector2f mousePos): checks to see if the mouse is in the drawing canvas
// parameters: the mouses position
// return type: bool; true if mouse is in the canvas else false
//======================================================
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool isInCanvas;
		if (drawingArea.getGlobalBounds().contains(mousePos) && mousePos.x < (drawingCanvasX) && mousePos.y < (drawingCanvasY))
			isInCanvas = true;
		else
			isInCanvas = false;
			
		return isInCanvas;
	}
};