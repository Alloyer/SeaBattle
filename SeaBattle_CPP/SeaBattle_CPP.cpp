// SeaBattle_CPP.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include "fstream"
#include "Player.h"
#include "AI.h"
#include <string>

int main()
{
	setlocale(LC_ALL, "Russian");

	AI *ai = new AI();
	ai->initializeField();

	std::string FileName;
	std::cout << "������� �������� ����� � ������\n";
	std::cin >> FileName;
	Player *player = new Player();
	player->initializeField(FileName);
	player->showFields(*ai);

    return 0;
}

