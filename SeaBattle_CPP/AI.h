#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

class AI
{
public: 

	AI()
	{
		std::cout << "CREATED!\n";
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				Field[i][j] = 'O';
			}
		}
	}

	void initializeField()
	{
		srand(time(0));
		for (int i = 0; i < 10; i++)
		{
			srand(time(0));
			int x = rand() % 9;
			int y = rand() % 9;
			int orientation = (rand() % 9) % 2;
			while (!isOK(x, y, Ships[i], orientation))
			{
				srand(time(0));
				int x = rand() % 9;
				int y = rand() % 9;
				int orientation = (rand() % 9) % 2;
			}
			setShip(x, y, Ships[i], orientation);
		}
	}

	char getFieldSymbol(const int& x, const int& y)
	{
		return Field[x-1][y-1];
	}

private:

	// проверка точки на пригодность постановки в неё корабля
	// координаты x и у, а также размер корабля и ориентация
	// ориентация = 0 - горизонтально; 1 - вертикально.
	bool isOK(const int& x, const int& y, const int& size, const int& orientation) const
	{
		if (orientation == 0)
		{
			if (y >= 0 && y <= 9 && x >= 0 && x <= 10 - size)
			{
				for (int i = 0; i < size; i++)
				{
					if (Field[x + i][y] != 'O') return false;
				}
				return true;
			}
			else return false;
		}
		else if(orientation == 1)
		{
			if (x >= 0 && x <= 9 && y >= 0 && y <= 10 - size)
			{
				for (int i = 0; i < size; i++)
				{
					if (Field[x][y + i] != 'O') return false;
				}
				return true;
			}
			else return false;
		}
	}

	void setShip(const int& x, const int& y, const int& size, const int& orientation)
	{
		if (orientation == 0)
		{
			for (int i = 1; i <= size; i++)
			{
				Field[x + i - 1][y] = 'S';
			}
		}
		else if(orientation == 1)
		{
			for (int i = 1; i <= size; i++)
			{
				Field[x][y + i - 1] = 'S';
			}
		}
	}

	char Field[10][10];
	int Ships[10] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };

	
};