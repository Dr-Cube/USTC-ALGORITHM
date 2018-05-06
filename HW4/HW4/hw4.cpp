//hw4
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int greedy(int)
{
	return 0;
}
bool complare(int a, int b)
{
	return a>b;
}

int main()
{
	int n;
	cin >> n;
	double p[1000];
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		sum += p[i];
	}

	for (int i = 0; i < n; i++)
	{
		p[i] = p[i] / sum;
		//cout << p[i];
	}
	sort(p, p + n, complare);

	system("pause");
	return 0;
}