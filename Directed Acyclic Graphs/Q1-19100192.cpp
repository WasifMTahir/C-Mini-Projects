/*
The algorithm takes O(n+m) time complexity and O(n) space complexity since it goes through all
the nodes and all of their edges twice making it n+2m which is O(n+m) and stores only the nodes
once each so O(n) space.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

void task1(string text);

void task1(string text)
{
	int size = 0;
	vector< vector<int> > nodes;
	vector<int> k;
	string input;
	int cursor = 0;
	int temp = 0;
	int temp1 = 0;
	ifstream in;
	in.open(text.c_str());
	string str;
	in >> str;
	in >> str;
	size = atoi(str.c_str());
	int list[size];
	for(int i=0;i<size;i++)
	{
		list[i] = 0;
		nodes.push_back(k);
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
		input = input.substr(1,input.length()-1);
		temp1 = atoi(input.c_str());
		nodes[cursor].push_back(temp1);
	}
	for(int i=0; i<size; i++)
	{	
		if(list[i] != 0)
		{
			for(int j=0; j<nodes[i].size(); j++)
			{
				if(list[i] == 1 && list[nodes[i][j]] == 0)
				{
					list[nodes[i][j]] = 2;
				}
				else
				{
					list[nodes[i][j]] = 1;
				}
				if(list[nodes[i][j]] == list[i])
				{
					cout << "Graph cannot be represented as Bipartite" << endl;
					return;
				}
			}
		}
		else
		{
			for(int j=0; j<nodes[i].size(); j++)
			{
				if(list[nodes[i][j]] == 1 && list[nodes[i][j]] != 0)
				{
					list[i] = 2;
					break;
				}
				else
				{
					list[i] = 1;
					break;
				}
			}
			if(list[i] == 0)
			{
				list[i] = 1;
			}
		}
	}
	for(int i=0;i<size;i++)
	{
		cout << "C" << i << " in " << list[i] << endl;
	}
	return;
	
}



int main()
{
	task1("Q1test.txt");
}
