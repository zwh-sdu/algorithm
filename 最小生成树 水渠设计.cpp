//问题描述
//你现在是城市的主人
//现在有 n 个田地需要灌溉。
//可以选择修建 m 个引水渠，第 i 条从第 a 个田地到第 b 个田地，花费 c 元。
//现在可以买任意多个抽水机，买一个抽水机需要花费 p 元。如果在一个田地旁边安置一个抽水机，则该田地会被灌溉。
//水可以顺着水渠流动。
//求让每一块田地都能被灌溉的最小花费。
//
//输入格式
//第一行三个整数 n, m, p
//接下来有 m 行，每行 a, b, c 代表修建了一条从第 a 个田地，到第 b 个田地的水渠，花费 c 元。
//
//输出格式
//输出一个数表示答案。
//
//样例输入
//5 5 2
//1 2 1
//2 3 3
//3 4 5
//1 3 2
//1 4 1
//
//样例输出
//8

#include<bits/stdc++.h>
using namespace std;

const int N = 2000010;
struct Node
{
	int a, b, c;
	bool operator < (const Node x) const {
		return c < x.c;
	}
}node[N];

int pre[N];

int find(int x) {
	if (pre[x] == x) {
		return x;
	}
	return pre[x] = find(pre[x]);
}

bool join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	pre[x] = y;
	return true;
}

int main()
{
	int n, m, p;
	cin >> n >> m >> p;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		node[cnt].a = 0;
		node[cnt].b = i;
		node[cnt].c = p;
		pre[i] = i;
		cnt++;
	}
	for (int i = 1; i <= m; i++) {
		cin >> node[cnt].a >> node[cnt].b >> node[cnt].c;
		cnt++;
	}
	sort(node, node + cnt);
	long long ans = 0;
	for (int i = 0; i < cnt; i++) {
		if (join(node[i].a, node[i].b)) {
			ans += node[i].c;
		}
	}
	cout << ans << endl;
	return 0;
}
