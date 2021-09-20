//问题描述
//小 L 喜欢喝酸奶，春天来了，小 L 想把酸奶种在地里，等到来年春暖花开，就能长出好多好多酸奶了
//有 n 个坑，小 L 给坑都编上号，从 1 号到 n 号，每个坑最多种一瓶酸奶。
//但是有一些限制形如 k, a, b, c。
//若 k 等于 1 ，则第 a 号坑到第 b 号坑最多种 c 瓶酸奶。
//若 k 等于 2 ，则第 a 号坑到第 b 号坑最少种 c 瓶酸奶。
//若 k 等于 3 ，则第 a 号坑到第 b 号坑必须种少于 c 瓶酸奶。
//若 k 等于 4 ，则第 a 号坑到第 b 号坑必须种多于 c 瓶酸奶。
//若 k 等于 5 ，则第 a 号坑到第 b 号坑必须种等于 c 瓶酸奶。
//
//问小 L 最多种多少瓶酸奶
//
//输入格式
//第一行两个整数 n, m ，表示有 n 个坑，有 m 条限制。
//1≤n, m≤1000
//接下来 m 行，每行四个整数 k, a, b, c
//1≤k≤5 ， 1≤a≤b≤n,∣c∣ <= 2000
//
//输出格式
//输出一行，若有解则输出一个整数，表示答案
//否则输出 impossible
//
//样例输入
//5 5
//1 1 4 4
//2 2 5 1
//3 2 4 2
//4 1 5 2
//5 1 3 2
//
//样例输出
//3

#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

struct Edge {
	int v, w, next;
}edge[20100];

int head[20100], vis[20100], dis[20100], cnt[20100];
int tot;

void add(int x, int y, int z) {
	edge[tot].v = y;
	edge[tot].w = z;
	edge[tot].next = head[x];
	head[x] = tot++;
}

int main()
{
	int n, m, k, a, b, c;
	cin >> n >> m;
	tot = 0;
	memset(head, -1, sizeof(head));
	memset(dis, INF, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < m; i++) {
		cin >> k >> a >> b >> c;
		if (k == 1) {
			add(a - 1, b, c);
		}
		else if (k == 2) {
			add(b, a - 1, -c);
		}
		else if (k == 3) {
			add(a - 1, b, c - 1);
		}
		else if (k == 4) {
			add(b, a - 1, -c - 1);
		}
		else if (k == 5) {
			add(a - 1, b, c);
			add(b, a - 1, -c);
		}
	}
	for (int i = 0; i < n; i++) {
		add(i, i + 1, 1);
		add(i + 1, i, 0);
	}
	//spfa
	dis[0] = 0;
	vis[0] = 1;
	queue<int> q;
	q.push(0);
	int flag = 0;
	int now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		vis[now] = 0;
		for (int i = head[now]; i != -1; i = edge[i].next) {
			if (dis[edge[i].v] > dis[now] + edge[i].w) {
				dis[edge[i].v] = dis[now] + edge[i].w;
				cnt[edge[i].v] = cnt[now] + 1;
				if (cnt[edge[i].v] >= n) {
					flag = 1;
					break;
				}
				if (vis[edge[i].v] == 0) {
					vis[edge[i].v] = 1;
					q.push(edge[i].v);
				}
			}
		}
		if (flag == 1) {
			break;
		}
	}
	if (flag == 1) {
		cout << "impossible" << endl;
	}
	else {
		cout << dis[n] << endl;
	}
	return 0;

}