//问题描述
//终于可以随意出入校园啦！于是，n个人决定去看电。每个人都要先去A影院再去B影院。
//第i个人在A，B影院的观影时间分别为ai，bi。
//按照疫情防控要求，每个影院最多允许1人同时观影。
//那么怎样安排这n个人的观影顺序，能使所有人都在A,B影院观影完的总时间最少。
//
//输入描述
//第一行为n(0 < n < 1000)(0 < n < 1000)，表示人数。
//第二行n个数，第i个数为ai(1≤ai≤350),中间有空格。
//第三行n个数，第i个数为bi(1≤bi≤350),中间有空格。
//
//输出描述
//输出只有一个数，为最少的总时间。
//提示：Johnson法则
//
//样例输入
//5
//3 5 8 7 10
//6 3 2 5 8
//
//样例输出
//35

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return min(a.first, b.second) < min(a.second, b.first);
}

int main()
{
	vector<pair<int, int>> x;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		x.push_back(make_pair(a, 0));
	}
	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		x[i].second = b;
	}
	sort(x.begin(), x.end(), cmp);

	int ta = 0, tb = 0;
	for (int i = 0; i < n; i++)
	{
		ta += x[i].first;
		tb = x[i].second + max(ta, tb);
	}
	cout << tb << endl;
	return 0;
}