//问题描述
//目前在一个很大的平面房间里有 n 个无线路由器, 每个无线路由器都固定在某个点上。任何两个无线路由器只要距离不超过 r 就能互相建立网络连接。
//除此以外, 另有 m 个可以摆放无线路由器的位置。你可以在这些位置中选择至多 k 个增设新的路由器。
//你的目标是使得第 1 个路由器和第 2 个路由器之间的网络连接经过尽量少的中转路由器。请问在最优方案下中转路由器的最少个数是多少 ?
//输入格式
//第一行包含四个正整数 n, m, k, r。(2 ≤ n ≤ 100, 1 ≤ k ≤ m ≤ 100, )。
//接下来 n 行, 每行包含两个整数 x i 和 y i, 表示一个已经放置好的无线 路由器在(x i, y i) 点处。输入数据保证第 1 和第 2 个路由器在仅有这 n 个路由器的情况下已经可以互相连接(经过一系列的中转路由器)。
//接下来 m 行, 每行包含两个整数 x i 和 y i, 表示(x i, y i) 点处可以增设 一个路由器。
//输入中所有的坐标的绝对值不超过 10 8, 保证输入中的坐标各不相同。
//输出格式
//输出只有一个数, 即在指定的位置中增设 k 个路由器后, 从第 1 个路 由器到第 2 个路由器最少经过的中转路由器的个数。
//样例输入
//5 3 1 3
//0 0
//5 5
//0 3
//0 5
//3 5
//3 3
//4 4
//3 0
//样例输出
//2

#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

ll r;
int n, m, k;

struct node {
	ll x, y;
}N;

struct info {
	ll step;//经过了多少路由器
	ll num;//新设置了多少路由器
	int id;//节点编号
}T;

queue<info> q;
vector<node> vec;
int vis[210];
bool check(ll x1, ll y1, ll x2, ll y2) {
	ll x = x1 - x2;
	ll y = y2 - y1;
	if ((x * x + y * y) <= r * r) {
		return true;
	}
	else {
		return false;
	}
}

int bfs()
{
	info new_T;
	int id;
	T.num = 0;
	T.step = 0;
	T.id = 0;
	q.push(T);
	vis[0] = 1;
	while (!q.empty()) {
		new_T = q.front();
		q.pop();
		id = new_T.id;
		if (check(vec[id].x, vec[id].y, vec[1].x, vec[1].y)) {
			return  new_T.step;
		}
		for (int i = 0; i < vec.size(); i++) {
			if (!vis[i] && i != id && check(vec[id].x, vec[id].y, vec[i].x, vec[i].y)) {
				if (new_T.num == k && i >= n) {//不能再添加新的路由器了
					continue;
				}
				vis[i] = 1;
				T.step = new_T.step + 1;
				if (i >= n) {
					T.num = new_T.num + 1;
				}
				else {
					T.num = new_T.num;
				}
				T.id = i;
				q.push(T);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k >> r;
	for (int i = 0; i < n + m; i++) {
		cin >> N.x >> N.y;
		vec.push_back(N);
	}
	cout << bfs() << endl;
	return 0;
}