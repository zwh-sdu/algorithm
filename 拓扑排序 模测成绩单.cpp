//问题描述
//模测结束了，小 L 拿到了一些形如 A 比 B 得分高 的信息，
//现在小 L 想要输出一份成绩排名表，使得排名表满足得到的信息，并且学号小的尽可能排在前面。
//
//输入格式
//第一行有两个整数，n, m 表示有 nn 个同学，第 ii 个同学学号为 ii ，有 m 条信息。
//接下来有 m 行，每行有两个整数 A, B ，表示学号为 A 的同学得分比学号为 B 的同学得分高。
//1≤n, m≤10^6
//1≤A, B≤n
//数据保证有解
//
//输出格式
//输出一行 n 个数，表示按照学号给出的排名。
//
//样例输入
//5 3
//4 5
//2 3
//1 5
//
//样例输出
//1 2 3 4 5

#include<bits/stdc++.h>
using namespace std;

struct Edge
{
	int v;
	Edge* next;
}edge[1000005];

int ind[1000005];//入度
vector<int> ans;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		Edge* newe = new Edge;
		newe->v = y;
		newe->next = edge[x].next;
		edge[x].next = newe;
		ind[y]++;
	}
	priority_queue<int, vector<int>, greater<int>> q;//优先队列
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {//把入度为零的放入队列
			q.push(i);
		}
	}
	Edge* now;
	while (!q.empty()) {
		int u = q.top();
		q.pop();
		ans.push_back(u);
		now = edge[u].next;
		while (now) {
			int v = now->v;
			ind[v]--;
			if (ind[v] == 0) {
				q.push(v);
			}
			now = now->next;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}