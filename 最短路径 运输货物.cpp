//问题描述
//考虑一个具有N个顶点，M条边的无向图。
//编号为1的顶点对应于一个矿山，从中提取一些珍贵的矿物。
//编号为N的顶点对应于一家矿物加工厂。每条边连接两个不同的顶点并拥有有两个参数，分别为最大承重量C和通行时间D。
//现在将从矿山中提取的矿物并选择一条路径将提取的矿物运送至工厂。
//该路径应具有最大的承重量，以便能够同时运输尽可能多的矿物。路径的承重量等于路径中经过的边的最大承重量的最小值。
//但是，这些矿物非常敏感，一旦从矿山中提取出来，它们将在T时间单位后开始分解，除非他们在此时间间隔内到达工厂。
//因此，所选路径的总行进时间（其路径的通行时间之和）应小于或等于T。
//
//输入格式
//输入的第一行包含一个整数X，表示测试用例的数量。
//每个测试用例的第一行包含3个整数，并用空格分隔：N，M，T。
//接下来的M行中的每行将包含四个整数，每个数字用空格分隔：A，B，C和D，
//这意味着顶点A和B之间存在一条边，最大承重量为C，通行时间为D。A和B是1和N之间的不同整数。
//任何两个顶点之间最多存在一个边。
//
//输出格式
//对于X个测试用例，请输出在满足通行时间限制下的路径最大承重量，每个测试用例对应一行。
//数据保证图中至少存在一条1到n通行总时间小于等于T的路径，即一定有解。
//
//样例输入
//2
//2 1 10
//1 2 13 10
//4 4 20
//1 2 1000 15
//2 4 999 6
//1 3 100 15
//3 4 99 4
//
//样例输出
//13
//99

#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define ll long long

const ll mm = 100010;
ll tot;
ll dis[mm], can[mm], head[mm];
ll n, m, t;

struct Edge
{
	ll b, c, d, next;
}edge[mm];

void add(ll a, ll b, ll c, ll d) {
	edge[tot].b = b;
	edge[tot].c = c;
	edge[tot].d = d;
	edge[tot].next = head[a];
	head[a] = tot++;
}

bool spfa(ll minc) {
	memset(dis, INF, sizeof(dis));
	memset(can, 0, sizeof(can));
	dis[1] = 0;
	can[1] = 1;
	queue<ll> q;
	q.push(1);
	while (!q.empty()) {
		ll now;
		now = q.front();
		q.pop();
		for (ll i = head[now]; i != -1; i = edge[i].next) {
			if (dis[edge[i].b] > dis[now] + edge[i].d && edge[i].c >= minc) {
				dis[edge[i].b] = dis[now] + edge[i].d;
				if (!can[edge[i].b]) {
					can[edge[i].b] = 1;
					q.push(edge[i].b);
				}
			}
		}
		can[now] = 0;
	}
	return (dis[n] <= t);
}

int main()
{
	ll f;
	cin >> f;
	while (f--) {
		vector<ll> v;
		cin >> n >> m >> t;
		tot = 0;
		memset(head, -1, sizeof(head));
		for (ll i = 0; i < m; i++) {
			ll a, b, c, d;
			cin >> a >> b >> c >> d;
			add(a, b, c, d);
			add(b, a, c, d);
			v.push_back(c);
		}
		sort(v.begin(), v.end());
		ll left = 0, right = v.size() - 1;
		ll mid = 0;
		while (left < right) {
			mid = left + (right - left + 1) / 2;
			if (spfa(v[mid])) {
				left = mid;
			}
			else {
				right = mid - 1;
			}
		}
		cout << v[left] << endl;
	}
	return 0;
}