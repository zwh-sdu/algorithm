//问题描述
//有N件物品和一个容量为V的背包。第i件物品的重量是w[i]，价值是c[i]。
//求解将哪些物品装入背包可使这些物品的重量总和不超过背包容量，且价值总和最大。
//
//输入描述
//第一行为N(1≤N≤40)，V(1≤V≤10^ { 15 })
//
//样例输入
//3 225274242
//70498827 830583485
//72910089 759360759
//80945586 1095298545
//
//样例输出
//2685242789

#include <bits/stdc++.h>
typedef long long ll;
const ll INF = 1e6;
using namespace std;

int N;
ll w[4500], v[4500];
ll W;
pair <ll, ll> ps[1000000];

int main()
{
	cin >> N >> W;
	for (int i = 0; i < N; i++) {
		cin >> w[i] >> v[i];
	}
	//枚举前半部分
	int n = N / 2;
	for (int i = 0; i < 1 << n; i++) {
		ll sw = 0;
		ll sv = 0;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				sw += w[j];
				sv += v[j];
			}
		}
		ps[i] = make_pair(sw, sv);
	}
	//去除多余元素
	sort(ps, ps + (1 << n));
	int m = 1;
	for (int i = 1; i < 1 << n; i++) {
		if (ps[m - 1].second < ps[i].second) {
			ps[m++] = ps[i];
		}
	}
	//枚举后半部分并求解
	ll ans = 0;
	for (int i = 0; i < 1 << (N - n); i++) {
		ll sw = 0;
		ll sv = 0;
		for (int j = 0; j < N - n; j++) {
			if (i >> j & 1) {
				sw += w[n + j];
				sv += v[n + j];
			}
		}
		if (sw <= W) {
			ll tv = (lower_bound(ps, ps + m, make_pair(W - sw, INF)) - 1)->second;
			ans = max(ans, sv + tv);
		}
	}
	cout << ans << endl;
	return 0;
}