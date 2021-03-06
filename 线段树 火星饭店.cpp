//问题描述
//lzh 在火星开了一家饭店，为了吸引顾客，饭店会不定期在菜谱中加入新菜，每个菜都有一个美味度(0≤l < p)。
//饭店使用手机进行点餐，手机上展示的菜谱会按照更新的顺序逆序排列。
//由于不同顾客的手机屏幕分辨率大小不同，所以能够显示在第一屏的菜谱的数量也不同。
//根据调查发现，火星用户只会在第一屏的菜品中选择美味度最高的购买。
//现在按照时间顺序输入 m 个添加菜品或顾客点菜的操作，请输出每位点菜顾客所点的菜的美味度。
//
//输入格式
//第一行有两个正整数m, p，意义如题目描述；
//接下来 m 行，每一行表示一个操作。
//如果该行的内容是 Q L，则表示有顾客进行了点菜，该顾客的手机屏幕可以显示 LL 个菜品；
//如果是 A t，则表示加入了新的菜品，菜品的美味度是(t + a)modp。
//t 是输入的参数
//a 是在这个添加操作之前最后一个点菜操作的答案（如果之前没有点菜操作，则 a = 0）。
//数据保证第一个操作一定是添加菜品。在顾客点菜时，L > 0 且不超过当前已有菜品的数量。
//
//输出格式
//对于每一个点菜操作，输出一行。该行只有一个数，即当前屏幕中美味度最大的菜品的美味度。
//
//样例输入
//10 100
//A 97
//Q 1
//Q 1
//A 17
//Q 2
//A 63
//Q 1
//Q 1
//Q 3
//A 99
//
//样例输出
//97
//97
//97
//60
//60
//97

#include<bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int c[MAXN];
int m, p, a, t, i;

void upd(int x, int l, int r) {
	if (l == r) {
		c[x] = (t + a) % p;
		return;
	}
	int mid = (l + r) / 2;
	if (i <= mid) {
		upd(x * 2, l, mid);
	}
	else {
		upd(x * 2 + 1, mid + 1, r);
	}
	c[x] = max(c[x * 2], c[x * 2 + 1]);
}

int ask(int x, int l, int r, int ll, int rr) {
	if (l == ll && r == rr) {
		return c[x];
	}
	int m = (l + r) / 2;
	if (rr <= m) {
		return ask(x * 2, l, m, ll, rr);
	}
	else if (ll > m) {
		return ask(x * 2 + 1, m + 1, r, ll, rr);
	}
	else {
		return max(ask(x * 2, l, m, ll, m), ask(x * 2 + 1, m + 1, r, m + 1, rr));
	}
}

int main()
{
	char op;
	int mm;
	cin >> m >> p;
	mm = m;
	while (m--) {
		cin >> op >> t;
		if (op == 'A') {
			i++;
			upd(1, 1, mm);
		}
		else {
			a = ask(1, 1, mm, i - t + 1, i);
			cout << a << endl;
		}
	}
	return 0;
}