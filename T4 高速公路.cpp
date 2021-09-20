#include <bits/stdc++.h>
using namespace std;
#define N 1000005

vector<int> G1[N], G2[N];
int vis[N], c[N];
vector<int> ve, res;
int cnt, n, m, ans, temp;

void add(int a, int b)
{
    G1[a].push_back(b);
    G2[b].push_back(a);
}

void dfs1(int x)
{
    vis[x] = 1;
    for (int j = 0; j < G1[x].size(); j++)
    {
        if (!vis[G1[x][j]])
            dfs1(G1[x][j]);
    }
    ve.push_back(x);
}

void dfs2(int x)
{
    temp++;
    c[x] = cnt;
    for (int j = 0; j < G2[x].size(); j++)
    {
        if (c[G2[x][j]]==0)
        {
            dfs2(G2[x][j]);
        }
    }
}

void kosaraju()
{
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs1(i);
    }
    for (int i = ve.size() - 1; i >= 0; i--)
    {
        if (c[ve[i]] == 0)
        {
            cnt++;
            temp = 0;
            dfs2(ve[i]);
            ans += (temp * (temp - 1) / 2);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    kosaraju();
    cout << ans << endl;
    system("pause");
    return 0;
}