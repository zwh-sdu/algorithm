//问题描述
//给定数列 a1, a1...an，你需要依次进行 q 个操作，操作有两类：
//1 i x : 给定i，x，将ai加上x
//2 l r : 给定l，r，求l到r的ai的值
//
//输出格式
//对于每个 2 l r 操作输出一行，每行有一个整数，表示所求的结果。
//
//样例输入
//3 2
//1 2 3
//1 2 0
//2 1 3
//
//样例输出
//6
#include<bits/stdc++.h>
#define N 1000003
using namespace std;

long long tree[N];
long long n, q;

long long lowbit(long long x) {
	return x & (-x);
}

void add(long long i, long long x) {
	for (long long j = i; j <= n; j += lowbit(j)) {
		tree[j] += x;
	}
}

long long ask(long long x) {
	long long ans = 0;
	for (long long i = x; i >= 1; i -= lowbit(i)) {
		ans += tree[i];
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	long long op, temp;
	cin >> n >> q;
	for (long long i = 1; i <= n; i++) {
		cin >> temp;
		add(i, temp);
	}
	while (q--) {
		cin >> op;
		if (op == 1) {
			long long i, x;
			cin >> i >> x;
			add(i, x);
		}
		if (op == 2) {
			long long l, r;
			cin >> l >> r;
			cout << ask(r) - ask(l - 1) << endl;
		}
	}
	return 0;
}