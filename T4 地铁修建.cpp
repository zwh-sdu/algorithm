#include<bits/stdc++.h>

#define pa pair<int,int>
using namespace std;
struct Edge {
    int v, w, nxt;
} edge[500000];

int head[100005], dis[100005], vis[100005];
int n, m, a, b, c, tot;

void add(int x, int y, int z) {
    edge[tot].v = y;
    edge[tot].w = z;
    edge[tot].nxt = head[x];
    head[x] = tot++;
}

void dij() {
    priority_queue<pa, vector<pa >, greater<pa>> q;
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        int sta = q.top().second;
        q.pop();
        if (vis[sta]) continue;
        vis[sta] = 1;
        int v, w;
        for (int i = head[sta]; i != -1; i = edge[i].nxt) {
            v = edge[i].v;
            w = edge[i].w;
            if (dis[v] > max(w, dis[sta])) {
                dis[v] = max(w, dis[sta]);
                q.push(make_pair(dis[v], v));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dis[1] = 0;
    dij();
    cout << dis[n] << endl;
    return 0;
}