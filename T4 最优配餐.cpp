#include <bits/stdc++.h>
using namespace std;

int n, m, k, d, a, b, c;
long long ans;
int dis[1005][1005];  //距离
bool vis[1005][1005]; //能不能走
queue<pair<int, int>> q;
struct node
{
    int x, y, z;
};
vector<node> ve;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void bfs()
{
    pair<int, int> p;
    int newx, newy;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            newx = p.first + dx[i];
            newy = p.second + dy[i];
            if (newx >= 1 && newx <= n && newy >= 1 && newy <= n && !vis[newx][newy])
            {
                if (dis[newx][newy] > dis[p.first][p.second] + 1)
                {
                    dis[newx][newy] = dis[p.first][p.second] + 1;
                    q.push(make_pair(newx, newy));
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k >> d;
    //初始化dis距离数组
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = 0x3f3f3f3f;
        }
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        dis[a][b] = 0;
        q.push(make_pair(a, b));
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        ve.push_back({a, b, c});
    }
    for (int i = 0; i < d; i++)
    {
        scanf("%d%d", &a, &b);
        vis[a][b] = true;
    }
    bfs();
    for (int i = 0; i < k; i++)
    {
        ans += dis[ve[i].x][ve[i].y] * ve[i].z;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}