#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

struct tempInfo	//structure for returning temporary info from the shapesDrawn for file input and output
{
	ShapeEnum shape;	//holds the type of shape
	int color;			//holds the shapes color
	Vector2f pos;		//holds the shapes position
};

class DrawingShape //abstract base class for Circle and Square
{
public:
	virtual tempInfo getShapeInfo() = 0;	//pure virtual function getting the shapes info: type, color, and position
	virtual void drawShape(RenderWindow& win) = 0;	//pure virtual function drawing each shape
	
};

class Circle : public DrawingShape
{
private:
	CircleShape circle;	//creates an instance of a circle from the graphics library
	Color drawColor;	//stores the drawing shapes color
	Vector2f drawPos;	//stores the drawing shapes position

public:
//======================================================
// Circle(Color inputColor, Vector2f pos): constructor for a circle
// parameters: requires the circles color and position
// return type: none
//======================================================
	Circle(Color inputColor, Vector2f pos)
	{
		circle.setFillColor(inputColor);
		circle.setOutlineColor(inputColor);
		circle.setPosition(pos);
		circle.setRadius(5);
		circle.setOutlineThickness(1);	
	}

//======================================================
// setCurPos(Vector2f inputPos): setter for the circles position
// parameters: requires the position to draw at
// return type: void
//======================================================
	void setCurPos(Vector2f inputPos)
	{
		drawPos = inputPos;
	}

//======================================================
// setCurCol(Color inputColor): setter for the circles color
// parameters: requires the color selected
// return type: void
//======================================================
	void setCurCol(Color inputColor)
	{
		drawColor = inputColor;
	}

//======================================================
// drawShape(RenderWindow& win): function to actually draw the given Circle
// parameters: the variable for the window that is being drawn in
// return type: void
//======================================================
	void drawShape(RenderWindow& win)
	{
		win.draw(circle);
	}

//======================================================
// getShapeInfo(): function for returning a temporary copy of the shapes info in order to read/write to a file
// parameters: none
// return type: tempInfo
//======================================================
	tempInfo getShapeInfo()
	{
		tempInfo output;
		output.shape = CIRCLE;
		output.color = circle.getFillColor().toInteger();
		output.pos = circle.getPosition();

		return output;
	}
};

class Square : public DrawingShape
{
private:
	RectangleShape square;	//creates an instance of a circle from the graphics library
	Color drawColor;		//stores the drawing shapes color
	Vector2f drawPos;		//stores the drawing shapes position

public:

//======================================================
// Square(Color inputColor, Vector2f pos): constructor for a square
// parameters: requires the squares color and position
// return type: none
//======================================================
	Square(Color inputColor, Vector2f pos)
	{
		square.setFillColor(inputColor);
		square.setOutlineColor(inputColor);
		square.setPosition(pos);
		square.setSize(Vector2f(15, 15));
		square.setOutlineThickness(2);
	}

//======================================================
// setCurPos(Vector2f inputPos): setter for the squares position
// parameters: requires the position to draw at
// return type: void
//======================================================
	void setCurPos(Vector2f inputPos)
	{
		drawPos = inputPos;
	}

//======================================================
// setCurCol(Color inputColor): setter for the squares color
// parameters: requires the color selected
// return type: void
//======================================================
	void setCurCol(Color inputColor)
	{
		drawColor = inputColor;
	}

//======================================================
// drawShape(RenderWindow& win): function to actually draw the given Square
// parameters: the variable for the window that is being drawn in
// return type: void
//======================================================
	void drawShape(RenderWindow& win)
	{
		win.draw(square);
	}

//======================================================
// getShapeInfo(): function for returning a temporary copy of the shapes info in order to read/write to a file
// parameters: none
// return type: tempInfo
//======================================================
	tempInfo getShapeInfo()
	{
		tempInfo output;
		output.shape = SQUARE;
		output.color = square.getFillColor().toInteger();
		output.pos = square.getPosition();

		return output;
	}
};