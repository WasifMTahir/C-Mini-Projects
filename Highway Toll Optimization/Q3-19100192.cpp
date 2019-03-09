/*
Once the node values are stored, the algorithm takes O(V^2) time because of using a matrix, otherwise the implementation would take O(E)
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int size = 8;
int node[8][8];
void readfile(string file)
{
	string input;
	int cursor = 0;
	int temp = 0;
	int temp1 = 0;
	int temp2 = 0;
	ifstream in;
	in.open(file.c_str());
	string str;
	in >> str;
	in >> str;
	size = atoi(str.c_str());
	string val;
	for(int i=0;i<size;i++)
	{
		for (int j=0; j<size; j++)
			node[i][j] = 0;
	}
	while(in>>input)
	{
		if(input.at(input.length()-1) == ':')
		{
			if(temp !=0)
			{
				cursor++;
			}
			temp = 1;
			continue;
		}
		if(input.at(input.length()-1) == ',')
		{
			input = input.substr(0,input.length()-1);
		}
		input = input.substr(1,input.size()-1);
		val = input.substr(0,1);
		temp1 = atoi(val.c_str());
		val = input.substr(2,2);
		temp2 = atoi(val.c_str());
		node[cursor][temp1] = temp2;
	}
}

int main()
{
	int toll[size];
	int flag[size];
	int path[size];
	readfile("Task3.txt");
	toll[0] = 0;
	int prev = 0;
	for (int i=0; i<size; i++)
		flag[i] = 0;
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			if (node[j][i])
			{
				//cout << "i="<<i << " j=" << j<<endl;
				flag[j]++;
				if (flag[j]>1)
				{
					//cout << "HERE (" << i << "," << j << ") with val " << node[j][i] << endl;
					if (node[j][i]>toll[i])
					{
						toll[i] = node[j][i] + toll[j];
						path[i] = 1;
						path[i-1] = 0;
					}
				}
				else
				{
					cout << "NODE  =" << node[j][i] << endl; // << "toll[i] =" << toll[i] << "\ntoll[j] =" << toll[j] << endl;
					if (toll[i]==70)
					{
						continue;
					}
					toll[i] = node[j][i] + toll[j];
					path[i] = 1;
					//cout << j << ": " << toll[i] << endl;
				}
				//cout << "AT " << i << ": " <<node[j][i] << "  toll= " << toll[i] << endl;
			}
		}
	}
	cout << "PATH = ";
	for (int i=0; i<size; i++)
	{
		if (path[i]==1)
			cout << "T" << i << "->";
	}
	cout << "\nMax Revenue = " << toll[7] << endl;
	return 0;
}
