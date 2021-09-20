//问题描述
//你现在是城市的主人
//现在有 n 个村庄，要修建 m 条路，每修建一条路，道路是双向的，输出至少还需要修建几条，可以让所有村庄互相可达。
//一开始路为 0 条
//数据保证有解
//
//输入格式
//第一行两个整数 n, m
//接下来有 m 行，每行 a, b 代表修建了一条从第 a 个村庄，到第 b 个村庄的路。
//a 和 b 可能相同。
//
//输出格式
//一共 m 行，第 i 个数代表已经修建了前 i 条路时，最少还需要修建几条，可以让所有村庄互相可达。
//
//样例输入
// 5 5
// 1 1
// 1 2
// 2 3
// 4 4
// 1 2
//
//样例输出
//4
//3
//2
//2
//2

#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
int pre[N], ans;
void init(int n)
{
	for (int i = 0; i < n; i++) {
		pre[i] = i;
	}
}
int find(int x)
{
	if (pre[x] == x) {
		return x;
	}
	return pre[x] = find(pre[x]);
}
bool join(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return false;
	pre[x] = y;
	ans--;
	return true;
}

int main()
{
	int n, m;
	cin >> n >> m;
	init(n);
	ans = n - 1;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		join(a, b);

		cout << ans << "\n";
	}
	return 0;
}