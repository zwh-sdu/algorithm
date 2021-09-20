//问题描述
//有一列长度为 n 的数，初始值都是 1 。
//有 m 次操作，每次对属于区间[l, r] 的数都乘上一个数 c^ b，最后输出这 n 个数的最大公约数。
//
//输入格式
//第一行一个整数 n, n <= 10 ^ 5
//第二行，一个整数 m, m <= 10 ^ 5
//接下来的 m 行，每行四个整数表示 l, r, c, b
//
//输出格式
//一行，一个数，代表最大公约数，答案对 10 ^ 9 + 7取模。
//
//样例输入
//5
//3
//1 4 3 2
//2 4 2 2
//3 5 6 1
//
//样例输出
//3

#include<bits/stdc++.h>
using namespace std;

long long qpow(long long a, long long b, long long p) {
	long long ans = 1;
	for (a %= p; b; a = a * a % p, b >>= 1) {
		if (b & 1) {
			ans = ans * a % p;
		}
	}
	return ans;
}

map<int, long long> mp;
void get(int n)					//寻找n的质因数
{
	for (int i = 2; i <= n; i++)
	{
		while (n % i == 0)
		{
			mp[i]++;
			n /= i;
		}
	}
}

long long power(long long base, unsigned int n)
{
	long long res = 1.0;
	while (n > 0)
	{
		if (n & 1)
			res *= base;
		base *= base;
		n >>= 1;
	}
	return res;
}


int main()
{
	int n, m;
	set<int> a;
	vector<int> b;    //最后结果中包含哪些质数
	cin >> n >> m;
	vector<long long> cb(100, 1000000000000000009);
	vector<vector<long long>> cf(n + 1, vector<long long>(100, 0));
	for (int i = 0; i < m; i++) {
		mp.clear();
		int l, r, c;
		long long b;
		cin >> l >> r >> c >> b;
		get(c);
		for (int j = 0; j < 100; j++) {
			if (!mp.count(j)) {
				continue;
			}
			else {
				cf[l - 1][j] += mp[j] * b;
				cf[r][j] -= mp[j] * b;
				a.insert(j);
			}
		}
	}
	for (auto iter = a.begin(); iter != a.end(); iter++) {
		long long temp = 0;
		for (int i = 0; i < n; i++) {
			temp += cf[i][*iter];
			cb[*iter] = min(cb[*iter], temp);
		}
	}
	//map<int, long long> minx;
	//for (auto iter = a.begin(); iter != a.end(); iter++) {
	//	minx[*iter] = *min_element(cb[*iter].begin(), cb[*iter].end());
	//	if (minx[*iter] == 0) {
	//		minx.erase(*iter);
	//	}
	//	else {
	//		b.push_back(*iter);
	//		//cout << *iter << endl;
	//	}
	//}
	long long ans = 1.0;
	for (auto iter = a.begin(); iter != a.end(); iter++) {
		ans = (ans * qpow(*iter, cb[*iter], power(10, 9) + 7)) % (power(10, 9) + 7);
	}
	cout << ans << endl;
}