#include<iostream>
using namespace std;
class ARRAY
{
	int n;
	int *p;


public:
	ARRAY()
	{
		n = 1;
		p = new int[n];
		cout << "Please enter an array" << endl;
		while (cin >> p[n - 1])
		{
			n++;
		}
		p[n - 1] = 0;
	}



	void print_ARRAY()
	{
		for (int i = 0;i < n - 1;i++)
		{
			cout << p[i] << "  " << endl;
		}
	}
};