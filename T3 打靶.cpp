//问题描述
//某一天，小L 又跟 小W 比英语成绩，但是由于 小W 太强了，小L 惨败，
//于是 小L 想使用自己更擅长的射击与 小W 一较高下。
//他们来到了靶场，靶场是一个矩形的空地，在其左下角建立二维直角坐标系，整个靶场处于坐标系的第一象限，
//第 i 个靶子的位置可以使用(x_i, y_i)进行描述，其中 x_i, y_i均为正整数，同一个位置至多有一个靶子。
//初始时小L在(0, 1)(0, 1) 且只能向 x 轴正半轴方向射击，小W在(1, 0)(1, 0) 且只能向 y 轴正半轴方向射击。
//两人轮流进行行动，小L先进行操作，行动分为两种：
//1.射击：当正对的方向有靶子时，进行射击操作。
//  每次开枪射出 1 颗子弹，靶子与射出的子弹在相遇后均会立刻消失，此时靶子算作被开枪的人打中。
//  由于 小L 在打靶方面有特殊的技巧，所以 小L 一次射击操作可以开 c 枪，而 小W 只能开 11 枪。
//2.移动：当正对的方向没有靶子时，小L 与 小W 会分别向 y 轴正方向与 x 轴正方向移动，
//  每次操作可以分别移动最多 d_L, d_Wd单位距离，移动会在第一个射击方向有靶子可打的地方立刻停止。
//
//当整个场地中没有可以打的靶子时，比赛立刻结束，他们将以打靶的数量决定输赢。
//由于两人专心射击，无法统计击中的靶子数量，请你帮助他们统计两人分别击中的靶子的数量。
//
//输入格式
//输入的第 11 行包含 44 个数，n, c, d_L, d_W分别表示靶子的数量，
//小L 一次射击操作可以开枪的次数，小L 一次移动操作可移动的最大距离，小W 一次移动操作可移动的最大距离。
//接下来的 n 行，每行两个数 x_i, y_i表示靶子的位置。
//
//输出格式
//输出一行两个整数，以空格隔开，分别表示小L 与 小W 击中的靶子的数量。
//
//样例输入
//8 2 4 1
//1 1
//6 7
//1 7
//3 5
//6 2
//3 6
//8 2
//4 2
//
//样例输出
//5 3

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, c, dl, dw;
set<pair<LL, LL> > L, W;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> c >> dl >> dw;
	LL x, y;
	for (LL i = 0; i < n; i++) {
		cin >> x >> y;
		L.emplace(y, x);
		W.emplace(x, y);
	}
	LL pl = 1, pw = 1;
	LL ansl = 0, answ = 0;
	while (!L.empty() && !W.empty()) {
		LL nl = L.begin()->first - pl;
		LL nw = W.begin()->first - pw;
		if (nl > dl && nw > dw) {
			LL b = min(nl / dl, nw / dw);
			pl += dl * b;
			pw += dw * b;
		}
		if (pl != L.begin()->first)
			pl = min(pl + dl, L.begin()->first);
		else {
			for (int i = 0; i < c && !L.empty() && pl == L.begin()->first; i++) {
				W.erase({ L.begin()->second, L.begin()->first });
				L.erase(L.begin());
				ansl++;
			}
		}
		if (!W.empty() && pw != W.begin()->first)
			pw = min(pw + dw, W.begin()->first);
		else {
			if (!W.empty() && pw == W.begin()->first) {
				L.erase({ W.begin()->second,W.begin()->first });
				W.erase(W.begin());
				answ++;
			}
		}
	}
	cout << ansl << " " << answ << endl;
	return 0;
}