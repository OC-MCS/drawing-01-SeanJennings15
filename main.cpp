//================================================
// Sean Jnennings
// Programming 2
// Assignment 6: Drawing
// 3-29-19
//================================================
#include <iostream>
#include <fstream>
using namespace std;
#include <SFML\Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
#include "SettingsUI.h"
#include "DrawingUI.h"
using namespace sf;

// Finish this code. Other than where it has comments telling you to 
// add code, you shouldn't need to add any logic to main to satisfy
// the requirements of this programming assignment

int main()
{
	const int WINDOW_WIDTH = 800;		//user drawing window width
	const int WINDOW_HEIGHT = 600;		//user drawing window height

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing");  //creating a window variable to draw in
	window.setFramerateLimit(60);

	SettingsMgr settingsMgr(Color::Blue, ShapeEnum::CIRCLE); //variable for remembering current shape and color
	SettingsUI  settingsUI(&settingsMgr);					//variable for managing changing the shape and color settings
	ShapeMgr    shapeMgr;									//variable for managing the shapes actually being drawn
	DrawingUI   drawingUI(Vector2f(250, 25));				//variable that handles drawing the shapes
	
	// ********* Add code here to make the managers read from shapes file (if the file exists)
	fstream file;											//creating a file variable
	file.open("shapesFile.dat", ios::in | ios::binary);		//opening file for input

	if (file)
	{
		settingsMgr.readFile(file);
		shapeMgr.readFile(file);
		file.close();										//closes file after input is done
	}

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				// ****** Add code here to write all data to shapes file
				file.open("shapesFile.dat", ios::out | ios::binary);	//opening file for output
				
				settingsMgr.saveFile(file);
				shapeMgr.saveFile(file);
				file.close();											//closes file after output is done
			
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				// maybe they just clicked on one of the settings "buttons"
				// check for this and handle it.
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));	//position of mouse
				settingsUI.handleMouseUp(mousePos);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left))
			{
				
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));	//position of mouse
				// check to see if mouse is in the drawing area
				if (drawingUI.isMouseInCanvas(mousePos))
				{
					// add a shape to the list based on current settings
					shapeMgr.addShape(mousePos, settingsMgr.getCurShape(), settingsMgr.getCurColor());
				}
			}
		}

		// The remainder of the body of the loop draws one frame of the animation
		window.clear();

		// this should draw the left hand side of the window (all of the settings info)
		settingsUI.draw(window);

		// this should draw the rectangle that encloses the drawing area, then draw the
		// shapes. This is passed the shapeMgr so that the drawingUI can get the shapes
		// in order to draw them. This redraws *all* of the shapes every frame.
		drawingUI.draw(window, &shapeMgr);

		window.display();
	} // end body of animation loop

	return 0;
}