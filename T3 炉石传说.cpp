#include <bits/stdc++.h>
using namespace std;

int n, position, health, attack, turn, attacker, defender;
string s;

struct node
{
	int health, attack;
	node(int _health, int _attack)
	{
		health = _health;
		attack = _attack;
	}
};

vector<node> v[2];

int main()
{
	cin >> n;
	v[0].push_back({30, 0});
	v[1].push_back({30, 0});
	while (n--)
	{
		cin >> s;
		if (s == "summon")
		{
			cin >> position >> attack >> health;
			v[turn].insert(v[turn].begin() + position, node(health, attack));
		}
		else if (s == "attack")
		{
			cin >> attacker >> defender;
			v[turn][attacker].health -= v[1 - turn][defender].attack;
			v[1 - turn][defender].health -= v[turn][attacker].attack;
			if (v[turn][attacker].health <= 0)
				v[turn].erase(v[turn].begin() + attacker);
			if (defender != 0 && v[1 - turn][defender].health <= 0)
				v[1 - turn].erase((v[1 - turn].begin() + defender));
		}
		else if (s == "end")
			turn = 1 - turn;
	}
	//输出结果
	if (v[0][0].health <= 0)
		cout << -1 << endl;
	else if (v[1][0].health <= 0)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	for (int k = 0; k < 2; k++)
	{
		cout << v[k][0].health << endl;
		cout << v[k].size() - 1;
		for (int i = 1; i < v[k].size(); i++)
			cout << " " << v[k][i].health;
		cout << endl;
	}

	system("pause");
	return 0;
}