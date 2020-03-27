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
