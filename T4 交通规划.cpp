#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, tot, ans;
struct Edge
{
	int v, cost, nxt;
};
Edge edge[400000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int dis[10005], cost[10005], vis[10005], head[10005];

void add(int x, int y, int z)
{
	edge[tot].v = y;
	edge[tot].cost = z;
	edge[tot].nxt = head[x];
	head[x] = tot++;
}

void dijkstra(int start)
{
	for (int i = 0; i <= n; i++)
	{
		dis[i] = 0x3f3f3f3f;
		cost[i] = 0x3f3f3f3f;
	}
	dis[start] = 0;
	cost[start] = 0;
	q.push(make_pair(0, start));
	pair<int, int> t;
	while (!q.empty())
	{
		t = q.top();
		q.pop();
		if (vis[t.second])
			continue;
		vis[t.second] = 1;
		int vt, ct;
		for (int i = head[t.second]; i != -1; i = edge[i].nxt)
		{
			vt = edge[i].v;
			ct = edge[i].cost;
			if (vis[vt])
				continue;
			if (dis[vt] > dis[t.second] + ct)
			{
				dis[vt] = dis[t.second] + ct;
				cost[vt] = ct;
				q.push(make_pair(dis[vt], vt));
			}
			else if (dis[vt] == dis[t.second] + ct)
			{
				cost[vt] = min(cost[vt], ct);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	dijkstra(1);
	for (int i = 2; i <= n; i++)
	{
		ans += cost[i];
	}
	cout << ans << endl;
	system("pause");
	return 0;
}