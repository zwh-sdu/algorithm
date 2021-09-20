#include <bits/stdc++.h>
using namespace std;

char s[105][105], c;
int m, n, x1, x2, yl, y2, op, q;
int d1[4] = {0, 0, 1, -1}, d2[4] = {1, -1, 0, 0};
queue<pair<int, int>> p;
int vis[105][105];

int main()
{
    memset(s, '.', sizeof(s));
    cin >> m >> n >> q;
    for (int k = 0; k < q; k++)
    {
        cin >> op;
        //划线操作
        if (op == 0)
        {
            cin >> x1 >> yl >> x2 >> y2;
            if (x1 == x2)
            {
                if (yl > y2)
                {
                    int t = yl;
                    yl = y2;
                    y2 = t;
                }
                for (int i = n - 1 - y2; i <= n - 1 - yl; i++)
                {
                    if (s[i][x1] == '-' || s[i][x1] == '+')
                        s[i][x1] = '+';
                    else
                        s[i][x1] = '|';
                }
            }
            else
            {
                if (x1 > x2)
                {
                    int t = x1;
                    x1 = x2;
                    x2 = t;
                }
                for (int i = x1; i <= x2; i++)
                {
                    if (s[n - 1 - yl][i] == '|' || s[n - 1 - yl][i] == '+')
                        s[n - 1 - yl][i] = '+';
                    else
                        s[n - 1 - yl][i] = '-';
                }
            }
        }
        //填充操作
        else
        {
            cin >> x1 >> yl >> c;
            yl = n - 1 - yl;
            while (!p.empty())
                p.pop();
            p.push(make_pair(yl, x1));
            pair<int, int> temp;
            memset(vis, 0, sizeof(vis));
            vis[yl][x1] = 1;
            while (!p.empty())
            {
                temp = p.front();
                p.pop();
                s[temp.first][temp.second] = c;
                for (int i = 0; i < 4; i++)
                {
                    if (vis[temp.first + d1[i]][temp.second + d2[i]] || s[temp.first + d1[i]][temp.second + d2[i]] == '|' || s[temp.first + d1[i]][temp.second + d2[i]] == '-' || s[temp.first + d1[i]][temp.second + d2[i]] == '+')
                        continue;
                    if (temp.first + d1[i] >= 0 && temp.first + d1[i] < n && temp.second + d2[i] >= 0 && temp.second + d2[i] < m)
                    {
                        p.push(make_pair(temp.first + d1[i], temp.second + d2[i]));
                        vis[temp.first + d1[i]][temp.second + d2[i]] = 1;
                    }
                }
            }
        }
    }
    //输出结果
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << s[i][j];
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}