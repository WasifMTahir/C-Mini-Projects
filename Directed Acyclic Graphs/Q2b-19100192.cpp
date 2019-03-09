/*
The algorithm takes O(n+m) time complexity and O(n) space complexity since it goes through all
the nodes and all of their edges twice making it n+2m which is O(n+m) and stores only the nodes
once each so O(n) space.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void task2a(string text);

int main()
{
	task2a("Q2btest.txt");
}

void task2a(string text)
{
	int size = 1;
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
		list[temp1]++;
		nodes[cursor].push_back(temp1);
	}
	temp = size;
	vector<int> stack;
	for(int i=0;i<size;i++)
	{
		if(list[i] == 0)
			{
				list[i]--;
				temp--;
				stack.push_back(i);
				
			}
	}
	vector<vector<int> >final;
	vector<int> returnVector;
	int current;
	while(temp >= 0)
	{
		if(stack.size() == 0)
		{
			cout<<"This graph is NOT a DAG" << endl;
			in.close();
			return;
		}
		vector<int> tempStack;
		for(int i=0; i<stack.size(); i++)
		{
			current = stack[i];
			for(int j=0; j<nodes[current].size(); j++)
			{
				list[nodes[current][j]]--;
				if(list[nodes[current][j]] == 0)
				{
					tempStack.push_back(nodes[current][j]);
				}
			}
			returnVector.push_back(current);
			temp--;
		}
		final.push_back(returnVector);
		for (int i=0; i<returnVector.size(); i++)
			returnVector.pop_back();
		stack = tempStack;
	}
	cout << "The DAG formation is: " << endl;
	for(int i=0; i<final.size(); i++)
	{
		cout<<"R"<<i<<" = ";
		for(int j=0; j<final[i].size(); j++)
			cout  << final[i][j] << " ";	
		cout << endl;
	}
	cout << "Rows required: " << final.size();
	in.close();
}
