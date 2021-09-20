//问题描述
//有 n 个人，每个人都有一个编号，从 1 到 n 。
//如果 A 得知一个消息，那么他一定会告诉 B 。
//问最少把消息告诉几个人，能让所有人得知这个消息。
//
//输入格式
//第一行两个整数 n, m, 1≤n, m≤10^6，表示有 n 个人
//接下来 m 行，每行给出一个关系形如 A, B ，表示如果 A 得知一个消息，那么他一定会告诉 B 。
//
//输出格式
//输出一行，一个数，代表答案
//
//样例输入
//10 10
//1 3
//2 4
//4 5
//2 8
//5 2
//5 9
//6 8
//9 2
//10 5
//5 8
//
//样例输出
//4

#include<bits/stdc++.h>
using namespace std;
#define mm 1000005

vector<int> G1[mm], G2[mm];
int vis[mm], c[mm], link[mm], u[mm], v[mm];
vector<int> vs;//存遍历顺序
int cnt, n, m, ans;

void add(int a, int b) {
	G1[a].push_back(b);
	G2[b].push_back(a);
}

void dfs1(int x) {
	vis[x] = 1;
	for (int j = 0; j < G1[x].size(); j++) {
		if (vis[G1[x][j]] == 0) {
			dfs1(G1[x][j]);
		}
	}
	vs.push_back(x);
}

void dfs2(int x) {
	c[x] = cnt;
	for (int j = 0; j < G2[x].size(); j++) {
		if (c[G2[x][j]] == 0) {
			dfs2(G2[x][j]);
		}
	}
}

void kosaraju() {
	cnt = 0;
	memset(vis, 0, sizeof(vis));
	memset(c, 0, sizeof(c));
	//第一遍dfs
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			dfs1(i);
		}
	}
	//第二遍dfs
	for (int i = vs.size() - 1; i >= 0; i--) {
		if (c[vs[i]] == 0) {
			cnt++;
			dfs2(vs[i]);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		add(x, y);
		u[i] = x;
		v[i] = y;
	}
	kosaraju();
	//缩点
	for (int i = 0; i < m; i++) {
		if (c[u[i]] == c[v[i]]) {
			continue;
		}
		else {
			link[c[v[i]]] = 1;
			//cout << v[i] << " ";
		}
	}
	for (int i = 1; i <= cnt; i++) {
		if (link[i] == 0) {
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}