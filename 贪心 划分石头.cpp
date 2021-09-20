//问题描述
//海边有很多好看的石，war把它们收集起来依次排成一排，一共n个，第i个石头的重量为wi。
//他想将其分成m段，每一段连续，并且重量和最大的段的和最小。请你帮帮他～
//
//输入描述
//第一行为n(1≤n≤10 ^ 5)，第二行n个数，第i个数为wi(0≤wi≤10 ^ 9)，中间有空格。
//
//输出描述
//输出只有一个数，重量和最大的段的和。
//
//输入样例
//6 3
//4 2 4 5 1 1
//
//输出样例
//7

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> w, int x, int m) {
	int sum = 0, cnt = 1;
	for (int i = 0; i < w.size(); i++)
	{
		if (sum + w[i] > x) {
			cnt++;
			sum = w[i];
		}
		else {
			sum += w[i];
		}
	}
	return cnt <= m;
}

int main()
{
	int n, m, left = 0, right = 0;
	cin >> n >> m;
	vector<int> w;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		right += x;
		if (left < x) {
			left = x;
		}
		w.push_back(x);
	}
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (check(w, mid, m)) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left << endl;
	return 0;
}