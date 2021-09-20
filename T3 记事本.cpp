//问题描述
//光标移动
//光标表示当前要进行输入等操作的位置，在本题中，我们假设所有字符都是等宽的。
//光标的位置可以用行列坐标来描述，光标所在的行和列均从1开始，以下操作可以进行光标的移动，
//使用 MOVE <comd> 输入相关的操作，其中 <comd> 表示指令，可以使用以下字符串代替：
//	Home：把光标移动到当前行的开头。
//	End：把光标移动到当前行的末尾。
//	Up：光标移动到上一行的相同列。
//	若当前为第一行，则不进行任何操作。
//	若上一行的列数小于当前光标的列数，则将光标移动到上一行的末尾。
//	Down：光标移动到下一行的相同列。
//	若当前为最后一行，则不进行任何操作。
//	若下一行的列数小于当前光标的列数，则将光标移动到下一行的末尾。
//	Left：光标左移一位。
//	若当前光标位于记事本开始，则不进行任何操作。
//	若当前光标处于某一行的开头，则将光标移动到上一行的末尾。
//	Right：光标右移一位。
//	若当前光标位于记事本末尾，则不进行任何操作。
//	若当前光标处于某一行的末尾，则将光标移动到下一行的开头。
//
//输入
//以下操作可以在光标后进行输入，使用 INSERT <comd> 输入相关的操作，其中 <comd> 表示指令，可以使用以下字符串代替：
//	Char <char>：输入一个字符，其中 <char> 是输入的字符。
//	Enter：输入换行符，并进行换行。
//	Space：输入空格。
//	Paste：在当前光标后，插入粘贴板中的内容，若粘贴板中无内容，则忽略当前操作。
//
//删除
//以下操作可以删除记事本中的内容，使用 REMOVE <comd> 输入相关的操作，其中 <comd> 表示指令，可以使用以下字符串代替：
//	Del：删除当前光标位置之后的一个字符。
//	若该字符为换行符，则当前行与下一行合并为一行。
//	若当前光标在文件末尾，则忽略当前操作。
//	Backspace：删除当前光标位置之前的一个字符。
//	若该字符为换行符，则当前行与上一行合并为一行。
//	若当前光标在文件开头，则忽略当前操作。
//
//粘滞功能（分数占比 24分）
//输入SHIFT指令，可以启动或关闭粘滞功能。
//
//	开始时粘滞功能默认为关闭状态，之后每次点击：
//	若当前为启动状态，则关闭；
//	若当前为关闭状态，则启动。
//	粘滞功能启动时，记录当前的光标位置为 记录点。
//	粘滞功能关闭时，若此时的光标位置与 记录点 的位置不同，则进入选中状态。
//	粘滞功能启动后，直到功能关闭前，不会对记事本进行除光标移动外的任何操作。
//当进入选中状态后，通过记录点与当前光标，可以唯一的确定一段内容，
//现令记录点与光标之间的所有字符（包括换行符）为 选中字段。
//
//当前 处于选中状态 时，对于不同的情况，需要按照序号依次执行以下操作：
//	若进行光标移动：
//		退出选中状态；
//		尝试进行光标的移动（无论光标最终是否移动，都会退出选中状态）。
//	若进行输入：
//		将选中内容替换为输入内容；
//		退出选中状态。
//	若进行删除：
//		删除当前选中内容；
//		退出选中状态。
//	若再次启动粘滞功能：退出选中状态，但保留上一次选中字段的 记录点 作为当前记录点。
//	若进行查找，字数统计，复制，打印操作，则在操作后仍然保持选中状态。
//
//查找
//输入FIND <word> 指令，进行字符串查找，其中 <word> 为输入的要查找的字符串，该字符串中不包含空格与换行符。
//	执行该指令时，要根据当前是否处于选中状态做不同的处理：
//		若当前处于选中状态：查找输入字符串在选中字段中的出现次数并输出。
//		否则：查找输入字符串在当前记事本中的出现次数并输出。
//	例如：当前没有选中的内容，且记事本中的内容为 ababa，若执行 FIND aba，则应当输出2，分别在第1列与第3列出现过。
//
//字数统计
//	输入COUNT 指令，进行字数统计。
//	执行该指令时，要根据当前是否处于选中状态做不同的处理：
//		若当前处于选中状态：输出当前选中字段中的可见字符（不包括空格与换行符）的数量。
//		否则：输出当前文档中可见字符（不包括空格与换行符）的数量。
//
//复制
//输入COPY指令，进行复制操作。
//	执行该指令时，要根据当前是否处于选中状态做不同的处理：
//		若当前处于选中状态：复制选中字段到粘贴板；
//		否则，
//			若当前行不为空：复制当前行的内容（不包括换行符）到粘贴板；
//			否则：忽略当前操作。
//
//打印
//输入PRINT 指令，输出当前的记事本中的全部内容，并在之后输出一个换行符。
//
//
//输入格式
//输入包含 n + 1 行。
//第一行包含一个整数 n，表示接下来指令的数量。
//接下来 n 行，每行一条指令，格式形如题目描述中的叙述。
//
//输出格式
//对于需要输出的指令，进行相应的输出。
//若为 FIND 与 COUNT 操作，输出一行表示相应的数字。
//若为 PRINT操作，则输出若干行，表示记事本的当前内容，并在之后输出一个换行。
//
//
//样例输入
//20
//INSERT Char #
//INSERT Enter
//INSERT Char C
//INSERT Enter
//INSERT Space
//INSERT Char _
//INSERT Char _
//PRINT
//INSERT Char >
//INSERT Enter
//INSERT Char h
//INSERT Char h
//INSERT Char h
//INSERT Enter
//PRINT
//COUNT
//FIND __
//REMOVE Del
//REMOVE Backspace
//PRINT
//
//样例输出
//#
//C
//__
//#
//C
//__ >
//hhh
//
//8
//1
//#
//C
//__ >
//hhh

