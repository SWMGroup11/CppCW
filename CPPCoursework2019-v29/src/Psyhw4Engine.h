#pragma once
#include "BaseEngine.h"
#include "TileManager.h"
class Man;
class Man1;
class Man2;
class Psyhw4Engine :
	public BaseEngine
{
public:
	TileManager obTileManager;
	Man2* m_pBall2;
	Man1* m_pBall1;
	Psyhw4Engine() : obTileManager(25, 25), m_pBall1(NULL), m_pBall2(NULL) {};
	~Psyhw4Engine();
	void virtSetupBackgroundBuffer();

	int virtInitialiseObjects();

	void virtDrawStringsUnderneath();

	void virtMouseDown(int iButton, int iX, int iY);

	void virtKeyDown(int iKeyCode);

	
};

