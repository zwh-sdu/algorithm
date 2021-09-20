#include <bits/stdc++.h>
using namespace std;

int p, r, u, q, n;
string s;
struct node
{
	string role;
	int num;
	node(string _role, int _num)
	{
		role = _role;
		num = _num;
	}
};

int main()
{
	map<string, vector<node>> mp;
	map<string, map<string, int>> mpp;
	cin >> p;
	while (p--)
		cin >> s;
	cin >> r;
	string role, pri;
	int count;
	while (r--)
	{
		cin >> role >> count;
		vector<node> temp;
		while (count--)
		{
			cin >> pri;
			if (pri.find(":") != pri.npos)
			{
				int d = pri.find(":");
				temp.push_back(node(pri.substr(0, d), pri[d + 1] - '0'));
			}
			else
			{
				temp.push_back(node(pri, -1));
			}
		}
		mp.insert(make_pair(role, temp));
	}
	cin >> u;
	string user;
	while (u--)
	{
		map<string, int> temp;
		cin >> user >> count;
		while (count--)
		{
			cin >> role;
			for (int i = 0; i < (mp.find(role)->second).size(); i++)
			{
				string tempri = (mp.find(role)->second)[i].role;
				int tempnum = (mp.find(role)->second)[i].num;
				if (temp.find(tempri) != temp.end())
				{
					if (tempnum != -1 && (temp.find(tempri)->second) < tempnum)
					{
						temp.find(tempri)->second = tempnum;
					}
				}
				else
				{
					temp.insert(make_pair(tempri, tempnum));
				}
			}
		}
		mpp.insert(make_pair(user, temp));
	}
	cin >> q;
	while (q--)
	{
		int num = -1;
		cin >> user >> pri;
		if (pri.find(":") != pri.npos)
		{
			int d = pri.find(":");
			num = pri[d + 1] - '0';
			pri = pri.substr(0, d);
		}
		if (mpp.find(user) == mpp.end())
			cout << "false" << endl;
		else
		{
			map<string, int> tempp = mpp.find(user)->second;
			if (tempp.find(pri) == tempp.end())
				cout << "false" << endl;
			else
			{
				if (num == -1)
				{
					if (tempp.find(pri)->second == -1)
						cout << "true" << endl;
					else
						cout << tempp.find(pri)->second << endl;
				}
				else
				{
					if (num <= tempp.find(pri)->second)
						cout << "true" << endl;
					else
						cout << "false" << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}