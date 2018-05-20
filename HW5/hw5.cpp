#include<iostream>
#include<fstream>
using namespace std;
int **board;
int cnt = 0;
int s, t;
int m, n;

void swap(int &a, int &b)//没有引用的话输入的数值
{
	int p;
	p = a;
	a = b;
	b = p;
}
int OK(int**board, int s, int t)
{
	for (int k = 1; k<s; k++)
		for (int j = 1; j <= n; j++)
			if (board[k][j] == board[s][j]) return 0;
	return 1;
}
void Backtrack(int s, int t)
{
	int j;
	if (s>m)
	{
		cnt++;
		return;
	}

	if (t>n)
	{
		if (OK(board, s, t))
			Backtrack(s + 1, 1);
	}
	for (int j = t; j <= n; j++)
	{
		swap(board[s][j], board[s][t]);
		Backtrack(s, t + 1);
		swap(board[s][j], board[s][t]);
	}
}
int main()
{
	ifstream indata("input.txt");
	indata >> m>>n;
	//cin >> n >> m;
	board = new int*[m + 1];
	for (int i = 0; i <= m; i++)
		board[i] = new int[n + 1];
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++)
			board[i][j] = j;
	Backtrack(1, 1);
	//cout << cnt << endl;
	ofstream outdata("output.txt");
	outdata << cnt;
	outdata.close();
	system("pause");
	return 0;
}