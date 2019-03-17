#pragma once
#include "DisplayableObject.h"
#include "Psyhw4Engine.h"
#include "MovementPosition.h"
class BaseEngine;
class Man :
	public DisplayableObject
{
public:
	virtual ~Man();
	Man(Psyhw4Engine* pEngine, int iID,
		int iDrawType, int iSize, int iColour,
		const char* szLabel, int iXLabelOffset, int iYLabelOffset);

	void virtDraw() override;

	void virtDoUpdate(int iCurrentTime) override;

private:
	/** Pointer to the main engine object */
	Psyhw4Engine* m_pEngine;

	// Unique id for object, passed to engine to identify it
	int m_iID;

	// Type of thing to draw
	int m_iDrawType;

	// Size of thing to draw
	int m_iSize;

	// Colour index to draw with
	int m_iColour;

	// Label to apply
	const char* m_szLabel;

	// Label offset in pixels
	int m_iXLabelOffset;
	int m_iYLabelOffset;
};


class TileManager;
class Man1 :
	public Man
{
public:
	Man1(Psyhw4Engine* pEngine, int iID,
		int iDrawType, int iSize, int iColour,
		const char* szLabel, int iXLabelOffset, int iYLabelOffset,
		TileManager* pTileManager);

	void setMovement(int iStartTime, int iEndTime, int iCurrentTime,
		int iStartX, int iStartY, int iEndX, int iEndY);

	void virtDoUpdate(int iCurrentTime) override;

protected:
	/** Movement position calculator - give it start and end position and times
	and it works out current position for the current time. */
	MovementPosition m_oMovement;

	// Pointer to the tile manager - we are going to use this!
	TileManager* m_pTileManager;
};

class Man2 :
	public Man
{
public:
	Man2(Psyhw4Engine* pEngine, int iID,
		int iDrawType, int iSize, int iColour,
		const char* szLabel, int iXLabelOffset, int iYLabelOffset,
		TileManager* pTileManager);

	void setMovement(int iStartTime, int iEndTime, int iCurrentTime,
		int iStartX, int iStartY, int iEndX, int iEndY);

	void virtDoUpdate(int iCurrentTime) override;

	/** Movement position calculator - give it start and end position and times
	and it works out current position for the current time. */
	MovementPosition m_oMovement;

	// Pointer to the tile manager - we are going to use this!
	TileManager* m_pTileManager;
	Man2(Psyhw4Engine * pEngine, int iID, int iDrawType, int iSize, int iColour, const char * szLabel, int iXLabelOffset, int iYLabelOffset);
	void setPosition(double dX, double dY);
	void setSpeed(double dSX, double dSY);
	double m_dX;
	double m_dY;
	double m_dSX;
	double m_dSY;
};

