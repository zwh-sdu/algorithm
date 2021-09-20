//问题描述
//有N种物品和一个容量为V的背包。第i种物品的重量是w[i]，价值是c[i]，有k[i]个。
//求解将哪些物品装入背包可使这些物品的重量总和不超过背包容量，且价值总和最大。
//
//样例输入
//6 1
//7 10 4
//6 9 1
//6 8 1
//10 6 2
//9 8 3
//1 3 2
//
//样例输出
//3

#include <bits/stdc++.h>
using namespace std;

long long w[10005], c[10005], v[10005], f[10005], ww[100005], vv[100005];
int N, V;

int main()
{
	cin >> N >> V;
	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i] >> c[i];
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int t = c[i];
		for (int k = 1; k <= t; k <<= 1) {
			cnt++;
			vv[cnt] = k * v[i];
			ww[cnt] = k * w[i];
			t -= k;
		}
		if (t > 0) {
			cnt++;
			vv[cnt] = t * v[i];
			ww[cnt] = t * w[i];
		}
	}
	for (int i = 1; i <= cnt; i++) {
		for (int k = V; k >= 0; k--) {
			if (k >= ww[i]) {
				f[k] = max(f[k], f[k - ww[i]] + vv[i]);
			}
		}
	}
	cout << f[V] << endl;
	return 0;
}