#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr
{
private:
	ShapeEnum currentShape;	//current selected shape from the menu
	Color currentColor;		//current selected color from the menu
public:

//======================================================
// SettingsMgr(Color startingColor, ShapeEnum startingShape): constructor for a SettingsMgr that requires the current selected shape and color
// parameters: selected shape and color
// return type: none
//======================================================
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		currentShape = startingShape;
		currentColor = startingColor;
	}

//======================================================
// getCurColor(): returns the shapes current color
// parameters: none
// return type: Color
//======================================================
	Color getCurColor()
	{
		return currentColor;
	}

//======================================================
// getCurShape(): returns the which current shape is selected
// parameters: none
// return type: ShapeEnum
//======================================================
	ShapeEnum getCurShape()
	{
		return currentShape;
	}

//======================================================
// setCurShape(): sets the current shape to the inputted shape
// parameters: the selected shape
// return type: void
//======================================================
	void setCurShape(ShapeEnum inputShape)
	{
		currentShape = inputShape;
	}

//======================================================
// setCurColor(): sets the current color to the inputted color
// parameters: the selected color
// return type: void
//======================================================
	void setCurColor(Color inputColor)
	{
		 currentColor = inputColor;
	}

//======================================================
// readFile(fstream &file): reads the settings from the file
// parameters: file stream
// return type: void
//======================================================
	void readFile(fstream &file)
	{
		unsigned int colorNumber; //variable to hold int version of the color
		file.read(reinterpret_cast<char*>(&colorNumber), sizeof(colorNumber));
		file.read(reinterpret_cast<char*>(&currentShape), sizeof(currentShape));
		Color aColor(colorNumber);
		currentColor = aColor;
	}

//======================================================
// saveFile(fstream &file): outputs the settings to the file
// parameters: file stream
// return type: void
//======================================================
	void saveFile(fstream &file)
	{
		unsigned int colorNumber = currentColor.toInteger(); //variable to hold the int version of the number
		file.write(reinterpret_cast<char*>(&colorNumber), sizeof(colorNumber));
		file.write(reinterpret_cast<char*>(&currentShape), sizeof(currentShape));
	}
};

//======================================================
// die(string errorMsg): error message for if the font does not load for the SettingsUI
// parameters: the error message that will be outputted
// return type: string
//======================================================
string die(string errorMsg)
{
	cout << errorMsg << endl;
	exit(-1);
}
