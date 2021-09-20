//问题描述
//化学方程式，也称为化学反应方程式，是用化学式表示化学反应的式子。
//给出一组化学方程式，请你编写程序判断每个方程式是否配平（也就是方程式中等号左右两边的元素种类和对应的原子个数是否相同)。
//本题给出的化学方程式由大小写字母、数字和符号(包括等号 = 、加号 + 、左圆括号(和右圆括号))组成，
//不会出现其他字符（包括空白字符，如空格、制表符等)。
//化学方程式的格式与化学课本中的形式基本相同（化学式中表示元素原子个数的下标用正常文本，如 H_2O 写成 H2O)
//
//输入格式
//从标准输入读入数据。
//输入的第一行包含一个正整数n，表示输入的化学方程式个数。接下来 n 行，每行是一个符合定义的化学方程式。
//
//输出格式
//输出到标准输出。
//输出共 n 行，每行是一个大写字母 Y 或 N，回答输入中相应的化学方程式是否配平。
//
//样例输入
//11
//H2 + O2 = H2O
//2H2 + O2 = 2H2O
//H2 + Cl2 = 2NaCl
//H2 + Cl2 = 2HCl
//CH4 + 2O2 = CO2 + 2H2O
//CaCl2 + 2AgNO3 = Ca(NO3)2 + 2AgCl
//3Ba(OH)2 + 2H3PO4 = 6H2O + Ba3(PO4)2
//3Ba(OH)2 + 2H3PO4 = Ba3(PO4)2 + 6H2O
//4Zn + 10HNO3 = 4Zn(NO3)2 + NH4NO3 + 3H2O
//4Au + 8NaCN + 2H2O + O2 = 4Na(Au(CN)2) + 4NaOH
//Cu + As = Cs + Au
//
//样例输出
//N
//Y
//N
//Y
//Y
//Y
//Y
//Y
//Y
//Y
//N

#include<bits/stdc++.h>
using namespace std;

struct elemset
{
	map<string, int> mp;
	void operator += (const elemset& s) {
		for (auto& x : s.mp) {
			mp[x.first] += x.second;
		}
	}
	bool operator == (const elemset& s) const {
		return mp == s.mp;
	}
	void operator *= (const int v) {
		for (auto& x : mp) {
			x.second *= v;
		}
	}
};

vector<string> split(const string& s, char c) {
	vector<string> res;
	stringstream ss(s);
	string temp;
	while (getline(ss, temp, c)) {
		res.push_back(temp);
	}
	return res;
}

int getnum(string& s, int& pos) {
	int res = 0;
	while (pos < s.size() && isdigit(s[pos])) {
		res = res * 10 + s[pos++] - '0';
	}
	return res == 0 ? 1 : res;
}

string getele(string& s, int& pos) {
	string res = "";
	res += s[pos++];
	if (islower(s[pos])) res += s[pos++];
	return res;
}

elemset getmp(string& s, int& pos) {
	elemset res;
	int xishu = getnum(s, pos);
	while (pos < s.size()) {
		if (s[pos] == '(') res += getmp(s, ++pos);
		else if (s[pos] == ')') {
			res *= getnum(s, ++pos);
			return res;
		}
		else {
			string temp = getele(s, pos);
			int t = getnum(s, pos);
			res.mp[temp] += t;
		}
	}
	res *= xishu;
	return res;
}

bool solve(string s) {
	vector<string> fms = split(s, '=');
	elemset res[2];
	for (int i = 0; i < fms.size(); i++) {
		vector<string> element = split(fms[i], '+');
		for (int j = 0; j < element.size(); j++) {
			int pos = 0;
			res[i] += getmp(element[j], pos);
		}
	}
	return res[0] == res[1];
}

int main()
{
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (solve(s)) cout << "Y" << "\n";
		else cout << "N" << "\n";
	}
	return 0;
}