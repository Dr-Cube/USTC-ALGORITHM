//最大间隙问题的线性复杂度解法
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

int main()
{
	int n, index;//index为每个cage的索引，即编号
	double cagedist, minx = 0, maxx = 0;
	double x[50];
	//cin >> n;
	
	char a;
	ifstream indata("input.txt");
	//char line[10];
	indata.get(a);
	n = a - '0';
	printf(" %d \n", n);
	//cout << line[0];
	int *count = new int[n];  //实际分到每个cage的数据个数
	double *low = new double[n]; //实际分到每个cage的最小数据
	double *high = new double[n]; //实际分到每个cage的最大数据
	for (int i = 0; i < n; i++)
	{
		indata >> x[i];
		//cout << x[0];
		printf("%f \n", x[i]);
		if (i == 0)
		{
			minx = x[i];
			maxx = x[i];
		}
		if (x[i] >= maxx) maxx = x[i];
		if (x[i] <= minx) minx = x[i];

		count[i] = 0;
		low[i] = maxx;
		high[i] = minx;
	}
	cagedist = (maxx - minx) / (n - 2);
	

	for (int i = 0; i < n; i++)
	{
		index = int((x[i] - minx) / cagedist) + 1;
		if (index == n)
			index--;

		count[index]++;
		if (x[i]<low[index])
			low[index] = x[i];
		if (x[i]>high[index])
			high[index] = x[i];
				
	}
	
	double cageMaxGap = 0, cageup = high[1], TempGap;
	for (int i = 2; i<n; i++)
	{
		if (count[i])
		{
			TempGap = low[i] - cageup;
			if (cageMaxGap<TempGap)
				cageMaxGap = TempGap;
			cageup = high[i];
		}
	}
	printf("%f \n", cageMaxGap);
	//cout << cageMaxGap;
	ofstream outdata("output.txt");
	outdata << cageMaxGap;
	outdata.close();
	//cagedist = int(cagedist);
	//cout << cagedist;
	
	delete [] count;
	count = NULL;
	delete [] low;
	low = NULL;
	delete [] high;
	high = NULL;

	system("pause");
	return 0;
}