//问题描述
//给定一个 3 行，n 列的矩阵，我们要在矩阵的每一列选一个数。对于第 i(1≤i≤n) 列，我们令 di为第i列选择的数，
//那么di每两项差的和的最小值是多少
//
//输入格式
//第一行一个整数 n ，描述见上文
//后面三行每行 n 个整数，为矩阵的各个元素
//
//输出格式
//一个整数，题目要求的最小值
//
//样例输入
//5
//5 10 5 4 4
//1 7 8 4 0
//3 4 9 0 3
//
//样例输出
//3

#include<bits/stdc++.h>
using namespace std;

long long a[3][1000003], dp[3][1000003];

int main()
{
	long long n;
	cin >> n;
	for (long long i = 0; i < 3; i++) {
		for (long long j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (long long j = 2; j <= n; j++) {
		for (long long i = 0; i < 3; i++) {
			dp[i][j] = min(min(dp[0][j - 1] + abs(a[i][j] - a[0][j - 1]),
				dp[1][j - 1] + abs(a[i][j] - a[1][j - 1])),
				dp[2][j - 1] + abs(a[i][j] - a[2][j - 1]));
		}
	}
	cout << min(min(dp[0][n], dp[1][n]), dp[2][n]) << endl;
	return 0;

}