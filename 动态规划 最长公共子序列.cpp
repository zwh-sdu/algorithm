//问题描述
//给定序列 A = (a_1, a_2, , a_n)和 B = (b_1, b_2, , b_m)，求它们的最长公共子序列
//
//样例输入
//5 5
//3 2 1 4 5
//1 2 3 4 5
//
//样例输出
//3

#include<bits/stdc++.h>
using namespace std;

int f[5001][5001];
int a[5001], b[5001];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				f[i][j] = f[i - 1][j - 1] + 1;
			}
			else {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}