/*
The algorithm uses a min heap based priority queue to sort all programs according to their sizes in O(nlog(n)) total time and O(n) space
Then starting from the smallest program it starts to insert it in the USB until the space runs out
*/

#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

int main()
{
	int size;
	cout << "USB size: ";
	cin >> size;
	int usb[size];
	priority_queue<int, vector<int>, greater<int> > prog;
	int element;
	for (int i=0; i<size/10; i++)
	{
		element = rand() % 100 + 1;
		prog.push(element);
	}
	int num = 0;
	while (1)
	{
		element = prog.top();
		if (size-element >= 0)
		{
			size-=element;
			num++;
		}
		else
		{
			break;
		}
		prog.pop();
	}
	cout << "The USB was able to store " << num << " programs" << endl;
	return 0;
}
