//问题描述
//给定 n 个数，我们要从中选出多若干个数，其中任意大小不同的两数差的绝对值不能为 1，那么选出的数之和最大是多少。
//
//输入格式
//第一行一个整数 n 。
//第二行 n 个整数，a_1, a_2, ..., a_n ，表示这 n 个数
//
//输出格式
//一个整数，选出的数的和的最大值
//
//样例输入
//5
//1 1 3 2 3
//
//样例输出
//8

#include<bits/stdc++.h>
using namespace std;

long long a[1000003], dp[1000003];

int main()
{
	int n, t, maxx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a[t] += t;
		maxx = max(maxx, t);
	}
	dp[1] = a[1];
	for (int i = 2; i <= maxx; i++) {
		dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
	}
	cout << dp[maxx] << endl;
	return 0;
}