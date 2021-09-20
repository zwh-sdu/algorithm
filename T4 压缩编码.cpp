#include<bits/stdc++.h>

using namespace std;
//石子合并问题
//int n;
//int a[1005];
//int dp[1005][1005];
//int sum[1005]; //前缀和
//
//int main() {
//    memset(dp, 999999, sizeof(dp));
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//        if (i == 0) {
//            sum[i] = a[i];
//        } else {
//            sum[i] += sum[i - 1] + a[i];
//        }
//        dp[i][i] = 0;
//    }
//    for (int len = 1; len <= n; len++) {
//        for (int i = 0; i < n - len; i++) {
//            int j = i + len;
//            int temp = sum[j] - (i > 0 ? sum[i - 1] : 0);
//            for (int k = i; k < j; k++) {
//                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + temp);
//            }
//        }
//    }
//    cout << dp[0][n - 1] << endl;
//    return 0;
//}

//平行四边形优化
int n;
int a[1005], sum[1005];
int dp[1005][1005], p[1005][1005];

int main() {
    cin >> n;
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        dp[i][i] = 0;
        p[i][i] = i;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            int temp;
            int t = 0;
            for (int k = p[i][j - 1]; k <= p[i + 1][j]; k++) {
                temp = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
                if (dp[i][j] > temp) {
                    dp[i][j] = temp;
                    p[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}