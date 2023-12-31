#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int ReadNumber(string Message)
{
	int num;
	do
	{
		cout << Message;
		cin >> num;
	} while (num < 0);

	return num;
}

int ReadNumberForChoice(string Message)
{
	int num;

	do
	{
		cout << Message;
		cin >> num;
	} while (num < 1 || num > 3);

	return num;
}

int RandomNumber(int From, int To)
{
	int Random = rand() % (To - From + 1) + From;

	return Random;
}

void CheckTheWinner(int User, int Program, int& UserWin, int& ProgramWin, int& DrawTimes, string& Winner)
{
	if ((User == 1 && Program == 3) || (User == 3 && Program == 2) || (User == 2 && Program == 1))
	{
		system("color 2F");
		cout << "\a";
		Winner = "You";
		UserWin++;
	}
	else if (User == Program)
	{
		system("color 6F");
		cout << "No one wins" << endl;
		Winner = "No one";
		DrawTimes++;
	}
	else
	{
		system("color 4F");
		Winner = "Program";
		ProgramWin++;
	}
}

void PlayingTime(int& UserWin, int& ProgramWin, int& DrawTimes, int& UserChoice, int& ProgramChoice, string& Winner)
{
	UserChoice = ReadNumberForChoice("Enter a number for your choice (1-3): ");
	ProgramChoice = RandomNumber(1, 3);

	CheckTheWinner(UserChoice, ProgramChoice, UserWin, ProgramWin, DrawTimes, Winner);
}

void PrintRoundWinnerInfo(string UserWordChoice, string ProgramWordChoice, int Round, string Winner)
{
	cout << "\n-------------- Round[" << Round + 1 << "] --------------" << endl;
	cout << "Player Choice  : " << UserWordChoice << endl;
	cout << "Program Choice : " << ProgramWordChoice << endl;
	cout << "Round Winner   : " << Winner << endl;
}

void ChangeChoiceNumberToChoiceWord(int UserChoice, int ProgramChoice, string& UserWordChoice, string& ProgramWordChoice)
{
	if (UserChoice == 1)
	{
		UserWordChoice = "Stone";
	}
	else if (UserChoice == 2)
	{
		UserWordChoice = "Paper";
	}
	else
	{
		UserWordChoice = "Scissor";
	}

	if (ProgramChoice == 1)
	{
		ProgramWordChoice = "Stone";
	}
	else if (ProgramChoice == 2)
	{
		ProgramWordChoice = "Paper";
	}
	else
	{
		ProgramWordChoice = "Scissor";
	}
}

void ChoicesPattern(int RoundNumber)
{
	cout << "\n" << setw(60) << "---------- Choices ----------";
	cout << "\n" << setw(50) << "Stone    [1]"
		<< "\n" << setw(50) << "Paper    [2]"
		<< "\n" << setw(50) << "Scissors [3]" << endl << endl;
}

void PrintWinnerInfo(int rounds, int UserWin, int ProgramWin, int DrawTimes)
{
	cout << "\n\n\t\t------------------------------------------------------------\n"
		<< "\t\t\t\t +++ THE WINNER +++\n"
		<< "\t\t------------------------------------------------------------\n";

	cout << "\n\t\t\t\tGame Rounds        : " << rounds;
	cout << "\n\t\t\t\tPlayer won times   : " << UserWin;
	cout << "\n\t\t\t\tComputer won times : " << ProgramWin;
	cout << "\n\t\t\t\tDraw times         : " << DrawTimes;

	if (UserWin > ProgramWin)
	{
		cout << "\n\t\t\t\tFinal Winner       : You";
		system("color 2F");
	}
	else if (UserWin < ProgramWin)
	{
		cout << "\n\t\t\t\tFinal Winner       : The Program";
		system("color 4F");
	}
	else
	{
		cout << "\n\t\t\t\tFinal Winner       : No one";
		system("color 6F");
	}
}

void PlayRounds(int Rounds)
{
	int UserWin = 0, ProgramWin = 0, DrawTimes = 0;
	int UserChoice = 0, ProgramChoice = 0;
	string UserWordChoice, ProgramWordChoice;
	string Winner;

	for (int i = 0; i < Rounds; i++)
	{
		ChoicesPattern(i);
		PlayingTime(UserWin, ProgramWin, DrawTimes, UserChoice, ProgramChoice, Winner);
		ChangeChoiceNumberToChoiceWord(UserChoice, ProgramChoice, UserWordChoice, ProgramWordChoice);
		PrintRoundWinnerInfo(UserWordChoice, ProgramWordChoice, i, Winner);
	}

	PrintWinnerInfo(Rounds, UserWin, ProgramWin, DrawTimes);
}

void StartTheGame()
{
	int NumberOfRounds;
	char ExitOrRepeat;

	do
	{
		system("cls");
		system("color 0F");
		cout << "\t\t\t\t\t\t----- The Game Start -----\n\n";
		NumberOfRounds = ReadNumber("Please enter how many rounds you wanna play: ");
		PlayRounds(NumberOfRounds);
		cout << "\n\n\t\t\t\t--------------------------" << endl;
		cout << "\t\t\t\tDo you wanna Repeat (Y/N): ";

		cin >> ExitOrRepeat;

		cout << endl << endl;

	} while (ExitOrRepeat == 'Y' || ExitOrRepeat == 'y');

	exit(1);
}

int main()
{
	srand((unsigned)time(NULL));

	StartTheGame();

	return 0;
}