/*
The algorithm uses O(V^2) time and space to run Prim's implementation to find the MST on matrix
*/

#include <iostream>
#include <queue>
#include <stdlib.h>
#include <fstream>
using namespace std;

void readfile(string file);
void task4();
int size = 5;
int node[5][5];

int main()
{
	readfile("Q4test.txt");
	task4();
	return 0;
}

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
			node[i][j] = 1000;
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
		val = input.substr(2,1);
		temp2 = atoi(val.c_str());
		node[cursor][temp1] = temp2;
	}
}

void task4()
{
	int mst[size];
	bool visited[size];
	int cost[size];
	
	for (int i=0; i<size; i++)
	{
		cost[i] = 1000;
	}
	mst[0] = -1;
	cost[0] = 0;
	for (int i=0; i<size; i++)
	{
		int vertex = 0;
		for (int j=0; j<size; j++)
		{
			if (!visited[i] && cost[j] < 1000)
				vertex = i;
		}
		visited[vertex] = 1;
		for (int j=0; j<size; j++)
		{
			if (!visited[j] && cost[j]>node[vertex][j])
			{
				cost[j] = node[vertex][j];
				mst[j] = vertex;
			}
			//cout << mst[j] << " ";
		}
		//cout << endl;
	}
	int edge;
	cout << "Delete which edge: ";
	cin >> edge;
	if (mst[edge]<0)
		cout << "T2 cannot be constructed" << endl;
	else
		cout << "T2 is possible" << endl;
}
