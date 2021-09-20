//问题描述
//你现在是城市的主人
//现在有 n 个村庄，已经修建了 n - 1 条道路，使得各个村庄作为节点，路作为边，构成一棵树。
//假设第 a 个村庄到第 b 个村庄有路相连，则从 a 走到 b 或者从 b 走到 a 需要走 1m 。
//你需要输出 n 个数，第 i 个数代表从第 i 个村庄出发，距离他最远的村庄的距离
//
//输入格式
//第一行一个整数 n,
//接下来有 n - 1 行，每行 a, b 代表第 a 个村庄，到第 b 个村庄有一条路。
//
//输出格式
//输出一行n个数，表示答案
//
//样例输入
//5
//5 1
//1 2
//2 3
//3 4
//
//样例输出
//3 2 3 4 4

#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int head[N], vis[N], d1[N], d2[N], tot, maxv;
struct Edge {
	int to, w, next;
}edges[2 * N];

void add(int u, int v, int w) {
	edges[tot] = { v,w,head[u] };
	head[u] = tot++;
}

void dfs(int u, int depth, int* d) {
	d[u] = depth;
	vis[u] = 1;
	if (d[maxv] < d[u]) maxv = u;
	for (int e = head[u]; e != -1; e = edges[e].next) {
		int v = edges[e].to, w = edges[e].w;
		if (vis[v] == 1) {
			continue;
		}
		dfs(v, depth + w, d);
	}
}

int main()
{
	int n;
	cin >> n;
	memset(head, -1, sizeof(head));
	tot = 0;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		add(a, b, 1);
		add(b, a, 1);
	}
	memset(vis, 0, sizeof(vis));
	d1[maxv] = 0;
	dfs(1, 0, d1);
	memset(vis, 0, sizeof(vis));
	d1[maxv] = 0;
	dfs(maxv, 0, d1);
	memset(vis, 0, sizeof(vis));
	d2[maxv] = 0;
	dfs(maxv, 0, d2);

	for (int i = 1; i <= n; i++) {
		cout << max(d1[i], d2[i]) << " ";
	}
	return 0;
}