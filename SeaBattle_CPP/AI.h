#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

class AI
{
public: 

	void initializeField()
	{
		//первичное заполнение пустыми клетками
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				Field[i][j] = 'O';
			}
		}

		srand(time(0));
		for (int i = 0; i < 10; i++)
		{
			int x = rand() % 9;
			int y = rand() % 9;
			int orientation = (rand() % 9) % 2;
			while (!isOK(x, y, Ships[i], orientation))
			{
				x = rand() % 9;
				y = rand() % 9;
				orientation = (rand() % 9) % 2;
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
			if (y >= 0 && y <= 10 - size && x >= 0 && x <= 9)
			{

				for (int i = -1; i <= 1; i++)
				{
					if (x + i < 0 || x + i > 9) continue;
					for (int j = -1; j <= size; j++)
					{
						if (y + j < 0 || y + j > 9) continue;
						if (Field[x + i][y + j] != 'O') return false;
					}
				}
				return true;
				////случай с (0,0)
				//if (y == 0 && x == 0) 
				//{
				//	for (int i = 0; i <= 1; i++)
				//	{
				//		for (int j = 0; j <= 1; j++)
				//		{
				//			if (Field[x + i][y + j] != 'O') return false;
				//		}
				//	}
				//	/*for (int i = 0; i <= size; i++)
				//	{
				//		if (Field[x + 1][y + i] != 'O') return false;
				//	}
				//	if (Field[x][y + size] != 'O') return false;*/
				//	return true;
				//}
				//
				////случай с (0,10-size)
				//if (y == 10 - size && x == 0) 
				//{
				//	for (int i = 0; i <= 1; i++)
				//	{
				//		for (int j = -1; j < size; j++)
				//		{
				//			if (Field[x + i][y + j] != 'O') return false;
				//		}
				//	}
				//	/*for (int i = -1; i < size; i++)
				//	{
				//		if (Field[x + 1][y + i] != 'O') return false;
				//	}
				//	if (Field[x][y - 1] != 'O') return false;*/
				//	return true;
				//}
				//
				////случай с (0, 1-8[size])
				//if (y >= 1 && y < 10 - size && x == 0)
				//{
				//	for (int i = 0; i <= 1; i++)
				//	{
				//		for (int j = -1; j <= size; j++)
				//		{
				//			if (Field[x + i][y + j] != 'O') return false;
				//		}
				//	}
				//	/*if (Field[x][y + size] != 'O') return false;
				//	if (Field[x][y - 1] != 'O') return false;
				//	for (int i = -1; i <= size; i++)
				//	{
				//		if (Field[x + 1][y + i] != 'O') return false;
				//	}*/
				//	return true;
				//}
				//
				////случай с (9,0)
				//if (y == 0 && x == 9)
				//{
				//	for (int i = -1; i <= 0; i++)
				//	{
				//		for (int j = 0; j <= 1; j++)
				//		{
				//			if (Field[x + i][y + j] != 'O') return false;
				//		}
				//	}
				//	/*for (int i = 0; i <= size; i++)
				//	{
				//		if (Field[x - 1][y + i] != 'O') return false;
				//	}
				//	if (Field[x][y + size] != 'O') return false;*/
				//	return true;
				//}
				//
				////случай с (9,10-size)
				//if (y == 10 - size && x == 9)
				//{
				//	for (int i = -1; i <= 0; i++)
				//	{
				//		for (int j = -1; j < size; j++)
				//		{
				//			if (Field[x + i][y + j] != 'O') return false;
				//		}
				//	}
				//	/*for (int i = -1; i < size; i++)
				//	{
				//		if (Field[x - 1][y + i] != 'O') return false;
				//	}
				//	if (Field[x][y - 1] != 'O') return false;*/
				//	return true;
				//}
				//
				////случай с (9,1-8[size])
				//if (y >= 1 && y < 10 - size && x == 9)
				//{
				//	if (Field[x][y + size] != 'O') return false;
				//	if (Field[x][y - 1] != 'O') return false;
				//	for (int i = -1; i <= size; i++)
				//	{
				//		if (Field[x - 1][y + i] != 'O') return false;
				//	}
				//	return true;
				//}
				//
				////случай с (1-8,0)
				//if (y == 0 && x >= 1 && x <= 8)
				//{
				//	for (int i = -1; i <= 1; i += 2)
				//	{
				//		for (int j = 0; j <= size; j++)
				//		{
				//			if (Field[x + i][y + j] != 'O') return false;
				//		}
				//	}
				//	if (Field[x][y + size] != 'O') return false;
				//	return true;
				//}
				//
				////случай с (1-8,10-size)
				//if (y == 10 - size && x >= 1 && x <= 8)
				//{
				//	for (int i = -1; i <= 1; i += 2)
				//	{
				//		for (int j = -1; j < size; j++)
				//		{
				//			if (Field[x + i][y + j] != 'O') return false;
				//		}
				//	}
				//	if (Field[x][y - 1] != 'O') return false;
				//	return true;
				//}
				//
				////случаи с (1-8, 1-8)
				//if (y >= 1 && y <= 8 && x >= 1 && x <= 8)
				//{
				//	for (int i = -1; i <= 1; i++)
				//	{
				//		for (int j = -1; j <= size; j++)
				//		{
				//			if (Field[x + i][y + j] != 'O') return false;
				//		}
				//	}
				//	return true;
				//}
				//
				//////случаи с (1-8, 1-8)
				////for (int i = 0; i < size; i++)
				////{
				////	if (Field[x][y + i] != 'O') return false;
				////}
				////return true;
			}
			else return false;
		}
		else if(orientation == 1)//TODO: сделать точечные проверки для  вертикальной ориентации
		{
			if (y >= 0 && y <= 9 && x >= 0 && x <= 10 - size)
			{

				for (int i = -1; i <= size; i++)
				{
					if (x + i < 0 || x + i > 9) continue;
					for (int j = -1; j <= 1; j++)
					{
						if (y + j < 0 || y + j > 9) continue;
						if (Field[x + i][y + j] != 'O') return false;
					}
				}
				return true;
				////случай с (0,0)
				//if (x == 0 && y == 0)
				//{
				//	for (int i = 0; i <= size; i++)
				//	{
				//		if (Field[x + i][y + 1] != 'O') return false;
				//	}
				//	if (Field[x + size][y] != 'O') return false;
				//	return true;
				//}
				////
				////случай с (0,9)
				//if (x == 0 & y == 9)
				//{
				//	for (int i = 0; i <= size; i++)
				//	{
				//		if (Field[x + i][y - 1] != 'O') return false;
				//	}
				//	if (Field[x + size][y] != 'O') return false;
				//	return true;
				//}
				////
				////случай с (10-size,0)
				//if (x == 10 - size && y == 0)
				//{
				//	for (int i = -1; i < size; i++)
				//	{
				//		if (Field[x + i][y + 1] != 'O') return false;
				//	}
				//	if (Field[x - 1][y] != 'O') return false;
				//	return true;
				//}
				////
				////случай с (10-size,9)
				//if (x == 10 - size && y == 9)
				//{
				//	for (int i = -1; i < size; i++)
				//	{
				//		if (Field[x + i][y - 1] != 'O') return false;
				//	}
				//	if (Field[x - 1][y] != 'O') return false;
				//	return true;
				//}
				////
				////случай с (0,1-8)
				////
				////
				////случай с (10-size,1-8)
				////
				////
				////случай с (1-8[size],0)
				////
				////
				////случай с (1-8[size],9)
				////
				////
				////случаи с (1-8,1-8)
				//if (y >= 1 && y <= 8 && x >= 1 && x <= 8)
				//{
				//	for (int i = -1; i <= 1; i++)
				//	{
				//		for (int j = -1; j <= size; j++)
				//		{
				//			if (Field[x + j][y + i] != 'O') return false;
				//		}
				//	}
				//	return true;
				//}
				//
				///*for (int i = 0; i < size; i++)
				//{
				//	if (Field[x + i][y] != 'O') return false;
				//}
				//return true;*/
			}
			else return false;
		}
	}

	void setShip(const int& x, const int& y, const int& size, const int& orientation)
	{
		if (orientation == 0 || size == 1)
		{
			for (int i = 1; i <= size; i++)
			{
				Field[x][y + i - 1] = 'S';
			}
		}
		else if(orientation == 1)
		{
			for (int i = 1; i <= size; i++)
			{
				Field[x + i - 1][y] = 'S';
			}
		}
		
	}

	char Field[10][10];
	int Ships[10] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };

	
};