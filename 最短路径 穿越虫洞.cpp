//问题描述
//小H有n个秘密基地（编号 1 到 n ）, n 个秘密基地之间有 m 条双向路径和 w 个单向时空隧道，
//通过路径需要消耗一定的时间Ti，而通过时空隧道可以使时光倒流Tj，
//现在小H想知道他能否从某一秘密基地出发，通过路径和时空隧道回到过去（即回到出发的秘密基地且该时刻要早于出发时间）。
//
//输入格式
//第1行，一个整数 F, 表示测试用例的数量
//接下来对于每一个测试用例，输入格式如下
//第1行，三个空格分隔的整数n, m, w
//第2到 m + 1 行，三个空格分隔的数字 s, e, t，表示 s, e 之间存在双向道路，通行需要消耗t，允许两点间存在多条路径
//第m + 2到m + w + 1行三个空间分隔的数字 s, e, t, 表示存在从 s 到 e 的单向时空隧道，穿过时空隧道时光倒流 t
//
//输出格式
//对于每个测试用例，如果小H能回到过去则输出YES，否则输出NO
//每个测试用例的输出占一行
//
//样例输入
//2
//3 3 1
//1 2 2
//1 3 4
//2 3 1
//3 1 3
//3 2 1
//1 2 3
//2 3 4
//3 1 8
//
//样例输出
//NO
//YES

#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

const int mm = 60210;
int tot = 0;
int dis[mm], head[mm], can[mm], cnt[mm];

struct Edge
{
	int y, z, next;
}edge[mm];

void add(int x, int y, int z) {
	edge[tot].y = y;
	edge[tot].z = z;
	edge[tot].next = head[x];
	head[x] = tot++;
}

int main()
{
	int f;
	cin >> f;
	while (f--) {
		int n, m, w0;
		cin >> n >> m >> w0;
		tot = 0;
		memset(head, -1, sizeof(head));
		memset(dis, INF, sizeof(dis));
		memset(can, 0, sizeof(can));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			add(x, y, z);
			add(y, x, z);
		}
		for (int i = 1; i <= w0; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			add(x, y, -z);
		}
		//spfa
		dis[1] = 0;
		can[1] = 1;
		queue<int> q;
		q.push(1);
		int flag = 0;
		int now;
		while (!q.empty()) {
			now = q.front();
			q.pop();
			for (int i = head[now]; i != -1; i = edge[i].next) {
				if (dis[edge[i].y] > dis[now] + edge[i].z) {
					dis[edge[i].y] = dis[now] + edge[i].z;
					cnt[edge[i].y] = cnt[now] + 1;
					if (cnt[edge[i].y] >= n) {
						flag = 1;
						break;
					}
					if (can[edge[i].y] == 0) {
						can[edge[i].y] = 1;
						q.push(edge[i].y);
					}
				}
			}
			can[now] = 0;
			if (flag == 1) {
				break;
			}
		}
		if (flag == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}