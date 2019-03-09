/*
The algorithm uses Djikstra's implementation for finding the shortest path from home to all other cities in O(V^2) time
It uses O(V^2) space for storing the adjacency matrix of the edges
*/

#include <iostream>
#include <queue>
#include <stdlib.h>
#include <fstream>
using namespace std;

void readfile(string file);
int task3(int home, int dest);
int size = 5;
int node[5][5];
int main()
{
	readfile("Q3test.txt");
	int home,dest,scene;
	cout << "Enter Home City: ";
	cin >> home;
	cout << "Enter Friend's City: ";
	cin >> dest;
	cout << "Enter Scenic Spot: ";
	cin >> scene;
	int path1 = task3(home, dest);
	int path2 = task3(home, scene) + task3(scene, dest);
	int extra = (((float)path2/(float)path1)*100)-100;
	if (extra>1000 || extra<0)
	{
		cout << "Path is Disconnected" << endl;
		return 0;
	}
	cout << "Home to Friend's City costs " << path1 << endl;
	cout << "Stopping at Scenic spot costs " << path2 << endl;
	cout << "Difference in distance is " << extra << "% extra" << endl;
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

int task3(int home, int dest)
{
	vector<int> path(size);
	vector<bool> visited(size);
	for (int i=0; i<size; i++)
		path[i] = 1000;
	path[home] = 0;
	for (int i=0; i<size; i++)
	{
		int vertex = -1;
		for (int j=0; j<size; j++)
		{
			if (visited[j] == 1)
				continue;
			if (vertex == -1 || path[j] < path[vertex])
				vertex = j;
		}
		visited[vertex] = 1;
		for (int k=0; k<size; k++)
		{
			if (path[k] > (path[vertex] + node[vertex][k]))
				path[k] = path[vertex] + node[vertex][k];
		}
	}
	if (path[dest]==1000)
	{
		return 0;
	}
	return path[dest];
}
