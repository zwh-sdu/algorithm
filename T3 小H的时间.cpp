//问题描述
//小H有两块用于显示时间的LCD显示器，第一个显示器显示的时间为当前时间，而第二个显示器显示的时间比当前时间晚15分钟。
//两个显示器都只能显示4个整数，每个整数占用3 * 3的字符矩阵，
//包含’ | ’, ’_’和空格三种字符，当显示器正常工作时，0-9的显示如下方所示
// _     _  _     _  _  _  _  _
//| |  | _| _||_||_ |_   ||_||_|
//|_|  ||_  _|  | _||_|  ||_| _|
//所以如果当前时间为9:30，则第一块显示器会显示0930，第二块显示器会显示0915。
//现在小H不小心损坏了两块显示器，显示器中的某些位置的字符无法正常显示了（注：无法显示的地方会变成空格），
//而他迫切的想要知道当前时间，你能帮帮他吗？
//
//输入格式
//第一行一个整数t，表示测试数据组数
//对于每个测试数据，包含3行，依次表示第一个显示器显示的时间和第二个显示器显示的时间，两者之间用空白列隔开
//
//输出格式
//对于每一组测试数据，如果有唯一确定的时间则输出当前时间，否则输出"Not Sure"
//
//样例输入
//2
//_  _  _      _     _
//| _  _ || _   ||
//| _ | _   |   | _ | _ |
//_  _  _   _  _     _
//|| _  _ || _|  ||
//| _ | _   |   ||     |_ |
//
//样例输出
//Not Sure
//0825

#include<bits/stdc++.h>
using namespace std;
vector<int> a[8];
string s[3] = { " _     _  _     _  _  _  _  _ ","| |  | _| _||_||_ |_   ||_||_|","|_|  ||_  _|  | _||_|  ||_| _|" };
bool check(int x1, int x2, string my[3]) {
	if (x2 <= 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 3 * x1, k = 3 * x2; j < 3 * (x1 + 1); j++, k++) {
				if (s[i][j] != my[i][k] && my[i][k] != ' ') {
					return 0;
				}
			}
		}
		return 1;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 3 * x1, k = 3 * x2 + 1; j < 3 * (x1 + 1); j++, k++) {
				if (s[i][j] != my[i][k] && my[i][k] != ' ') {
					return 0;
				}
			}
		}
		return 1;
	}
}

int main()
{
	int t;
	cin >> t;
	string my[3];
	getchar();
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 3; j++) {
			getline(cin, my[j]);
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 10; j++) {
				if (check(j, i, my)) {
					if (i == 0 || i == 4) {
						if (j <= 2) {
							a[i].push_back(j);
						}
						continue;
					}
					else if (i == 2 || i == 6) {
						if (j <= 6) {
							a[i].push_back(j);
						}
						continue;
					}
					a[i].push_back(j);
				}
			}
		}

		vector<int> t1;
		vector<int> t2;
		int cnt = 0;
		int ans;
		for (int i1 = 0; i1 < a[0].size(); i1++) {
			for (int i2 = 0; i2 < a[1].size(); i2++) {
				for (int i3 = 0; i3 < a[2].size(); i3++) {
					for (int i4 = 0; i4 < a[3].size(); i4++) {
						int temp1 = a[0][i1] * 10 + a[1][i2];
						int temp2 = a[2][i3] * 10 + a[3][i4];
						if (temp1 <= 24 && temp2 <= 59) {
							t1.push_back(100 * temp1 + temp2);
						}
					}
				}
			}
		}
		for (int i1 = 0; i1 < a[4].size(); i1++) {
			for (int i2 = 0; i2 < a[5].size(); i2++) {
				for (int i3 = 0; i3 < a[6].size(); i3++) {
					for (int i4 = 0; i4 < a[7].size(); i4++) {
						int temp1 = a[4][i1] * 10 + a[5][i2];
						int temp2 = a[6][i3] * 10 + a[7][i4];
						if (temp1 <= 24 && temp2 <= 59) {
							t2.push_back(100 * temp1 + temp2);
						}
					}
				}
			}
		}
		bool p = 1;
		for (int i = 0; i < t1.size() && p; i++) {
			for (int j = 0; j < t2.size() && p; j++) {

				if (t2[j] / 100 == t1[i] / 100 && t2[j] + 15 == t1[i]) {
					cnt++;
					ans = t1[i];
				}
				else if (t2[j] / 100 + 1 == t1[i] / 100 && t2[j] + 55 == t1[i]) {
					cnt++;
					ans = t1[i];
				}
				else if (t2[j] >= 2345 && t1[i] == t2[j] - 2345) {
					cnt++;
					ans = t1[i];
				}
				if (cnt > 1) {
					p = 0;
					cout << "Not Sure" << endl;
				}
			}
		}
		if (cnt == 1) {
			if (ans < 1000 && ans >= 100) {
				cout << '0' << ans << endl;
			}
			else if (ans < 100 && ans >= 10) {
				cout << "00" << ans << endl;
			}
			else if (ans < 10) {
				cout << "000" << ans << endl;
			}
			else {
				cout << ans << endl;
			}
		}
		if (cnt == 0) {
			cout << "Not Sure" << endl;
		}
		t1.clear();
		t2.clear();
		for (int i = 0; i < 8; i++) {
			a[i].clear();
		}
	}
	return 0;
}