//问题描述
//TT 在同一时间会与很多同学同时用 QQ（TT特供版） 进行答疑，
//有时 TT 开启一个新的窗口，开始一个新的答疑对话；
//有时 TT 关闭一个窗口，结束一段答疑； 
//有时，为了及时回答着急的同学，TT会把一个对话窗口设置为置顶状态（置顶状态是一种虚拟的状态，窗口的实际位置并不会发生改变）。
//你可以将 TT 的聊天窗口想象成一个队列。
//如果现在没有窗口处于置顶状态，那么在队列中位列第一窗口视为在顶层，否则处于置顶状态的窗口视为在顶层。
//请注意，不可能同时存在两个窗口处于置顶状态（也就是说，处于置顶状态的窗口，要么不存在，要么只有一个）。
//如果当前置顶的窗口被关闭了，则剩余队列中第一窗口视为在顶层。
//TT 为了安抚自己的猫，于是给猫猫看自己的聊天记录解闷，根据猫猫看屏幕中窗口的时间，
//TT 给每个窗口分配了一个喜爱度，TT 认为喜爱度越高，猫猫越开心。由于猫猫具有不确定的生物特性，
//所以所有的喜爱度都是不同的。
//作为 TT 特供版QQ的研发人员，你要负责完成的工作是为软件记录 TT 的操作，形成一个日志系统。
//日志有固定的记录格式：OpId #X: MSG.，其中 XX 是操作的编号，而 MSG 是日志的提示信息，需要使用特定的字符串进行替换。
//TT 可能会用到的操作如下：
//
//Add u : TT 打开一个喜爱度为 uu 的新窗口，若 uu 不与当前窗口队列中的某个窗口重复，则该新窗口将新建成功，并成为窗口队列中的最后一个窗口。 如果创建成功，则 MSG 记录 success。 否则， MSG 记录 same likeness 。
//
//Close u : TT 关掉了一个喜爱度为 uu 的窗口，如果该窗口存在，则将其关闭，MSG 记录 close u with c，uu 表示喜爱度，cc 表示该窗口上次打开至今交流的话的数量。若该窗口不存在，则MSG 记录invalid likeness。
//
//Chat w : TT 和顶层窗口交流了 ww 句话，如果当前队列中没有窗口，则MSG 记录empty，否则记录 success。
//
//Rotate x : 将队列中第 xx 个窗口放在队首，若 xx 大于当前队列中窗口数或小于 11 ，则MSG 记录out of range，否则记录success。举个例子，目前队列中有喜爱度为 5, 3, 2, 8 的四个窗口，Rotate 3 之后，会将喜爱度为 2 的第 3 个窗口放在首位，结果为 2, 5, 3, 8。
//
//Prior : TT 将目前喜爱度最大的窗口放在队首，如果当前队列中没有窗口，则MSG 记录empty，否则记录 success。
//
//Choose u : TT 将喜爱度为 uu 的窗口放在队首，如果喜爱度为 uu 的窗口存在，则MSG 记录success，否则记录invalid likeness。
//
//Top u : TT 将喜爱度为 uu 的窗口设定为置顶状态，如果喜爱度为 uu 的窗口存在，则MSG 记录success，否则记录invalid likeness。注意，处于置顶状态的窗口最多不超过一个，也就是说，如果在此次设定前已经有处于置顶状态的窗口，则原有置顶状态的窗口的置顶状态将会消失。（置顶只是一种虚拟的状态，原窗口在队列中的位置不会发生变化）
//
//Untop : TT 取消当前处于置顶状态窗口的置顶状态。如果当前没有窗口处于置顶状态，则MSG 记录no such person，否则记录success。
//
//最后，由于TT要给自己的猫猫树立一个讲文明有礼貌的榜样，所以在上述操作完成后，还要进行若干次操作，
//这些操作是：与当前队列中所有说过话的窗口说拜拜。MSG 记录Bye u : c，
//u 表示喜爱度，c 表示该窗口上次打开至今交流的话的数量。即：TT 先和位于顶层的窗口说拜拜，然后将其关闭，
//如果TT没有和当前顶层窗口说过话，则直接将其关闭，如此操作下去，直到队列为空。
//
//输入格式
//第一行包含一个整数 T(T≤5)，表示数据组数。
//对于每组数据，第一行一个 n，表示执行的操作数，其中 0 < n≤5000。接下来 n 行，每行输入一个操作，
//保证所有输入数据中的整数不大于 10 ^ 9
//
//输出格式
//对于每个指定的操作，按照日志的格式，每个操作行。对于最后的非指定操作，同样按照日志的格式，每个操作一行。
//
//样例输入
//1
//30
//Add 4
//Add 3
//Chat 4
//Add 3
//Rotate 2
//Chat 5
//Prior
//Top 3
//Choose 4
//Rotate 1
//Add 2
//Close 4
//Chat 7
//Choose 2
//Chat 7
//Add 3
//Top 2
//Add 4
//Choose 3
//Chat 7
//Prior
//Top 3
//Rotate 1
//Rotate 3
//Chat 7
//Top 4
//Add 2
//Close 2
//Prior
//Add 4
//
//样例输出
//OpId #1: success.
//OpId #2: success.
//OpId #3: success.
//OpId #4: same likeness.
//OpId #5: success.
//OpId #6: success.
//OpId #7: success.
//OpId #8: success.
//OpId #9: success.
//OpId #10: success.
//OpId #11: success.
//OpId #12: close 4 with 4.
//OpId #13: success.
//OpId #14: success.
//OpId #15: success.
//OpId #16: same likeness.
//OpId #17: success.
//OpId #18: success.
//OpId #19: success.
//OpId #20: success.
//OpId #21: success.
//OpId #22: success.
//OpId #23: success.
//OpId #24: success.
//OpId #25: success.
//OpId #26: success.
//OpId #27: same likeness.
//OpId #28: close 2 with 7.
//OpId #29: success.
//OpId #30: same likeness.
//OpId #31: Bye 3 : 26.

