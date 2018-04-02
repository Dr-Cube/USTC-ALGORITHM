//整数因子分解问题
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

//递归
int solve(int n) {
	if (n == 1) return 1;

	int cnt = 1;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			
			if (i == sqrt(n)) cnt += solve(i);
			else cnt += solve(n / i) + solve(i);
		}
		
	}

	return cnt;
}

int* num;
int length;

// 备忘录
int lookup(int n) {
	if (n < length && num[n] != 0) {
		return num[n];
	}

	int cnt = 1;
	int q = sqrt(n);

	for (int i = q; i >= 2; i--) {
		if (n % i == 0) {
			if (i == sqrt(n)) {
				cnt += lookup(i);
			}
			else {
				cnt += lookup(i) + lookup(n / i);
			}
		}
	}

	if (n < length) {
		num[n] = cnt;
	}
	return cnt;
}

int main()
{
	int n;
	//ifstream indata("input.txt");
	//indata >> n;
	cin >> n;
	int q = sqrt(n);
	length = q + 1;
	num = new int[length];


	memset(num, 0, length * sizeof(int));
	

	cout << "纯递归方法："<<solve(n) << endl;//纯递归法  此方法太慢
	cout << "备忘录方法：" << lookup(n) << endl;//备忘录法  

	//ofstream outdata("output.txt");
	//outdata << solve(n);
	//outdata << lookup(n);
	//outdata.close();


	system("pause");
	return 0;
}
