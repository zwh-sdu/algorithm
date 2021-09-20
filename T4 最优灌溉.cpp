#include <bits/stdc++.h>
using namespace std;

int n, m, ans, a, b, c;

struct Edge
{
    int u, v, w;
    bool operator<(const Edge &t) const { return w < t.w; }
};

vector<Edge> edge;

int f[1005];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
}

int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}

bool unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    f[x] = y;
    return true;
}

int kruskal()
{
    sort(edge.begin(), edge.end());
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (unite(edge[i].u, edge[i].v))
        {
            ans += edge[i].w;
            if (++cnt == n - 1)
                break;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }
    cout << kruskal() << endl;
    system("pause");
    return 0;
}