#include<bits/stdc++.h>
using namespace std;

deque<long long> window;
set<long long> winset;
map<long long, long long> mp;
long long x, zd;

void add(long long u) {
	if (winset.count(u)) {
		cout << "OpId #" << x << ": same likeness." << "\n";
	}
	else {
		winset.insert(u);
		window.push_back(u);
		cout << "OpId #" << x << ": success." << "\n";
	}
	x++;
}

void close(long long u) {
	if (!winset.count(u)) {
		cout << "OpId #" << x << ": invalid likeness." << "\n";
	}
	else {
		winset.erase(u);
		window.erase(find(window.begin(), window.end(), u));
		cout << "OpId #" << x << ": close " << u << " with " << mp[u] << ".\n";
		if (zd == u) {
			zd = -1;
		}
		mp[u] = 0;
	}
	x++;
}

void chat(long long w) {
	if (window.empty()) {
		cout << "OpId #" << x << ": empty." << "\n";
	}
	else {
		if (zd == -1) {
			mp[window.front()] += w;
			cout << "OpId #" << x << ": success." << "\n";
		}
		else {
			mp[zd] += w;
			cout << "OpId #" << x << ": success." << "\n";
		}

	}
	x++;
}

void rotate(long long u) {
	if (u<1 || u>window.size()) {
		cout << "OpId #" << x << ": out of range." << "\n";
	}
	else {
		auto iter = window.begin();
		iter += u - 1;
		int value = *iter;
		window.erase(iter);
		window.push_front(value);
		cout << "OpId #" << x << ": success." << "\n";
	}
	x++;
}

void prior() {
	if (window.empty()) {
		cout << "OpId #" << x << ": empty." << "\n";
	}
	else {
		long long mx = *(winset.rbegin());
		auto iter = find(window.begin(), window.end(), mx);
		int value = *iter;
		window.erase(iter);
		window.push_front(value);
		cout << "OpId #" << x << ": success." << "\n";
	}
	x++;
}

void choose(long long u) {
	if (!winset.count(u)) {
		cout << "OpId #" << x << ": invalid likeness." << "\n";
	}
	else {
		auto iter = find(window.begin(), window.end(), u);
		int value = *iter;
		window.erase(iter);
		window.push_front(u);
		cout << "OpId #" << x << ": success." << "\n";
	}
	x++;
}

void top(long long u) {
	if (winset.count(u)) {
		zd = u;
		cout << "OpId #" << x << ": success." << "\n";
	}
	else {
		cout << "OpId #" << x << ": invalid likeness." << "\n";
	}
	x++;
}

void untop() {
	if (zd == -1) {
		cout << "OpId #" << x << ": no such person." << "\n";
	}
	else {
		zd = -1;
		cout << "OpId #" << x << ": success." << "\n";
	}
	x++;
}

int main() {
	long long T;
	cin >> T;
	while (T--) {
		long long n;
		cin >> n;
		x = 1;
		zd = -1;
		while (n > 0) {
			string op;
			long long u;
			cin >> op;
			if (op == "Add") {
				cin >> u;
				add(u);
			}
			if (op == "Close") {
				cin >> u;
				close(u);
			}
			if (op == "Chat") {
				cin >> u;
				chat(u);
			}
			if (op == "Rotate") {
				cin >> u;
				rotate(u);
			}
			if (op == "Prior") {
				prior();
			}
			if (op == "Choose") {
				cin >> u;
				choose(u);
			}
			if (op == "Top") {
				cin >> u;
				top(u);
			}
			if (op == "Untop") {
				untop();
			}
			n--;
		}
		if (zd != -1) {
			if (mp[zd]) {
				cout << "OpId #" << x << ": Bye " << zd << ": " << mp[zd] << ".\n";
				x++;
			}
			window.erase(find(window.begin(), window.end(), zd));
		}

		int us = 0;
		while (!window.empty()) {
			us = window.front();
			if (mp[us]) {
				cout << "OpId #" << x << ": Bye " << us << ": " << mp[us] << ".\n";
				x++;
			}
			window.pop_front();
		}
		zd = -1;
		winset.clear();
		mp.clear();
	}
	return 0;
}
