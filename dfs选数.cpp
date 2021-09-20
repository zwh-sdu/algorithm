//问题描述
//已知n个整数x1，x2。。。xn和一个整数k。从n个整数中任选k个整数相加，可分别得到一系列的和。
//现在，要求你计算出和为素数共有多少种。
//
//输入格式
//输入包含两行
//第一行两个数n, k
//第二行n个数依次表示xi
//
//输出格式
//一个整数，表示合法的组合数
//
//样例输入
//4 3
//3 7 12 19
//
//样例输出
//1

#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstring>
#include<algorithm>
using namespace std;

int a[5000001];
int vis[5000001];
int n, k, ans = 0;

bool isprime(int n)
{
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

void dfs(int num, int sum, int x) {
	if (num == k) {
		if (isprime(sum)) {
			ans++;
		}
	}
	else {
		for (int i = x; i < n; i++) {
			dfs(num + 1, sum + a[i], i + 1);
		}
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(vis, 0, sizeof(vis));
	dfs(0, 0, 0);
	cout << ans << endl;
	return 0;
}

