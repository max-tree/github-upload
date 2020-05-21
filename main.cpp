#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
void swap(vector<int> & organizer, int length);


int main()
{
	//create a file
	//ofstream newfile;
	//newfile.open("Example.txt");
	//newfile << "Hello World";
	//newfile.close();
	//Read a file with random numbers.
	ifstream file;
	vector<int> nums_from_file;
	int num = 0, length = 0;
	string NUM;
	file.open("Random_num.txt");
	if (file.is_open())
	{
		while (getline(file, NUM))
		{
			num = stoi(NUM);
			nums_from_file.push_back(num);
			length++;
		}
	}
	else
	{
		cout << "file not found...";
	}
	file.close();

	swap(nums_from_file, length);

	//print out the result
	for (int i = 0; i < length; i++)
	{
		cout << nums_from_file[i] << endl;
	}
	int out;
	cout << "Press any number and hit 'Enter' to terminate the program." << endl;
	cin >> out;
	return 0;
}