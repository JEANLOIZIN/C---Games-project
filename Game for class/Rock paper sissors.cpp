/* Jean Loizin

This is the game of ROCK / PAPER / SCISSORS.
The game will be played with two player, Player one will prompt to input his or her choice and player two choice will be selected randomly. 
The game of the rules are simple and will be display after the program runs.
Please understand the rules and the inputs needed in order to play this game. 
Thank you for putting this program to use and have fun. */





#include <iostream>// input, output library
#include <stdio.h>// library	
#include <time.h>//random time Library
#include <fstream>// file in Library



using namespace std; // std prototype 

enum objectType {Rock, Paper, Scissors};// enum prototype

void displayRules ();// initialization
objectType selectRand();// initialization
objectType retrievePlay (char selection);// initialization objecttype prototype
bool validSelection (char selection); // intialization objecttype prototype
void convertEnum (objectType object);// intialization
objectType winningObject (objectType play1, objectType computer);// initialization
void gameResult (objectType play1, objectType computer, int& winner);// initialization
void displayResults (int gCount, int wCount1, int wCount2);// initialization
void load(char &gameCount, char &winCount1,char &winCount2, string name); // loading function without returning anything.
int save(int gameCount,int winCount1, int winCount2, string name); // setting up save function.

int main()// main function for opeinning the body
{
	string Name; // string name initializing
	int gameCount; // gamecout initializing
	int winCount1; // win count initializing
	int winCount2; // win game count initializing
	int gameWinner; // game winning count initializing
	char response; // to initialize the response variable
	char selection1;// selection 1 initialization
	char selection2; // selection 2 initialization
	objectType play1; // playing selection objecttype
	objectType computer; // computer selection objecttype

	gameCount = 0; // variable
	winCount1 = 0; // variable
	winCount2 = 0; // variable
	displayRules (); 

	cout<< endl;
	//cout << "To begin, Please enter your name; ";
	//cin >> Name;
	cout << "Enter Y/y to play the game: "; // asking playing access
	cin >> response; // response waiting for access or not. 
	cout << endl; // skipping line.

	while (response == 'Y' || response == 'y') // while loop, if Answer input is (Y / y)
	{
		cout << "Player 1, Please enter your choice: "; // printing out player one selection request
		cin >> selection1;// response
		cout << endl;// skipping line

		cout << "The computer Selected:  "; // printing out computer selection
		computer= selectRand(); // computer selections randomly
		convertEnum(static_cast<objectType>(computer)); // switching and converting computer choices from a number to character.

		cout << endl;// line skipping
		
		if (validSelection (selection1)) // if selection is valid, run the play. 
		{
			play1 = retrievePlay (selection1);
			gameCount ++;
			gameResult (play1, computer, gameWinner);

			if (gameWinner == 1)
				winCount1 ++;
			else
				if (gameWinner == 2)
					winCount2 ++;
		int save(int gCount, int wCount1 , int wCount2); // saving the output file. customized with spacings. 
		{
			ofstream file;
			file.open("Name"); // opening a file called name
			file << "Number of Game played =  " << gameCount; // writting in the file
			cout << endl;
			file << "\n\nNumber of Game Won by player one = " << winCount1; // writting in the file
			cout << endl;
			file << "\n\nNumber of Game won by the computer = " << winCount2; // writting in the file
			cout << endl;
			file << "\n\nAll selections made by player 1 = " << selection1; // writting in the file
			cout << endl;
			file << "\n\nAll selections made by computer = " << selectRand(); // writting in the file
			cout << endl;
			cout << endl;
			file.close();
		}
		}
		cout << "Enter Y/y to play the game: "; // asking for permission to play another game.
		cin >> response; // waitting for response
		cout << endl;
	}
	displayResults (gameCount, winCount1, winCount2); // display result. 

	system("pause");
	return 1;
}

objectType selectRand() // computer randomly selection and limiting the selection only up to 3. 
{
	return (objectType)((rand() + time(0)) % 3);
}
void displayRules () // Rule displayment... 
{
	cout << "\t\tWelcome to the game of Rock, Papers, and Scissors." << endl;
	cout << "\t\t\bThis is a game for two players. For each game, each" << endl;
	cout << "     \tPlayer selects one of the objects, Rock, Paper, and Scissor" << " Scissors." << endl;
	cout << "			The rules for winning the game are: " << endl << endl << endl;
	cout << "1. If both player selects the game object, it is a " << "tie." << endl << endl;
	cout << "2. Rock breaks Scissors: So player who selects Rock" << " wins " << endl << endl;
	cout << "3. Paper covers Rock: So player who selects Paper" << " wins" << endl << endl;
	cout << "4. Scissors cuts Paper: So player who selects Scissors" << " wins " << endl << endl << endl;
	cout << "Enter R or r to select Rock, P or p to select Paper, and " << "S or s to select Scissors." << endl;
}

bool validSelection (char selection) // selections
{
	switch (selection)
	{
	case 'R': case 'r':
	case 'P': case 'p':
	case 'S': case 's': return true;
	default: return false;
	}
}

objectType retrievePlay (char selection) // turning character to the full word.
{
	objectType object;

	switch (selection)
	{
	case 'R': case 'r': object = Rock;
		break;
	case 'P': case 'p': object = Paper;
		break;
	case 'S': case 's': object = Scissors;
	}
	return object;
}

void convertEnum (objectType object) // converting  and ouputing object type selection
{
	switch (object)
	{
	case Rock: cout << "Rock";
		break;
	case Paper: cout << "Paper";
		break;
	case Scissors: cout << "Scissors";
	}
}

objectType winningObject (objectType play1, objectType computer) // comparing selections
{
	if ((play1 == Rock &&  computer == Scissors)
		|| (computer == Rock && play1 == Scissors))
		return Rock;
	else 
		if ((play1 == Rock && computer== Paper)
			|| (computer == Rock && play1 == Paper))
			return Paper;
		else
			return Scissors;
}

void gameResult (objectType play1, objectType computer, int &winner) // resulting game, deciding who wins
{
	objectType winnerObject;

	if (play1 == computer)
	{
		winner = 0;
		cout << "Both players selected ";
		convertEnum (play1);
		cout << ". This game is a tie." << endl;
	}
	else
	{
		winnerObject = winningObject (play1, computer);
		cout << endl << endl;
		cout << "Player 1 selection = ";
		convertEnum (play1);
		cout<< endl << endl;
		cout << "Computer selection = ";
		convertEnum (computer);
		cout << endl << endl;
		cout << endl;
		if (play1 == winnerObject)
			winner = 1;
		else
			if (computer == winnerObject)
				winner = 2;
		//save(int gameCount, int winCount1, int winCount2, string name);
		cout << "Player" << winner << " =  wins this game." << endl;
		cout << endl << endl;
	}
}
	
void displayResults (int gCount, int wCount1, int wCount2) // bottom screen outputs
	
{

	cout << "The number of plays: " << gCount << endl;
	cout << "The number of plays won by player 1: " << wCount1 << endl;
	cout << "The number of plays won by Computer: " << wCount2 << endl;

}
void load( char &gameCount, char &winCount1, char &winCount2, string Name) // loading file name and input the game count, win counts and closing file. 
	{
		
		ifstream file;
		file.open(Name);
		if(file.good())
		{
		
		file >> gameCount;
		file >> winCount1;
		file >> winCount2;
		}
		file.close();
		
	}

/// END OF THE PROGRAM. 