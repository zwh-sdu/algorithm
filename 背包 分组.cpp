//问题描述
//有N件物品和一个容量为V的背包，将所有的物品划分成若干组，每个组里面的物品最多选一件。
//第i件物品的重量是w[i]，价值是c[i]，属于组k[i]。
//求解将哪些物品装入背包可使这些物品的重量总和不超过背包容量，且价值总和最大。
//
//样例输入
//7 9
//6 6 3
//5 10 3
//3 5 1
//9 4 4
//6 1 4
//8 3 5
//5 2 2
//
//样例输出
//15

#include <bits/stdc++.h>
using namespace std;

vector<int> ve[1005];
int w[1005], v[1005], f[1005];
int N, V, maxt;

int main()
{
	cin >> N >> V;
	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
		int p;
		cin >> p;
		maxt = max(maxt, p);
		ve[p].push_back(i);
	}
	for (int k = 1; k <= maxt; k++) {
		for (int i = V; i >= 0; i--) {
			for (int j = 0; j < ve[k].size(); j++) {
				if (i >= w[ve[k][j]]) {
					f[i] = max(f[i], f[i - w[ve[k][j]]] + v[ve[k][j]]);
				}
			}
		}
	}
	cout << f[V] << endl;
	return 0;
}