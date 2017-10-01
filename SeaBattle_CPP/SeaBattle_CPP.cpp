// SeaBattle_CPP.cpp: определ€ет точку входа дл€ консольного приложени€.
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
	std::cout << "¬ведите название файла с картой\n";
	std::cin >> FileName;
	Player *player = new Player();
	player->initializeField(FileName);

    return 0;
}

