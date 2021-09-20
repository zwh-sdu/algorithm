//问题描述
//小H收集到一些形状特殊的棋盘，她想在棋盘上面摆放棋子（棋子都是相同的）。
//她希望摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，
//你能帮她求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案数C嘛？
//
//输入格式
//输入含有多组测试数据。
//每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n* n的矩阵内描述棋盘，以及摆放棋子的数目。
//当为 - 1 - 1时表示输入结束。
//随后的n行描述了棋盘的形状：
//每行有n个字符，其中 # 表示棋盘区域，.表示空白区域（数据保证不出现多余的空白行或者空白列）。
//注意只有#棋盘区域可以摆放棋子。
//
//输出格式
//对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C < 2 ^ 31）
//
//样例输出
//2 1
//#.
//.#
//4 4
//...#
//..#.
//.#..
//#...
//- 1 - 1
//
//样例输出
//2
//1

#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstring>
#include<algorithm>
using namespace std;

char a[8][8];
int n, k, num = 0;
int c;
int vis[8];

void dfs(int x) {
	if (num == k) {
		c++;
		return;
	}
	if (x >= n) {
		return;
	}
	for (int i = 0; i < n; i++) {
		if (vis[i] == 0 && a[x][i] == '#') {
			vis[i] = 1;
			num++;
			dfs(x + 1);
			vis[i] = 0;
			num--;
		}
	}
	dfs(x + 1);

}

int main()
{
	while (true) {
		c = 0;
		cin >> n >> k;
		if (n == -1 && k == -1) {
			break;
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cin >> a[i][j];
				}
			}
			memset(vis, 0, sizeof(vis));
			dfs(0);
			cout << c << "\n";
		}
	}
	return 0;
}