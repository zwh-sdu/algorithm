#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int head[N], vis[N], ans, tot, n, m, pos;

struct Edge
{
    int v, w, nxt;
} edge[2 * N];

void add(int u, int v, int w)
{
    edge[tot] = {v, w, head[u]};
    head[u] = tot++;
}

void dfs(int u, int depth)
{
    vis[u] = 1;
    if (depth > ans)
    {
        ans = depth;
        pos = u;
    }
    for (int i = head[u]; i != -1; i = edge[i].nxt)
    {
        int v = edge[i].v, w = edge[i].w;
        if (vis[v])
            continue;
        dfs(v, depth + w);
    }
}

int main()
{
    cin >> n >> m;
    int x;
    for (int i = 0; i < N; i++)
        head[i] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        add(x, i + 2, 1);
        add(i + 2, x, 1);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        add(x, i + n + 1, 1);
        add(i + n + 1, x, 1);
    }
    dfs(1, 0);
    memset(vis, 0, sizeof(vis));
    dfs(pos, 0);
    cout << ans << endl;
    system("pause");
    return 0;
}