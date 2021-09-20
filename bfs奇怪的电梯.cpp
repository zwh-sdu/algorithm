//问题描述
//小H有一个奇怪的电梯，电梯可以根据需要停在每个楼层，每个楼层上都对应一个数字K(i) (0<=K(i)<=N),
//该电梯只有两个按钮：“UP"和"DOWN”。在第i层楼，如果按下"UP"按钮，电梯将移动到i+K(i)层；
//如果按下"DOWN"，电梯将移动到i=K(i)层；当然，电梯有一个移动的范围，不能高于N且不能低于1。
//现在问题来了：小H想从A层移动到B层，他至少要按几次"UP"或"DOWN"按钮，你能帮帮他嘛？
//
//输入格式
//输入包含多个测试用例。每个测试用例包含两行。
//第一行包含上述三个整数N，A，B  (1<=N,A,B<=200),第二行包含N个整数k1，k2 。。。kn；
//若读取到单个0，则表示输入结束
//
//输出格式
//对于每个测试用例，输出一个整数表示最少按下"UP"或"DOWN"按钮的次数，
//若无法到达B层，请输出"-1"。每个测试用例的输出占一行。
//
//样例输入
//5 1 5
//3 3 1 2 5
//0
//
//样例输出
//3

#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct node {
	int x, t;
	node(int _x, int _t) {
		x = _x;
		t = _t;
	}
};

int bfs(int a, int b);

int n, a, b;
int k[210];
int vis[210] = { 0 };

int main()
{
	while (true) {

		cin >> n;
		if (n == 0) {
			break;
		}
		else {
			cin >> a >> b;
			for (int i = 1; i <= n; i++) {
				int x;
				cin >> x;
				k[i] = x;
			}
			cout << bfs(a, b) << "\n";
		}
	}
	return 0;

}
int bfs(int a, int b) {
	queue<node> q;
	memset(vis, 0, sizeof(vis));
	q.push(node(a, 0));
	vis[a] = 1;
	while (!q.empty()) {
		node temp = q.front();
		q.pop();
		if (temp.x == b) {
			return temp.t;
		}
		if (temp.x - k[temp.x] >= 1 && vis[temp.x - k[temp.x]] == 0) {
			q.push(node(temp.x - k[temp.x], temp.t + 1));
			vis[temp.x - k[temp.x]] = 1;
		}
		if (temp.x + k[temp.x] <= n && vis[temp.x + k[temp.x]] == 0) {
			q.push(node(temp.x + k[temp.x], temp.t + 1));
			vis[temp.x + k[temp.x]] = 1;
		}

	}
	return -1;
}