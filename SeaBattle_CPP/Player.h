#pragma once

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "AI.h"

class Player
{
public:

	void initializeField(const std::string& FileName)
	{
		std::ifstream Scanner;
		
		std::string InputString;
		int i = 0;
		try
		{
			Scanner.open("test.txt");
			if (!Scanner.is_open())
			{
				std::cout << "Не удалось открыть файл!\n";
				return;
			}

			while (getline(Scanner, InputString))
			{
				for (int j = 0; j < InputString.length(); j++)
				{
					Field[i][j] = InputString[j];
				}
				i++;
			}
		}
		catch (std::exception e)
		{
			e.what();
		}
		Scanner.close();
	}

	void showFields(AI& ai) const
	{
		std::cout << "-------------------SHOWING FIELD------------------\n";
		for (int i = 0; i < 11; i++)
		{
			if (i == 0)
			{
				for (int j = 0; j < 27; j++)
				{
					if (j == 11) continue;
					if (j == 0)
					{
						std::cout << "  ";
						continue;
					}
					if (j > 10 && j < 17) std::cout << " ";
					else if (j > 16) std::cout << j - 16 << " ";
					else std::cout << j << " ";
				}
			}
			else
			{
				for (int j = 0; j < 11; j++)
				{
					if (j == 0)
					{
						std::cout << char(97 + i - 1) << " ";
						continue;
					}
					std::cout << Field[i-1][j-1] << " ";
				}
				std::cout << "    ";
				for (int j = 0; j < 11; j++) // тут данные из массива с кораблями компьютера
				{
					if (j == 0)
					{
						std::cout << char(97 + i - 1) << " ";
						continue;
					}
					std::cout << ai.getFieldSymbol(i, j) << " "; //TODO: заменить это на вывод поля попаданий игрока
				}
			}
			std::cout << std::endl;
		}
		std::cout << "--------------------------------------------------\n";
	}

private:

	char Field[10][10];
};