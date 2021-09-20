//题目描述
//众所周知，打球是一件非常快乐的事情，但是约球却并不容易。
//给出每个球友的各项事情的时间表，你的任务是找出所有可以用来打球的时间段。
//
//输入
//第一行，输入一个整数数 T（T≤100），表示接下来要输入的数据组数。
//对于接下来的每组数据，第一行输入一个整数 m（2≤m≤20），表示球友的数量。
//对于每位球友，首先是一个整数 n（0≤n≤100），表示该球友的任务数。接下来n行，表示各个任务的信息，格式如下：
//
//YYYY MM DD hh mm ss YYYY MM DD hh mm ss There are some strings here
//每一行描述的信息为：
//
//开始时间的年、月、日、时、分、秒；
//结束时间的年、月、日、时、分、秒；
//以及一些字符串，描述任务的信息。
//所有数值为固定位数，位数不足会补前导0，数据间由空格隔开。
//描述任务的字符串中可以有空格，但总长度小于等于 100。
//所有的日期时间均在1800年1月1日00 : 00 : 00到2200年1月1日00 : 00 : 00之间。
//	简化一下该问题，假设每个月（1~12月）都是 30 天，数据保证不含有不合法的日期。
//	注意每件事务的结束时间点也即是该成员可以开始打球的时间点。
//
//输出要求
//对于每组数据，开头先输出一行 Scenario #i : ，i 等于当前数据组数
//接下来对于所有可以用来打球的时间段，每一个时间段输出一行。
//
//样例输入
//2
//3
//2
//1874 03 04 10 21 36 1895 09 28 00 24 41 yhf is coding.
//2050 09 10 02 30 01 2199 02 09 06 07 15 sysand yhf are coding.
//2
//1810 04 05 05 03 39 1834 01 15 03 55 55 war is coding.
//1949 02 29 02 14 56 2189 12 01 05 22 47 hxy is coding.
//0
//3
//0
//2
//2108 07 18 08 26 00 2135 03 30 04 20 30 I am so happy
//2140 02 19 00 01 36 2190 04 18 11 54 09 Me too
//0
//
//样例输出
//Scenario #1:
//appointment possible from 01 / 01 / 1800 00 : 00 : 00 to 09 / 10 / 2050 02:30 : 01
//appointment possible from 12 / 01 / 2189 05 : 22 : 47 to 01 / 01 / 2200 00 : 00 : 00
//
//Scenario #2:
//appointment possible from 01 / 01 / 1800 00 : 00 : 00 to 01 / 01 / 2200 00 : 00 : 00

#include<bits/stdc++.h>
using namespace std;

struct tim
{
	int year, month, day, hour, minu, sec;
	bool operator < (const tim& b) const {
		if (year < b.year) {
			return true;
		}
		else if (year == b.year) {
			if (month < b.month) {
				return true;
			}
			else if (month == b.month) {
				if (day < b.day) {
					return true;
				}
				else if (day == b.day) {
					if (hour < b.hour) {
						return true;
					}
					else if (hour == b.hour) {
						if (minu < b.minu) {
							return true;
						}
						else if (minu == b.minu) {
							if (sec < b.sec) {
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	}
};

bool cmp(tim a, tim b) {
	if (a.year < b.year) {
		return true;
	}
	else if (a.year == b.year) {
		if (a.month < b.month) {
			return true;
		}
		else if (a.month == b.month) {
			if (a.day < b.day) {
				return true;
			}
			else if (a.day == b.day) {
				if (a.hour < b.hour) {
					return true;
				}
				else if (a.hour == b.hour) {
					if (a.minu < b.minu) {
						return true;
					}
					else if (a.minu == b.minu) {
						if (a.sec < b.sec) {
							return true;
						}
					}
				}
			}
		}

	}
	return false;

}

vector<tim> sta, en, ans;

int main()
{
	int t;
	cin >> t;
	int tt = t;
	while (t--) {
		sta.clear();
		en.clear();
		ans.clear();
		int m, n;
		cin >> m;
		int num = m, tot = m;
		while (tot--) {
			cin >> n;
			if (n == 0) {
				continue;
			}
			while (n--) {
				tim temp;
				cin >> temp.year >> temp.month >> temp.day >> temp.hour >> temp.minu >> temp.sec;
				sta.push_back(temp);
				cin >> temp.year >> temp.month >> temp.day >> temp.hour >> temp.minu >> temp.sec;
				en.push_back(temp);
				string s;
				getline(cin, s);
			}
		}
		sort(sta.begin(), sta.end(), cmp);
		sort(en.begin(), en.end(), cmp);
		int s = 0, e = 0, flag = 1;
		ans.push_back({ 1800,1,1,0,0,0 });
		while (e < en.size()) {
			if (s < sta.size() && sta[s] < en[e]) {
				num--;
				if (m - num <= 1 && num >= 2) {
					s++;
				}
				else {
					if (flag == 0) {
						s++;
						continue;
					}
					ans.push_back(sta[s]);
					flag = 0;
					s++;
				}
			}
			else {
				num++;
				if (m - num <= 1 && num >= 2) {
					if (flag == 0) {
						ans.push_back(en[e]);
						flag = 1;
						e++;
					}
					else {
						e++;
					}
				}
				else {
					e++;
				}
			}
		}
		if (flag == 1) {
			ans.push_back({ 2200,1,1,0,0,0 });
		}
		cout << "Scenario #" << tt - t << ":" << "\n";
		for (int i = 0; i < ans.size() - 1; i += 2) {
			if (ans[i].year == ans[i + 1].year && ans[i].month == ans[i + 1].month && ans[i].day == ans[i + 1].day && (ans[i].hour == ans[i + 1].hour || ans[i].hour == ans[i + 1].hour - 1)) {
				continue;
			}
			cout << "appointment possible from ";
			if (ans[i].month < 10) {
				cout << 0 << ans[i].month << "/";
			}
			else {
				cout << ans[i].month << "/";
			}
			if (ans[i].day < 10) {
				cout << 0 << ans[i].day << "/";
			}
			else {
				cout << ans[i].day << "/";
			}
			cout << ans[i].year << " ";
			if (ans[i].hour < 10) {
				cout << 0 << ans[i].hour << ":";
			}
			else {
				cout << ans[i].hour << ":";
			}
			if (ans[i].minu < 10) {
				cout << 0 << ans[i].minu << ":";
			}
			else {
				cout << ans[i].minu << ":";
			}
			if (ans[i].sec < 10) {
				cout << 0 << ans[i].sec << " ";
			}
			else {
				cout << ans[i].sec << " ";
			}

			cout << "to ";

			if (ans[i + 1].month < 10) {
				cout << 0 << ans[i + 1].month << "/";
			}
			else {
				cout << ans[i + 1].month << "/";
			}
			if (ans[i + 1].day < 10) {
				cout << 0 << ans[i + 1].day << "/";
			}
			else {
				cout << ans[i + 1].day << "/";
			}
			cout << ans[i + 1].year << " ";
			if (ans[i + 1].hour < 10) {
				cout << 0 << ans[i + 1].hour << ":";
			}
			else {
				cout << ans[i + 1].hour << ":";
			}
			if (ans[i + 1].minu < 10) {
				cout << 0 << ans[i + 1].minu << ":";
			}
			else {
				cout << ans[i + 1].minu << ":";
			}
			if (ans[i + 1].sec < 10) {
				cout << 0 << ans[i + 1].sec << " ";
			}
			else {
				cout << ans[i + 1].sec << " ";
			}
			cout << "\n";

		}

	}
	return 0;
}