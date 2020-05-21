/*This program organizes a vector of numbers by swapping in a nested for loop*/
#include <vector>
#include <iostream>
using namespace std;

void swap(vector<int>& organizer, int length)
{
	int placeholder = 0;
	for (int i = 0; i < length; i++)
	{
		for (int a = i; a < length; a++)
		{
			if (organizer[i] <= organizer[a])
			{

			}
			else
			{
				placeholder = organizer[i];
				organizer[i] = organizer[a];
				organizer[a] = placeholder;

			}

		}

	}

	return;
}