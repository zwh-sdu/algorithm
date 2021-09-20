#include <bits/stdc++.h>
using namespace std;

int n, m, t, r, c, a, b, ans;
int can[105][105][210], vis[105][105][210];
struct node
{
	int r, c, ti;
};
queue<node> q;
int d1[4] = {0, 0, 1, -1}, d2[4] = {1, -1, 0, 0};

int main()
{
	cin >> n >> m >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> r >> c >> a >> b;
		for (int j = a; j <= b; j++)
		{
			can[r][c][j] = 1;
		}
	}
	//bfs
	q.push({1, 1, 0});
	vis[1][1][0] = 1;
	node temp;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp.r == n && temp.c == m)
		{
			ans = temp.ti;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			if (d1[i] + temp.r < 1 || d1[i] + temp.r > n || d2[i] + temp.c < 1 || d2[i] + temp.c > m)
				continue;
			if (vis[d1[i] + temp.r][d2[i] + temp.c][temp.ti + 1] || can[d1[i] + temp.r][d2[i] + temp.c][temp.ti + 1])
				continue;
			vis[d1[i] + temp.r][d2[i] + temp.c][temp.ti + 1] = 1;
			q.push({d1[i] + temp.r, d2[i] + temp.c, temp.ti + 1});
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}