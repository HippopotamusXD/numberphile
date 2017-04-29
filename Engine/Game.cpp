/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}



void Game::ComposeFrame()
{
	checkForInput();
}

void Game::checkForInput()
{
	if (wnd.mouse.LeftIsPressed() && !clicked && clickNum < arrSize) {
		clicked = true;
		xPos[clickNum] = wnd.mouse.GetPosX();
		yPos[clickNum] = wnd.mouse.GetPosY();
		clickNum++;
	}
	if (!wnd.mouse.LeftIsPressed()) {
		clicked = false;
	}
	if (clickNum >= arrSize) {
		done = true;
	}
	for (int i = 0; i < arrSize; i++) {
		if (xPos[i] >= 0 && yPos[i] >= 0) {
			int x = xPos[i];
			int y = yPos[i];
			gfx.PutPixel(x, y, 255, 0, 0);
		}
		else {
			break;
		}
	}
}