#include <iostream>
#include <vector>

using namespace std;

//function prototypes
void enter_Roman_numerals(void);							//user inputs each letter of the Roman Numeral.
void RtoA_Arithmetic(vector<int>& converted_num, int l);	//Roman to Arabic algorithm.

void RtoA(void)
{
	enter_Roman_numerals();
	return;
}

void enter_Roman_numerals(void)
{
	char input_char = 'Q';
	unsigned int input_num = 0;
	vector<int> num;				//used to store each Roman numeral individually for the arithmetic function.
	unsigned int length = 0;		//stores the length of the vector.
	bool Roman_check = 1;			// This variable is used to check if a Roman numeral has been entered.

	cout << "Please input the Roman numeral Characters in order" << endl;
	cout << "from left to right always capitalizing the letter." << endl;
	cout << "Once you have entered the last character, type 'Z'" << endl;
	cout << "and hit 'enter' to start the conversion." << endl;
	cout << "NOTE:you must type in one character and hit enter" << endl;
	cout << "before preceding to the next character." << endl << endl;

	while (input_char != 'Z')		//translate each input into a number and store it in a vector.
	{
		cin >> input_char;
		switch (input_char)
		{
		case 'I':
			input_num = 1;
			break;
		case 'V':
			input_num = 5;
			break;
		case 'X':
			input_num = 10;
			break;
		case 'L':
			input_num = 50;
			break;
		case 'C':
			input_num = 100;
			break;
		case 'D':
			input_num = 500;
			break;
		case 'M':
			input_num = 1000;
			break;
		case 'Z':
			Roman_check = 0;
			break;
		default:
			cout << endl << "That is not a Roman numeral. Please input an" << endl;
			cout << "I, V, X, L, C, D, or M (or Z if finished)." << endl << endl;
			Roman_check = 0;
			break;
		}
		if (Roman_check)
		{
			num.push_back(input_num);
			length++;
		}
		else { Roman_check = 1; }
	}

	//letter to number conversion complete, now on to arithmetic to get the Arabic number.
	RtoA_Arithmetic(num, length);
	return;
}

void RtoA_Arithmetic(vector<int>& converted_num, int l)
{
	//change each vector component to be negative if it is smaller than the number on its right.
	for (int i = 0; i + 1 < l; i++)
	{
		if (converted_num[i] >= converted_num[i + 1])
		{
			//do nothing
		}
		else
		{
			converted_num[i] = -converted_num[i];
		}
	}

	int Arabic_num = 0;
	//Add them together to get the number in the Arabic system.
	for (int i = 0; i < l; i++)
	{
		Arabic_num += converted_num[i];
	}

	cout << "The Roman number entered is equivalent to:" << endl << endl;
	cout << Arabic_num << endl << endl;
	return;
}
