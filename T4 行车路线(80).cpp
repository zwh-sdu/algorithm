#include<bits/stdc++.h>

using namespace std;

int n, m, t, a, b, type, tot;
long long c;

struct Edge {
    long long w;
    int v,type, nxt;
} edge[200005];

int head[505], vis[505];
long long dis[505], xl[505]; //xl数组记录小路走了多长

void add(int u, int v, long long w, int type) {
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].type = type;
    edge[tot].nxt = head[u];
    head[u] = tot++;
}

void dij() {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[1] = 0;
    q.push(make_pair(0, 1));
    vis[1] = 1;
    int tem=n;
    while (!q.empty()) {
        int sta = q.top().second;
        q.pop();
        for (int i = head[sta]; i != -1; i = edge[i].nxt) {
            int v = edge[i].v, w = edge[i].w, t = edge[i].type;
            if (vis[v]) continue;
            if (t == 0) {
                if (dis[v] > dis[sta] + w) {
                    dis[v] = dis[sta] + w;
                    xl[v] = 0;
                    q.push(make_pair(dis[v],v));
                }
            } else {
                if (!xl[sta]) {
                    if (dis[v] > dis[sta] + w * w) {
                        dis[v] = dis[sta] + w * w;
                        xl[v] = w;
                        q.push(make_pair(dis[v],v));
                    }
                } else {
                    long long w1 = (xl[sta] + w) * (xl[sta] + w) - xl[sta] * xl[sta];
                    if (dis[v] > dis[sta] + w1) {
                        dis[v] = dis[sta] + w1;
                        xl[v] = xl[sta] + w;
                        q.push(make_pair(dis[v],v));
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    while (m--) {
        cin >> type >> a >> b >> c;
        add(a, b, c, type);
        add(b, a, c, type);
    }
    dij();
    cout << dis[n] << endl;
    return 0;
}