#include<bits/stdc++.h>
using namespace std;

int r[999999], rs[999999];//记录每行的字符个数（包含'\n'）
string s = "\n", temp, paste, paste0;//paste：选中的字符串；paste0：粘贴板
int pos, nowr, nowl, maxr = 1, pos0;
//当前处于的位置，当前处于第几行，当前处于第几列，一共有多少-1行了，记录点
bool state = false, choose = false;//是否开启粘滞功能，是否处于选中状态

void upd() {	//更新每行的字符个数数组r
	int cnt = 1, index = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '\n') {
			cnt++;
		}
		else {
			r[index] = cnt;
			if (index == 0) {
				rs[index] = r[index];
			}
			else {
				rs[index] = rs[index - 1] + cnt;
			}
			if (pos < r[0]) {
				nowr = 0;
				nowl = pos;
			}
			else if (index > 0 && pos < rs[index] && pos >= rs[index - 1]) {
				nowr = index;
				nowl = pos - rs[index - 1];
				if (rs[nowr] - 1 >= s.size()) {
					while (1);
				}
			}
			index++;
			cnt = 1;
		}
	}
	maxr = index - 1;
}

void move() {
	choose = false;
	int prepos = pos;
	if (temp == "Home") {
		pos -= nowl;
	}
	if (temp == "End") {
		//pos = rs[nowr] - 1;
		pos = s.find('\n', pos);
	}
	if (temp == "Up") {
		if (nowr != 0) {
			if (r[nowr - 1] <= nowl + 1) {
				pos -= nowl + 1;
			}
			else {
				pos -= r[nowr - 1];
			}
		}
	}
	if (temp == "Down") {
		if (nowr < maxr) {
			if (r[nowr + 1] <= nowl + 1) {
				pos = rs[nowr + 1] - 1;
			}
			else {
				pos += r[nowr];
			}
		}
	}
	if (temp == "Left") {
		if (pos > 0) {
			pos--;
		}
	}
	if (temp == "Right") {
		if (pos < s.size() - 1) {
			pos++;
		}
	}
}

void input() {
	if (temp == "Paste" && paste0.size() == 0) {
		return;
	}
	if (choose == true) {
		s.erase(min(pos, pos0), abs(pos - pos0));
		pos = min(pos, pos0);
		choose = false;
		upd();
	}
	if (temp == "Char") {
		//cout << "@@@@" << pos << "," << s.size() << endl;
		char t;
		cin >> t;
		s.insert(pos++, 1, t);
	}
	if (temp == "Enter") {
		s.insert(pos++, 1, '\n');
	}
	if (temp == "Space") {
		s.insert(pos++, 1, ' ');
	}
	if (temp == "Paste") {
		if (paste0.size() != 0) {
			s.insert(pos, paste0);
			pos += paste0.size();
		}
	}
}

void del() {
	if (choose == true) {
		s.erase(min(pos, pos0), abs(pos - pos0));
		if (pos > pos0) {
			pos = pos0;
		}
		choose = false;
	}
	else {
		if (temp == "Del" && pos < s.size() - 1) {
			s.erase(s.begin() + pos);
		}
		if (temp == "Backspace" && pos > 0) {
			s.erase(s.begin() + pos - 1);
			pos--;
		}
	}
}

void shift() {
	if (state == true) {
		if (pos != pos0) {
			choose = true;
			paste = s.substr(min(pos, pos0), abs(pos - pos0));
		}
		state = false;
	}
	else {
		if (choose == false) {
			pos0 = pos;
		}
		else {
			choose = false;
		}
		state = true;
	}
}

int find() {
	string word;
	int cnt = 0, idx = 0;
	cin >> word;
	if (choose == true) {
		while ((idx = paste.find(word, idx)) != paste.npos) {
			idx++;
			cnt++;
		}
	}
	else {
		while ((idx = s.find(word, idx)) != s.npos) {
			idx++;
			cnt++;
		}
	}
	return cnt;
}

int count() {
	int cnt = 0;
	if (choose == true) {
		for (int i = 0; i < paste.size(); i++) {
			if (paste[i] != '\n' && paste[i] != ' ') {
				cnt++;
			}
		}
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '\n' && s[i] != ' ') {
				cnt++;
			}
		}
	}
	return cnt;
}

void copy() {
	if (choose == true) {
		paste0 = paste;
	}
	else if (r[nowr] > 1) {
		paste0 = s.substr(pos - nowl, r[nowr] - 1);
	}
}

void print() {
	cout << s;
	//for (int i = 0; i <= maxr; i++) {
	//	cout << r[i] << "*" << rs[i] << endl;
	//}
	//cout << nowr << "**" << nowl << endl;
}

int main()
{
	//freopen("Text.txt", "r", stdin);
	int n;
	string op;
	cin >> n;
	while (n--) {
		//cout << "%%%%%" << 4800 - n << endl;
		cin >> op;
		if (op == "MOVE") {
			cin >> temp;
			move();
		}
		if (op == "INSERT") {
			cin >> temp;
			input();
		}
		if (op == "REMOVE") {
			cin >> temp;
			del();
		}
		if (op == "SHIFT") {
			shift();
		}
		if (op == "FIND") {
			cout << find() << endl;
		}
		if (op == "COUNT") {
			cout << count() << endl;
		}
		if (op == "COPY") {
			copy();
		}
		if (op == "PRINT") {
			print();
		}
		//cout << "pos=" << pos << endl;
		upd();
	}
	//cout << "****"<<paste0 << endl;
	//cout << maxr << endl;
	return 0;
}