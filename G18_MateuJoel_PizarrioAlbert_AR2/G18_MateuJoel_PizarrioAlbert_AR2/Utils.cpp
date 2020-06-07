#include "Utils.h"

void Utils::PrintScores(const int & p1Score, const int & p2Score)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);
	std::cout << "*------SCORE------*";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << "\nPlayer 1: " << p1Score << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	std::cout << "Player 2: " << p2Score << std::endl;

}

void Utils::PrintUI(const int & p1lives, const int & p2lives, const int &timeLeft, const bool &paused)
{
	if (paused) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 203);
		std::cout << "-*-*-PAUSE-*-*-";
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 60);
		std::cout << "-*-*-PLAY-*-*-";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "\nTime: " << timeLeft / 1000 << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);
	std::cout << "--Lives--";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << "\nPl1: " << p1lives << "\t\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	std::cout << "Pl2: " << p2lives << std::endl;

}
