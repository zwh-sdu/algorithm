#include <bits/stdc++.h>
using namespace std;

#define N 10005
//并查集判断是否连通
int v[N];
int find(int x)
{
    if (x == v[x])
        return x;
    else
        return v[x] = find(v[x]);
}

bool Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    else
    {
        v[x] = y;
        return true;
    }
}

set<int> s[N];   //存邻接图
stack<int> path; //保存欧拉路径
bool vis[N][N];
bool flag;
int n, m;

void dfs(int node)
{
    for (auto iter = s[node].begin(); iter != s[node].end(); iter++)
    {
        if (!vis[node][*iter])
        {
            vis[node][*iter] = true;
            vis[*iter][node] = true;
            dfs(*iter);
        }
    }
    path.push(node);
}

int main()
{
    int a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        v[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        s[a].insert(b);
        s[b].insert(a);
        Union(a, b);
    }
    //判断图的连通性
    flag = false;
    int root = find(1);
    for (int i = 2; i <= n; i++)
    {
        if (find(i) != root)
        {
            flag = true;
            break;
        }
    }
    //判断是否存在欧拉路径，根据出入度运算
    if (!flag)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i].size() % 2 == 1)
                count;
        }
        if (!(count == 0 || (count == 2 && s[1].size() % 2 == 1)))
            flag = true;
    }
    if (!flag)
    {
        memset(vis, false, sizeof(vis));
        dfs(1);
        int t;
        while (!path.empty())
        {
            t = path.top();
            path.pop();
            cout << t << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << -1 << endl;
    }
    system("pause");
    return 0;
}