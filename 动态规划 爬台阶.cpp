//问题描述
//楼上有 n 级台阶，其中有 m 级台阶是不安全的。yhf一开始站在第 00 级台阶上，希望最终走到第 nn 级台阶
//yhf跨一步满足以下约束：
//只能向前走
//不能落脚在不安全的台阶上
//最多迈 k 级台阶
//落脚点不能超过第 n 级台阶
//也就是说，若某一刻yhf站在第 c 级台阶上，那么他下一步可以落脚的位置 x 满足 c < x≤min(c + k, n)
//且第 x 级台阶是安全的。那么，yhf有多少种方法走到第 n 级台阶
//
//输入格式
//第一行三个整数 n, m, k ，描述见上文
//第二行 mm 个整数，d_1, d_2, ..., d_m 其中 1<=di<n,表示不安全台阶的编号
//
//样例输入
//5 1 2
//3
//
//样例输出
//2

#include<bits/stdc++.h>
#define N 998244353
using namespace std;

long long a[1000003], b[1000003];

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	a[0] = 1;
	b[0] = 1;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		a[t] = -1;
	}

	for (int i = 1; i <= n; i++) {
		//for (int j = 1; j <= k; j++) {
		//	if (i >= j && a[i] != -1 && a[i - j] != -1) {
		//		a[i] += a[i - j];
		//		a[i] = (a[i]) % 998244353;
		//	}
		//}
		if (a[i] == -1) {
			b[i] = b[i - 1];
			continue;
		}
		if (i - k - 1 >= 0) {
			a[i] += b[i - 1] - b[i - k - 1];
			a[i] = a[i] % N;
		}
		else {
			a[i] += b[i - 1];
			a[i] = a[i] % N;
		}
		b[i] = b[i - 1] + a[i];
	}
	cout << a[n] << endl;
	return 0;

}