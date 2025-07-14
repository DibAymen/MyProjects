#include<iostream>
using namespace std;

enum enRoshambo { Stone = 1, Paper = 2, Scissors = 3 };

struct stUserInformation
{
	string Choice;
};
struct stGeneralInformations
{
	short GameRounds = 0;
	short Player1WonTimes = 0;
	short ComputerWonTimes = 0;
	short DrawTimes = 0;
	string RoundWinner;
	string FinalWinner;


};

int EnterRoundsNumber()
{
	int Rounds;
	do {
		cout << "How Many Rounds 1 To 10 ? ";

		cin >> Rounds;

	} while (Rounds < 1 || Rounds>10);

	return Rounds;
}

int GenerateRandomNumber(int From, int To)
{
	return (rand() % (To - From + 1) + From);

}

void PlayerChoice(stUserInformation& PlayerInfo)
{
	short Choice = 0;
	do
	{
		cout << "You Choice :[1]:Stone, [2]:Paper, [3]:Scissors ? ", cin >> Choice;
		cout << endl;


	} while (Choice > 3 || Choice < 1);

	switch (Choice)
	{
	case enRoshambo::Paper:
		PlayerInfo.Choice = "Paper";
		break;
	case enRoshambo::Scissors:
		PlayerInfo.Choice = "Scissors";
		break;
	case enRoshambo::Stone:
		PlayerInfo.Choice = "Stone";
		break;
	}


}

void ComputerChoice(stUserInformation& ComputerInfo)
{
	short Choice = 0;
	Choice = GenerateRandomNumber(1, 3);

	switch (Choice)
	{
	case enRoshambo::Paper:
		ComputerInfo.Choice = "Paper";
		break;
	case enRoshambo::Stone:
		ComputerInfo.Choice = "Stone";
		break;
	case enRoshambo::Scissors:
		ComputerInfo.Choice = "Scissors";
		break;

	}

}

void CheckRoundWinner(stUserInformation ComputerInfo, stUserInformation PlayerInfo, stGeneralInformations& GameInfo)
{
	if (ComputerInfo.Choice == PlayerInfo.Choice)
	{
		GameInfo.DrawTimes++;
		GameInfo.RoundWinner = "[No Winner]";
		system("Color 6F");
	}
	else if (ComputerInfo.Choice == "Paper" && PlayerInfo.Choice == "Stone")
	{
		GameInfo.ComputerWonTimes++;
		GameInfo.RoundWinner = "[Computer]";
		system("Color 4F");

	}
	else if (ComputerInfo.Choice == "Stone" && PlayerInfo.Choice == "Scissors")
	{
		GameInfo.ComputerWonTimes++;
		GameInfo.RoundWinner = "[Computer]";
		system("Color 4F");

	}
	else if (ComputerInfo.Choice == "Scissors" && PlayerInfo.Choice == "Paper")
	{
		GameInfo.ComputerWonTimes++;
		GameInfo.RoundWinner = "[Computer]";
		system("Color 4F");

	}
	else
	{
		GameInfo.Player1WonTimes++;
		GameInfo.RoundWinner = "[Player]";
		system("Color 2F");
	}
}

void CheckFinalWinner(stGeneralInformations& GameInfo)
{
	if (GameInfo.Player1WonTimes == GameInfo.ComputerWonTimes)
	{
		GameInfo.FinalWinner = "No winner";
	}

	else if (GameInfo.Player1WonTimes > GameInfo.ComputerWonTimes)
	{
		GameInfo.FinalWinner = "Player";

	}

	else
	{
		GameInfo.FinalWinner = "Computer";

	}
}

void GenerateRounds(stGeneralInformations& GeneralInformation, stUserInformation& PlayerInfo, stUserInformation& ComputerInfo)

{

	for (int i = 1; i <= GeneralInformation.GameRounds; i++)
	{
		cout << "\n Round[" << i << "] begins : \n\n";
		ComputerChoice(ComputerInfo);
		PlayerChoice(PlayerInfo);
		CheckRoundWinner(ComputerInfo, PlayerInfo, GeneralInformation);
		cout << "-------------[Round" << i << "]----------------------\n\n";
		cout << "Player Choice : " << PlayerInfo.Choice;
		cout << "\nComputer Choice : " << ComputerInfo.Choice;
		cout << "\nRound Winner :" << GeneralInformation.RoundWinner << "\n\n";
		cout << "-------------------------------------------\n\n";

	}



}

void PrintResult(stGeneralInformations Result)
{
	cout << "				   --------------------------------------\n\n";
	cout << "				             ---G a m e O v e r ---\n\n";
	cout << "				   --------------------------------------\n\n";
	cout << "				   -------------{Game Results }----------\n\n";
	cout << "				   Game Rounds : " << Result.GameRounds;
	cout << "\n				   Player Won Times : " << Result.Player1WonTimes;
	cout << "\n				   Computer Won Times : " << Result.ComputerWonTimes;
	cout << "\n				   Draw Times : " << Result.DrawTimes;
	cout << "\n				   Final Winner : " << Result.FinalWinner;
	cout << "\n\n				   --------------------------------------\n\n";


}


void GameBegin()
{
	string Qustion;

	do {
		stGeneralInformations GeneralInformation;
		stUserInformation ComputerInformations, PlayerInformations;
		GeneralInformation.GameRounds = EnterRoundsNumber();
		GenerateRounds(GeneralInformation, PlayerInformations, ComputerInformations);
		CheckFinalWinner(GeneralInformation);
		PrintResult(GeneralInformation);
		cout << "				  Do you Want To Play Again? Y/N? ", cin >> Qustion;
		if (Qustion == "Y" || Qustion == "y")
			system("cls");
	} while (Qustion == "Y" || Qustion == "y");

}


int main()
{
	srand((unsigned)time(NULL));

	GameBegin();

	return  0;

	// Day 1 : 0.5 h 
	// Day 2 : 2.5 h 
	// Day 3 : 2h 



}

