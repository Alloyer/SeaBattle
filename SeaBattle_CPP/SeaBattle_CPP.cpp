// SeaBattle_CPP.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include "fstream"
#include "Map.h"
#include <string>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::string FileName;
	std::cout << "������� �������� ����� � ������\n";
	std::cin >> FileName;
	Map *map = new Map();
	map->initialize_field(FileName);

    return 0;
}

