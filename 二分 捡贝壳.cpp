//问题描述
//war发现海边还有好看的贝，他把n个贝壳依次排成一排，第i个贝壳的体积为vi。
//war觉得平均体积最大，且长度不小于m的一段贝壳最好看。请你帮他找出这一段～
//
//输入描述
//第一行为n(1≤n≤10 ^ 5)，m(m≤n)。第二行n个数，第i个数为vi(0≤vi≤2000)，中间有空格。
//
//输出描述
//输出一个整数，表示这个平均体积的1000倍。不用四舍五入，直接输出。
//提示：二分答案，前缀和
//
//样例输入
//12 6
//1
//1
//1
//1
//1
//1
//1
//1
//1
//1
//1
//1
//
//样例输出
//1000

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> nums, double avg, int m) {
	double sum = 0, pre = 0, premin = 0;
	for (int i = 0; i < m; i++) {
		sum += nums[i] - avg;
	}
	if (sum >= 0) {
		return true;
	}
	for (int i = m; i < nums.size(); i++)
	{
		sum += nums[i] - avg;
		pre += nums[i - m] - avg;
		premin = min(pre, premin);
		if (sum - premin >= 0) {
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> nums;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		nums.push_back(x);
	}

	double l = 0, r = 2048, mid;
	int ans;
	while (r - l > 1e-6) {
		mid = l + (r - l) / 2.0;
		if (check(nums, mid, m)) {
			l = mid;
		}
		else
		{
			r = mid;
			ans = 1000 * mid;
		}
	}

	cout << ans << endl;
	return 0;

}