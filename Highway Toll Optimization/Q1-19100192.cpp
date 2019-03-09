#include <iostream>
using namespace std;

int main()
{
	string x,y,z;
	int s1 = 0;
	int s2 = 0;
	int num = 0;
	cout << "Enter String-1: ";
	cin >> x;
	cout << "Enter String-2: ";
	cin >> y;
	cout << "Enter String-3: ";
	cin >> z;
	num = z.size();
	if (num != (x.size()+y.size()))
	{
		cout << "Unmatched string sizes" << endl;
		return 0;
	}
	for (int i=0; i<num; i++)
	{
			if (x[s1] == z[i])
				s1++;
			else if (y[s2] == z[i])
				s2++;
			else
			{
				cout << "NOT Interleaved" << endl;
				return 0;
			}
	}
	cout << "Is Interleaved" << endl;
	return 0;
}
