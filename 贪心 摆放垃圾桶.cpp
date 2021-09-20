//问题描述
//滨海公园旁边新铺了一条路，把这条路分成n段，依次编号为1…n。
//为了防止游客把垃圾扔到海里，war要在路上放一些垃圾。
//政府提出了m个要求，每个要求包含三个整数l，r，k，表示路段l到r之间至少有k个垃圾桶 。
//垃圾桶放太多不仅浪费资源，也影响风景，所以每个路段至多可以放一个垃圾桶。
//为了环保，war最少要放多少个垃圾桶才能满足要求？
//
//输入描述
//一行为n(1≤n≤3 * 10 ^ 4)，表示路段数。
//第二行为m(1≤m≤5000)，表示要求数。
//下面m行，每行描述一条建议l，r，k，用一个空格分隔，(1≤l≤r≤3 * 10 ^ 4, k≤r - l + 1)
//
//输出描述
//输出只有一个数，为满足政府所有的要求，需要的垃圾桶的最少数量。
//
//样例输入
//9
//4
//1 4 2
//4 6 1
//8 9 2
//3 5 2
//
//样例输出
//4

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<numeric>
using namespace std;

struct bin
{
	int l, r, k;
};

bool cmp(bin a, bin b) {
	if (a.r == b.r) {
		return a.l < b.l;
	}
	else {
		return a.r < b.r;
	}
}

int main()
{
	int n, m, ans;
	cin >> n >> m;
	vector<bin> rub = {};
	vector<int> have(n, 0);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		rub.push_back(bin{ a - 1,b - 1,c });
	}

	sort(rub.begin(), rub.end(), cmp);

	while (!rub.empty()) {
		int now = 0;
		bin temp = rub.front();
		rub.erase(rub.begin());
		for (int j = temp.l; j <= temp.r; j++) {
			if (have[j] == 1) {
				now++;
			}
		}
		if (now >= temp.k) {
			continue;
		}
		else {
			int x = temp.r;
			while (now != temp.k) {
				if (have[x] == 0) {
					have[x] = 1;
					now++;
				}
				else {
					x--;
				}
			}
		}
	}
	ans = accumulate(have.begin(), have.end(), 0);
	cout << ans << endl;
	return 0;
}