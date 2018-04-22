#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
//#include<vector>
//#include<algorithm>

using namespace std;
int mini(int a, int b, int c)
{
	int temp, min;
	temp = (a <= b ? a : b);
	min = (temp <= c ? temp : c);
	return min;
}
int editdist(string a, string b)
{
	int na = a.size();
	int nb = b.size();
	int **mat = new int *[na + 1];
	for (int i = 0; i != na + 1; i++)
	{
		mat[i] = new int[nb + 1];
	}
	// ¶¯Ì¬¹æ»® 
	mat[0][0] = 0;
	int p, q;
	for (p = 1; p != na + 1; p++)
	{
		mat[p][0] = p;
	}
	for (q = 1; q != nb + 1; q++)
	{
		mat[0][q] = q;
	}
	for (int j = 1; j != na + 1; j++)
	{
		for (int k = 1; k != nb + 1; k++)
		{
			int Fjk = 0;
			if (a[j - 1] != b[k - 1])
			{
				Fjk = 1;
			}
			mat[j][k] = mini(mat[j - 1][k] + 1, mat[j][k - 1] + 1, mat[j - 1][k - 1] + Fjk);
		}
	}
	int  nEditDis = mat[na][nb];
	for (int m = 0; m != na + 1; m++)
	{
		delete[] mat[m];
	}
	delete[] mat;


	return  nEditDis;
}

int main()
{
	int n;
	string a;
	string b;
	ifstream indata("input.txt");
	indata >> a>>b;
	//cin >> a >> b;
	n = editdist(a, b);
	//cout << n;

	ofstream outdata("output.txt");
	outdata << n;
	outdata.close();
	system("pause");
	return 0;
}