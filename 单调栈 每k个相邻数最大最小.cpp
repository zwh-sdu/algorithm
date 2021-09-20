//问题描述
//有一行 n 个数。输出每 k 个相邻数字的最大值和最小值。
//
//输入格式
//第一行两个整数 n, k。
//第二行，有 n 个数字，中间用空格隔开，每一个数为大小不超过 10 ^ 9的正整数。
//
//输出格式
//有两行，每行 n - k + 1 个数字，第一行表示最小值，第二行表示最大值。
//
//样例输入
// 8 3
// 1 3 - 1 - 3 5 3 6 7
//
//样例输出
//- 1 - 3 - 3 - 3 3 3
//3 3 5 5 6 7

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> num;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num.push_back(a);
	}

	deque<int> smax;
	for (int i = 0; i < k; i++) {
		while (!smax.empty() && num[i] <= num[smax.back()]) {
			smax.pop_back();
		}
		smax.push_back(i);
	}
	cout << num[smax.front()] << " ";
	for (int i = k; i < n; i++) {
		while (!smax.empty() && num[i] <= num[smax.back()]) {
			smax.pop_back();
		}
		smax.push_back(i);
		while (smax.front() <= i - k) {
			smax.pop_front();
		}
		cout << num[smax.front()] << " ";
	}

	cout << "\n";

	deque<int> smin;
	for (int i = 0; i < k; i++) {
		while (!smin.empty() && num[i] >= num[smin.back()]) {
			smin.pop_back();
		}
		smin.push_back(i);
	}
	cout << num[smin.front()] << " ";
	for (int i = k; i < n; i++) {
		while (!smin.empty() && num[i] >= num[smin.back()]) {
			smin.pop_back();
		}
		smin.push_back(i);
		while (smin.front() <= i - k) {
			smin.pop_front();
		}
		cout << num[smin.front()] << " ";
	}


	return 0;
}