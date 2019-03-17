#include "header.h"

#include "BaseEngine.h"

#include "Man.h"

#include "Psyhw4Engine.h"

#include "ImageManager.h"

#include "TileManager.h"

#include "BouncingObject.h"


#include "DisplayableObject.h"

#include "ImageObject.h"
#include "DragableImageObject.h"

#include "DragableObject.h"

#include "Moveable.h"
Psyhw4Engine::~Psyhw4Engine()
{
}

void Psyhw4Engine::virtSetupBackgroundBuffer()
{
	fillBackground(0x000000);
	drawBackgroundRectangle(0,0,350,250, 0xffff00);
	drawBackgroundRectangle(450, 0, 800, 250, 0xffff00);
	drawBackgroundRectangle(450, 350, 800, 600, 0xffff00);
	drawBackgroundRectangle(0, 350, 350, 600, 0xffff00);

	// Draw some tiles using the tile manager
// Specify how many tiles wide and high
	obTileManager.setMapSize(10, 10);
	// Specify the screen x,y of top left corner
	obTileManager.setTopLeftPositionOnScreen(450, 350);
	// Tell it to draw tiles from x1,y1 to x2,y2 in tile array, to the background of this screen
	obTileManager.drawAllTiles(this, getBackgroundSurface()); // Draw to background!
}


int Psyhw4Engine::virtInitialiseObjects()
{
	// Record the fact that we are about to change the array - so it doesn't get used elsewhere without reloading it
	drawableObjectsChanged();

	// Destroy any existing objects
	destroyOldObjects(true);

	// Create a new object of type BouncingBall1
	m_pBall1 = new Man1(this,
		0/*Id*/, 1/*Type*/,
		50/*Size*/,
		1/*Colour*/,
		"Monster"/*Label*/,
		0/*XLabelOffset*/,
		0/*YLabelOffset*/,
		&obTileManager);
	m_pBall1->setMovement( getModifiedTime(), getModifiedTime()+1000, getModifiedTime(), 0, 300, 800, 300 );


	// Create another, different, type of ball
	m_pBall2 = new Man2 (this,
		0/*Id*/, 1/*Type*/,
		100/*Size*/,
		2/*Colour*/,
		"B"/*Label*/,
		-10/*XLabelOffset*/,
		-15/*YLabelOffset*/);
	m_pBall2->setPosition(100, 100);
	m_pBall2->setSpeed(1.1, 1.0);
	// Creates an array one element larger than the number of objects that you want.

	createObjectArray(3);
	// You MUST set the array entry after the last one that you create to NULL, so that the system knows when to stop.
	storeObjectInArray(0, m_pBall1);
	storeObjectInArray(1,new Moveable(this, 60, 80, false));
	storeObjectInArray(2, m_pBall2);

	// NOTE: We also need to destroy the objects, but the method at the 
	// top of this function will destroy all objects pointed at by the 
	// array elements so we can ignore that here.

	return 0;
}

void Psyhw4Engine::virtDrawStringsUnderneath()
{
	drawForegroundString(150, 10, "What the Fuck", 0xf00310, getFont("Cornerstone Regular.ttf", 48));
}


// Override to add a node at specified point
void Psyhw4Engine::virtMouseDown(int iButton, int iX, int iY)
{
	m_pBall1->setPosition(iX, iY);
}

/*
Handle any key presses here.
Note that the objects themselves (e.g. player) may also check whether a key is pressed
*/
void Psyhw4Engine::virtKeyDown(int iKeyCode)
{
	switch (iKeyCode)
	{
	case SDLK_ESCAPE: // End program when escape is pressed
		setExitWithCode(0);
		break;
	case SDLK_SPACE: // SPACE Pauses
		break;
	}
}