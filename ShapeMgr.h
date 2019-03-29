#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"
using namespace std;
using namespace sf;

// finish the ShapeMgr class.
class ShapeMgr
{
private:
	vector<DrawingShape*> shapesDrawn;	//vector for holding all the shapes that get drawn to the screen

public:
//======================================================
// ShapeMgr(): empty default constructor
// parameters: none
// return type: none
//======================================================
	ShapeMgr()
	{
	}

//======================================================
// addShape((Vector2f pos, ShapeEnum whichShape, Color color): adds the shape to the shapesDrawn array according to which type of shape it is
// parameters: the shapes: position, type of shape, and color
// return type: void
//======================================================
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			Circle* newCircle;		//creates a pointer to a Circle in order to have a struct to push to the vector each time a shape is drawn
			newCircle = new Circle(color, pos);
			shapesDrawn.push_back(newCircle);
		}
		else if (whichShape == SQUARE)
		{
			Square* newSquare;		//creates a pointer to a Square in order to have a struct to push to the vector each time a shape is drawn
			newSquare = new Square(color, pos);
			shapesDrawn.push_back(newSquare);
		}
	}

//======================================================
// getVector(): returns a pointer to the array containing all the drawn shapes
// parameters: none
// return type: vector<DrawingShape*>
//======================================================
	vector<DrawingShape*> getVector()
	{
		return shapesDrawn;
	}

//======================================================
// saveFile(fstream& file): saves the contents of the shapesDrawn vector to the file
// parameters: the stream to the storage file
// return type: void
//======================================================
	void saveFile(fstream& file)
	{
		tempInfo tempVector;	//temporary vector that is written to the file
		for (int i = 0; i < shapesDrawn.size(); i++)
		{
			tempVector = shapesDrawn[i]->getShapeInfo();
			file.write(reinterpret_cast<char*>(&tempVector), sizeof(tempVector));
		}
	}
//======================================================
// readFile(fstream& file): reads the contents of the file to the shapesDrawn vector
// parameters: the stream to the storage file
// return type: void
//======================================================
	void readFile(fstream& file)
	{
		tempInfo tempVector;	//temporary vector that is read from the file
		while (file.read(reinterpret_cast<char*>(&tempVector), sizeof(tempVector)))
		{
			addShape(tempVector.pos, tempVector.shape, Color(tempVector.color));
		}
	}
};
