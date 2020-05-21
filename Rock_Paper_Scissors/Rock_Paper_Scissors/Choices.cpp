#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

using namespace std;

int user_choice(int round_num)
{
	cout << "Round #" << round_num << ". What is your choice?";
	int uc = 0;
	cin >> uc;
	return uc;
}

int computer_choice()
{
	static unsigned int cc = 0;
	srand(time(NULL));
	cc = rand() % 3 + 1;
	cout << "The computer chose " << cc << "\n";
	return cc;
}