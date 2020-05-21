#include <iostream>
#include <vector>

using namespace std;

//function prototypes
void enter_Arabic_num(void);				//user inputs the Arabic number to be converted.
void AtoR_Conversion(int& num_to_R);		//Arabic to Roman Conversion.

void AtoR(void)
{	

	enter_Arabic_num();
	return;
}

void enter_Arabic_num(void)
{
	int num = 0;	//Number to be converted to Roman Numeral.
	cout << "Please input the entire Arabic number and hit enter." << endl;
	cout << "NOTE: Do not input negative numbers nor decimals" << endl;
	cout << "because neither exist in Roman numerals." << endl << endl;
	cin >> num;

	AtoR_Conversion(num);
	return;
}

void AtoR_Conversion(int& num_to_R)
{
	int placeholder = 0, length = 0;		//placeholder variables that allow for numerical computations and finding the length of the vector that will hold the Roman Numeral.
	vector<char> num_Roman;
	
	//find the number of M, then the number of D, etc. and then store them in a vector.
	//M
	placeholder = num_to_R / 1000;
	while (placeholder > 0)
	{
		num_Roman.push_back('M');
		length++; placeholder--;
	}
	num_to_R = num_to_R % 1000;
	//D
	placeholder = num_to_R / 500;
	num_to_R = num_to_R % 500;
	while (placeholder > 0)
		if (num_to_R < 400)
		{
			num_Roman.push_back('D');
			length++; placeholder--;
		}
		else
		{
			num_Roman.push_back('C');
			num_Roman.push_back('M');
			placeholder = 0;
			length += 2;
		}

	//C
	placeholder = num_to_R / 100;
	num_to_R = num_to_R % 100;
	while (placeholder > 0)
		if (placeholder < 4)
		{
			num_Roman.push_back('C');
			length++; placeholder--;
		}
		else
		{
			num_Roman.push_back('C');
			num_Roman.push_back('D');
			placeholder = 0;
			length += 2;
			//num_to_R -= 400;
		}

	//L
	placeholder = num_to_R / 50;
	num_to_R = num_to_R % 50;
	while (placeholder > 0)
		if (num_to_R < 40)
		{
			num_Roman.push_back('L');
			length++; placeholder--;
		}
		else
		{
			num_Roman.push_back('X');
			num_Roman.push_back('C');
			placeholder = 0;
			length += 2;
			num_to_R -= 40;
		}

	//X
	placeholder = num_to_R / 10;
	num_to_R = num_to_R % 10;
	while (placeholder > 0)
		if (placeholder < 4)
		{
			num_Roman.push_back('X');
			length++; placeholder--;
		}
		else
		{
			num_Roman.push_back('X');
			num_Roman.push_back('L');
			placeholder = 0;
			length += 2;
		}

	//V
	placeholder = num_to_R / 5;
	num_to_R = num_to_R % 5;
	while (placeholder > 0)
	{
		if (num_to_R < 4)
		{
			num_Roman.push_back('V');
			length++; placeholder--;
		}
		else
		{
			num_Roman.push_back('I');
			num_Roman.push_back('X');
			placeholder = 0;
			length += 2;
			num_to_R = 0;
		}
	}

	//I
	placeholder = num_to_R / 1;
	while (placeholder > 0)
	{
		if (placeholder < 4)
		{
			num_Roman.push_back('I');
			length++; placeholder--;
		}
		else 
		{
			num_Roman.push_back('I');
			num_Roman.push_back('V');
			placeholder = 0;
			length += 2;
		}
	}

	//read out the resultant Roman Numeral
	cout << endl << endl << "The equivalent Roman numeral is:" << endl << endl;
	for (int a = 0; a < length; a++)
	{
		cout << num_Roman[a];
	}
	cout << endl << endl;
	return;
}
