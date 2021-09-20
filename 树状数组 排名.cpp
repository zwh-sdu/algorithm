//问题描述
//sys 参加了一场 AI 算法大赛，大赛要求参赛者提供一个程序，
//后台的评测系统会使用相同的数据对所有提交程序进行评测，通过程序的运行时间与内存占用来衡量一个算法的好坏。
//比赛的成绩计算方法为，给每一个程序进行打分，
//对于一个程序来说，该程序的得分为：运行时间与内存占用均小于等于该程序的程序的数量。
//现在需要你来计算，成绩为0, 1, 。。n−1 的程序的数量分别为多少。
//
//输入格式
//第一行一个整数 N，表示程序的数目；
//接下来 N 行给出每个程序的运行时间与内存占用，用两个空格隔开的整数表示；
//不会有两个程序的运行时间与内存占用均相同。
//
//输出格式
//n 行，每行一个整数，分别是得分为 0，1，2，。。，n - 1 的程序的数目。
//
//样例输入
//5
//1 1
//5 1
//7 1
//3 3
//5 5
//
//样例输入
//1
//2
//1
//1
//0

#include<bits/stdc++.h>
#define N 1000001
using namespace std;

int c[N], ans[N];
int n, maxx;

struct Node
{
	int x, y;
}node[N];

bool cmp(Node a, Node b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}

int lowbit(int x) {
	return x & (-x);
}

void upd(int x) {
	for (int i = x; i <= maxx; i += lowbit(i)) {
		c[i]++;
	}
}

int ask(int x) {
	int res = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {
		res += c[i];
	}
	return res;
}

int main()
{
	int x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		if (maxx < x + 1) {
			maxx = x + 1;
		}
		node[i] = { x + 1,y };
	}
	sort(node, node + n, cmp);
	for (int i = 0; i < n; i++) {
		ans[ask(node[i].x)]++;
		upd(node[i].x);
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}