/*This program can translate Roman numerals to the Arabic system
	and vice versa. It begins with the option of Roman to Arabic
	or arabic to roman and then allows the user to translate
	a number or numeral. In order to translate in the 
	reverse, the user must restart the program.*/

#include <iostream>
#include <vector>

using namespace std;

//function prototypes
bool RtoA_OR_AtoR(void);	//Decision on Roman to Arabic or vice versa.
void RtoA(void);			//Goes from Roman to Arabic numerical systems.
void AtoR(void);			//Goes from Arabic to Roman numerical systems.

int main()
{
	bool R_to_A = 0;			//Variable for Roman or Arabic conversion.
	R_to_A = RtoA_OR_AtoR();	//Decision on Roman to Arabic or vice versa.
	if (R_to_A)
	{
		RtoA();
	}
	else
	{
		AtoR();
	}

	//terminate the program.
	int out;					//This variable is just a placeholder so that the program will not terminate until the user wants it to.
	cout << "type a number and press enter to terminate the program.";
	cin >> out;
	return 0;					//end program.
}

bool RtoA_OR_AtoR(void)		//Decision on Roman to Arabic or vice versa.
{
	cout << "Would you like to convert a Roman numeral number" << endl;
	cout << "to the Arabic System (type 1 and then 'Enter') or" << endl;
	cout << "would you like to do the opposite (type 0 and then 'Enter')?" << endl;
	bool RtoA = 0;				//Variable for Roman or Arabic conversion.
	cin >> RtoA;				//user decision.
	cout << endl << endl;
	return RtoA;
}
