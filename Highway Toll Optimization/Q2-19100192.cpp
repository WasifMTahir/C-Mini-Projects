/*
The complexity of this algorithm is O(n) as we only need to access the values of the two n-sized arrays at most twice. So 2(2n)=4n total operations.
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
	int size;
	string in;
	ifstream read;
	read.open("Task2.txt");
	read >> in;
	size = atoi(in.c_str());
	int Revh[size];
	int Revl[size];
	int total[size];
	int selection[size];
	for (int i=0; i<size; i++)
	{
		read >> in;
		Revh[i] = atoi(in.c_str());
	}
	for (int i=0; i<size; i++)
	{
		read >> in;
		Revl[i] = atoi(in.c_str());
	}
	if (Revh[0] > Revl[0])
	{
		total[0] = Revh[0];
		selection[0] = 1;
	}
	else
	{
		total[0] = Revl[0];
		selection[0] = 0;
	}
	if (Revh[1] > Revl[1] + total[0])
	{
		total[1] = Revh[1];
		selection[1] = 1;
	}
	else
	{
		total[1] = Revl[1] + total[0];
		selection[1] = 0;
	}
	int flag=0;
	for (int i=2; i<size; i++)
	{
		if (Revh[i] + total[i-2] > Revl[i] + total[i-1])
		{
			total[i] = Revh[i] + total[i-2];
			selection[i] = 1;
			if (flag==1)
				selection[i-1] = -1;
			flag++;
		}
		else
		{
			total[i] = Revl[i] + total[i-1];
			selection[i] = 0;
			if (flag>0)
				flag--;
		}
	}
	for (int i=0; i<size; i++)
	{
		if (selection[i] == 1)
			cout << "RevH, ";
		else if (selection[i] == 0)
			cout << "RevL, ";
		else
			cout << "Skipped, ";
	}
	cout << endl << "Revenue = " << total[size-1] << endl;
	return 0;
}
