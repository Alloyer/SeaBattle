#pragma once

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

class Map
{
public:

	void initialize_field(const std::string& FileName)
	{
		std::ifstream scanner;
		
		std::string str;
		int i = 0;
		try
		{
			scanner.open("test.txt");
			if (!scanner.is_open())
			{
				std::cout << "Не удалось открыть файл!\n";
				return;
			}

			while (getline(scanner, str))
			{
				for (int j = 0; j < str.length(); j++)
				{
					field[i][j] = str[j];
				}
				i++;
			}
		}
		catch (std::exception e)
		{
			e.what();
		}
		scanner.close();
		this->show_field();
	}

	void show_field() const
	{
		std::cout << "-----------------SHOWING FIELD----------------\n";
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				std::cout << field[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "----------------------------------------------\n";
	}

private:

	char field[10][10];
};