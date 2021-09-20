//问题描述
//对于一个整数序列 A = (a_1, a_2, 。。, a_k)定义 A 的子序列为：
//从 A 中删除若干个元素后（允许不删，也允许将所有 k 个元素都删除），
//剩下的元素按照原来的顺序所组成的序列。如果这个子序列的元素从左到右严格递增，则称它为 A 的一个上升子序列。
//其中包含元素数量最多的上升子序列称为 A 的最长上升子序列。
//那么，给定一个序列 A = (a_1, a_2, 。。。, a_n) 求 A 的最长上升子序列的长度
//
//样例输入
//第一行一个整数 n ，代表序列 A 的长度
//第二行是 n 个由空格隔开的整数，代表 a_1, a_2,。。, a_n
//
//输出格式
//一个整数，代表最长上升子序列的长度
//
//样例输入
//7
//2 1 1 4 7 5 6
//
//样例输出
//4

#include<bits/stdc++.h>
#define N 1000003
using namespace std;

int s[N];
int f[N];
int n;

int lowbit(int x) {
	return x & (-x);
}

int ask(int x) {
	int res = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {
		res = max(res, s[i]);
	}
	return res;
}

void upd(int x, int v) {
	for (int i = x; i <= N; i += lowbit(i)) {
		s[i] = max(s[i], v);
	}
}

int main()
{
	int t, ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		f[i] = ask(t - 1) + 1;
		upd(t, f[i]);
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}