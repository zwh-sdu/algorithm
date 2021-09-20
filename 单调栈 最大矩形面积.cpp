//问题描述
//最大矩形面积
//
//输入格式
//第一行一个整数 n
//第二行，一行数，第 i 个数代表 hi
//
//输出格式
//一个数，代表最大矩形面积
//
//样例输入
//7
//2 1 4 5 1 3 3
//
//样例输出
//8

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> h;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		h.push_back(a);
	}
	vector<int> l(n), r(n);
	stack<int> s1,s2;
	for (int i = 0; i < n; i++) {
		while (!s1.empty() && h[s1.top()] >= h[i]) {
			s1.pop();
		}
		if (s1.empty()) {
			l[i] = -1;
		}
		else {
			l[i] = s1.top();
		}
		s1.push(i);
	}

	for (int i = n-1; i >= 0; i--) {
		while (!s2.empty() && h[s2.top()] >= h[i]) {
			s2.pop();
		}
		if (s2.empty()) {
			r[i] = n;
		}
		else {
			r[i] = s2.top();
		}
		s2.push(i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, h[i] * (r[i] - l[i] - 1));
	}
	cout << ans << endl;

	return 0;
}

// int main()
// {
// 	int n;
// 	cin >> n;
// 	vector<long long> h;
// 	for (int i = 0; i < n; i++) {
// 		long long a;
// 		cin >> a;
// 		h.push_back(a);
// 	}
// 	vector<int> l(n), r(n, n);
// 	stack<int> s;
// 	for (int i = 0; i < n; i++) {
// 		while (!s.empty() && h[s.top()] >= h[i]) {
// 			r[s.top()] = i;
// 			s.pop();
// 		}
// 		if (s.empty()) {
// 			l[i] = -1;
// 		}
// 		else {
// 			l[i] = s.top();
// 		}
// 		s.push(i);
// 	}
// 	long long ans = 0;
// 	for (int i = 0; i < n; i++) {
// 		if (ans < (long long)h[i] * (r[i] - l[i] - 1)) {
// 			ans = (long long)h[i] * (r[i] - l[i] - 1);
// 		}
// 	}
// 	cout << ans << endl;

// 	return 0;
// }