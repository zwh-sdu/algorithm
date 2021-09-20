//问题描述
//有N种物品（每种有无限多个）和一个容量为V的背包。第i种物品的重量是w[i]，价值是c[i]。
//求解将哪些物品装入背包可使这些物品的重量总和不超过背包容量，且价值总和最大。
//
//样例输入
//10 8
//4 5
//1 1
//1 5
//5 4
//5 10
//6 5
//1 1
//5 6
//7 4
//4 5
//
//样例输出
//40

#include <bits/stdc++.h>
using namespace std;

int N, V;
int w[5005], v[5005], f[5005];

int main()
{
	cin >> N >> V;
	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= V; j++) {
			if (j >= w[i]) {
				f[j] = max(f[j], f[j - w[i]] + v[i]);
			}
		}
	}
	cout << f[V] << endl;
	return 0;
}