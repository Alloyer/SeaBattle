// SeaBattle_CPP.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include "fstream"
#include "Player.h"
#include <string>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::string FileName;
	std::cout << "������� �������� ����� � ������\n";
	std::cin >> FileName;
	Player *player = new Player();
	player->initializeField(FileName);

    return 0;
}

