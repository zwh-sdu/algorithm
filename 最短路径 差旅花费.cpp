//问题描述
//有n个车站，其中1号车站为始发站，现有n - 1个人，
//你需要安排他们分别去往除始发站以外的n - 1个车站，然后返回始发站。
//交通系统的所有路径均为单向路径，连接两个不同的车站，
//每经过一条路径需要交纳一定的费用，你能求出总花费的最低金额嘛
//
//输入格式
//第一行一个整数T，表示测试用例的个数。
//对于每个测试用例，输入格式如下
//第一行两个整数n, m, 分别表示车站的数量和车站之间的单向路径数。
//接下来m行，每行三个数s, e, c, 表示存在从s到e的单向路径，花费为c
//
//输出格式
//对于每个测试用例，输出其总花费的最低金额，每个测试用例的输出占一行。
//
//样例输入
//2
//2 2
//1 2 13
//2 1 33
//4 6
//1 2 10
//2 1 60
//1 3 20
//3 4 10
//2 4 5
//4 1 50
//
//样例输出
//46
//210

#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

const int mm = 1000005;
int tot;
long long dis1[mm], dis2[mm], head1[mm], head2[mm], can[mm];
struct Edge
{
	int y, z, next;
}edge1[mm], edge2[mm];

void add(int x, int y, int z) {
	edge1[tot].y = y;
	edge1[tot].z = z;
	edge1[tot].next = head1[x];
	head1[x] = tot;

	edge2[tot].y = x;
	edge2[tot].z = z;
	edge2[tot].next = head2[y];
	head2[y] = tot++;
}

void spfa1() {
	dis1[1] = 0;
	can[1] = 1;
	queue<int> q;
	q.push(1);
	int now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = head1[now]; i != -1; i = edge1[i].next) {
			if (dis1[edge1[i].y] > dis1[now] + edge1[i].z) {
				dis1[edge1[i].y] = dis1[now] + edge1[i].z;
				if (can[edge1[i].y] == 0) {
					can[edge1[i].y] = 1;
					q.push(edge1[i].y);
				}
			}
		}
		can[now] = 0;
	}
}

void spfa2() {
	dis2[1] = 0;
	can[1] = 1;
	queue<int> q;
	q.push(1);
	int now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = head2[now]; i != -1; i = edge2[i].next) {
			if (dis2[edge2[i].y] > dis2[now] + edge2[i].z) {
				dis2[edge2[i].y] = dis2[now] + edge2[i].z;
				if (can[edge2[i].y] == 0) {
					can[edge2[i].y] = 1;
					q.push(edge2[i].y);
				}
			}
		}
		can[now] = 0;
	}
}

int main()
{
	int f;
	cin >> f;
	while (f--) {
		int n, m;
		cin >> n >> m;
		tot = 0;
		memset(head1, -1, sizeof(head1));
		memset(head2, -1, sizeof(head2));
		memset(dis1, INF, sizeof(dis1));
		memset(dis2, INF, sizeof(dis2));
		memset(can, 0, sizeof(can));
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			add(x, y, z);
		}
		spfa1();
		memset(can, 0, sizeof(can));
		spfa2();
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += dis1[i] + dis2[i];
		}
		cout << ans << endl;
	}
	return 0;
}