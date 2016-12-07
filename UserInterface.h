#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Structure.h"

class UserInterface {
public:
	static void drawUI();		// Draw the user interface
	static void incrScore();    // Increases the global score
	static void decrScore(int n);    // Decreases the global score
	static int getScore();		// Gets global score.
	static void decrTime();		// Decrease global time.
	static int getTime();   	// Gets global time.
	static void setTime(); 
	static void gameOver();
	static void levelLost();
	static void finishedLevel();
	static void setGameOverState();
	static bool getGameOverState();
	static void setLevelState();
	static bool getLevelState();
	static void setEndGameState();
	static bool getEndGameState();
	static void setFinishedLevelState();
	static bool getFinishedLevelState();
	static bool calculatingScore();
	static void setCalculatingScore(bool n);
};

#endif