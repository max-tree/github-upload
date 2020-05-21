#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

using namespace std;

//function prototypes of choices.cpp
int user_choice(int round_num);
int computer_choice(void);
//other function
bool round_result(int user, int computer);

//main
int main()
{
	printf ("There are three rounds for this game of Rock, Paper, /n Scissors. Choose from the following options:\n");
	printf ("1 for Rock \n 2 for Paper \n 3 for Scissors \n\n");
	unsigned int round = 1;
	unsigned int uc = 0;
	unsigned int cc = 0;
	bool user_win = 1;
	int score = 0;
	while (round <= 3)
	{
		uc = user_choice(round);
		cc = computer_choice();
		if (uc != cc)
		{
			user_win = round_result(uc, cc);
			if (user_win)
			{
				printf("Nice! You have won the round! \n");
				score++;
			}
			else
			{
				printf("Ouch! You have lost the round. \n");
				score--;
			}
			round++;
		}
		else
		{
			printf("Tied. The round did not count.\n\n");
		}
	}
	switch (score)
	{
	case 1:
		printf ("You won 2 to 1!\n");
			break;
	case -1:
		printf ("You lost 2 to 1.\n");
		break;
	case 3:
		printf("You won 3 to 0!\n");
		break;
	case -3:
		printf ("You lost 3 to 0.\n");
		break;
	default:
		printf("error\n");
		break;
	}

	return 0;
}

bool round_result(int user, int computer)
{
	//default to lose if the round is a tie.
	bool user_win = 1;
	if (user < computer)
	{
		if (computer - 1 > user)	//The case of Scissors and Rock
		{
			user_win = 1;
		}
		else
		{
			user_win = 0;
		}
	}
	else if (user == computer)
	{
		user_win = 0;
	}
	else
	{
		if (user - 1 > computer)	//The case of Scissors and Rock
		{
			user_win = 0;
		}
		else
		{
			user_win = 1;
		}
	}

	return user_win;
}