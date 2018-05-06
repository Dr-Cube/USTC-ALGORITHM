//hw4
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;
bool complare(int a, int b) //sort()的第三个参数
{
	return a>b;
}
int cmp(const void *a, const void *b) {
	return *(double *)a - *(double *)b;
}
double greedy(double p[], int n)
{
	//sort(p, p + n, cmp);// complare); //sort默认小到大，要加第三个参数
	qsort(p, n, sizeof(double), cmp);
	int mid = (n - 1) / 2; //数组从0开始，所以是n-1
	double pnew[1000];
	double sum = 0, exp = 0;
	pnew[mid] = p[n-1];
	for (int i = mid+1; i < n; i++)
	{
		pnew[i] = p[n - 2 * (i - mid)];
	}
	for (int i = mid - 1; i >= 0; i--)
	{
		pnew[i] = p[n - 2 * (mid - i) - 1];
	}
	for (int i = 0; i < n; i++)
	{
		sum += p[i];
		for (int j = i+1; j < n; j++)
		{
			exp += pnew[i] * pnew[j] * (j - i);
		}
	}
	return exp/sum/sum;
}

int main()
{
	int n;
	//cin >> n;
	ifstream indata("input.txt");
	indata >> n;
	double p[1000];
	//double sum = 0;
	for (int i = 0; i < n; i++)
	{
		indata >> p[i];
		//sum += p[i];
	}
	
	/*for (int i = 0; i < n; i++)
	{
		//p[i] = p[i] / sum;
		cout << p[i];
	}*/
	//cout << greedy(p, n);
	ofstream outdata("output.txt");
	outdata << greedy(p,n);
	outdata.close();
	system("pause");
	return 0;
}