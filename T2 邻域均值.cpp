#include<bits/stdc++.h>

using namespace std;

int n, l, r, t, ans;
int a[605][605], sum[605][605];

int main() {
    cin >> n >> l >> r >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (i == 0 && j == 0) sum[i][j] = a[i][j];
            else if (i == 0) sum[i][j] = sum[i][j - 1] + a[i][j];
            else if (j == 0) sum[i][j] = sum[i - 1][j] + a[i][j];
            else sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int le, ri, up, dm, tsum, tnum;
    for (int i = 0; i < n; i++) {
        if (i < r) up = 0;
        else up = i - r;
        if (n - i - 1 < r) dm = n - 1;
        else dm = i + r;
        for (int j = 0; j < n; j++) {
            if (j < r) le = 0;
            else le = j - r;
            if (n - j - 1 < r) ri = n - 1;
            else ri = j + r;

            tnum = (dm - up + 1) * (ri - le + 1);
            if (up == 0 && le == 0) tsum = sum[dm][ri];
            else if (up == 0) tsum = sum[dm][ri] - sum[dm][le - 1];
            else if (le == 0) tsum = sum[dm][ri] - sum[up - 1][ri];
            else tsum = sum[dm][ri] - sum[up - 1][ri] - sum[dm][le - 1] + sum[up - 1][le - 1];
            if (tsum * 1.0 / tnum <= t * 1.0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}