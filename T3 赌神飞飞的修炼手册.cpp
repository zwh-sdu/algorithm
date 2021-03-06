//问题描述
//飞飞很喜欢打牌，他决定苦练牌技，终成赌神！
//飞飞有 A X B 张扑克牌。
//每张扑克牌有一个大小(整数，记为a，范围区间是 0 到 A - 1）和一个花色（整数，记为b，范围区间是 0 到 B - 1。
//扑克牌是互异的，也就是独一无二的，也就是说没有两张牌大小和花色都相同。
//“一手牌”的意思是你手里有5张不同的牌，这 5 张牌没有谁在前谁在后的顺序之分，它们可以形成一个牌型。
//我们定义了 9 种牌型，如下是 9 种牌型的规则，我们用“低序号优先”来匹配牌型，
//即这“一手牌”从上到下满足的第一个牌型规则就是它的“牌型编号”（一个整数，属于1到9）：
//    1.同花顺 : 同时满足规则 5 和规则 4.
//	2.炸弹 : 5张牌其中有4张牌的大小相等.
//	3.三带二 : 5张牌其中有3张牌的大小相等，且另外2张牌的大小也相等.
//	4.同花 : 5张牌都是相同花色的.
//	5.顺子 : 5张牌的大小形如 x, x  + 1, x + 2, x + 3, x + 4
//	6.三条 : 5张牌其中有3张牌的大小相等.
//	7.两对 : 5张牌其中有2张牌的大小相等，且另外3张牌中2张牌的大小相等.
//	8.一对 : 5张牌其中有2张牌的大小相等.
//	9.要不起 : 这手牌不满足上述的牌型中任意一个.
//现在, 飞飞从 A × B 张扑克牌中拿走了 2 张牌！分别是(a1, b1) 和(a2, b2).（其中a表示大小，b表示花色）
//现在要从剩下的扑克牌中再随机拿出 3 张！组成一手牌！
//其实飞飞现在要预言他的未来的可能性，即他将拿到的“一手牌”的可能性，
//我们用一个 “牌型编号（一个整数，属于1到9）” 来表示这手牌的牌型，那么他的未来有 9 种可能，但每种可能的方案数不一样。
//现在飞飞想要计算一下 9 种牌型中，每种牌型的方案数。
//
//输入格式
//第 1 行包含了整数 A 和 B(1 ≤ A ≤ 25, 1 ≤ B ≤ 4).
//第 2 行包含了整数 a1, b1, a2, b2(0 ≤ a1, a2 ≤ A  - 1, 0 ≤ b1, b2 ≤ B  - 1, (a1, b1) ≠ (a2, b2)).
//
//输出格式
//输出一行，这行有 9 个整数，每个整数代表了 9 种牌型的方案数（按牌型编号从小到大的顺序）
//
//样例输入
//5 2
//1 0 3 1
//
//样例输出
//0 0 0 0 8 0 12 36 0
//
//样例输入
//25 4
//0 0 24 3
//
//样例输出
//0 2 18 0 0 644 1656 36432 113344

#include<cstdio>
#include<algorithm>
using namespace std;

struct node
{
	int sz;
	int hs;
}p[100];

int A, B;
int sz1, hs1, sz2, hs2;
int a[5], b[5];
int result[10];

void check(int i, int j, int k) {
	a[0] = sz1;
	b[0] = hs1;
	a[1] = sz2;
	b[1] = hs2;
	a[2] = p[i].sz;
	b[2] = p[i].hs;
	a[3] = p[j].sz;
	b[3] = p[j].hs;
	a[4] = p[k].sz;
	b[4] = p[k].hs;
	sort(a, a + 5);
	if ((b[0] == b[1] && b[1] == b[2] && b[2] == b[3] && b[3] == b[4]) &&
		(a[0] == a[1] - 1 && a[1] == a[2] - 1 && a[2] == a[3] - 1 && a[3] == a[4] - 1)) {
		result[1]++;
		return;
	}
	if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] ||
		a[1] == a[2] && a[2] == a[3] && a[3] == a[4]) {
		result[2]++;
		return;
	}
	if ((a[0] == a[1] && a[1] == a[2] && a[3] == a[4]) ||
		(a[0] == a[1] && a[2] == a[3] && a[3] == a[4])) {
		result[3]++;
		return;
	}
	if (b[0] == b[1] && b[1] == b[2] && b[2] == b[3] && b[3] == b[4]) {
		result[4]++;
		return;
	}
	if (a[0] == a[1] - 1 && a[1] == a[2] - 1 && a[2] == a[3] - 1 && a[3] == a[4] - 1) {
		result[5]++;
		return;
	}
	if ((a[0] == a[1] && a[1] == a[2]) || (a[1] == a[2] && a[2] == a[3]) || (a[2] == a[3] && a[3] == a[4])) {
		result[6]++;
		return;
	}
	if ((a[0] == a[1] && a[2] == a[3]) || (a[1] == a[2] && a[3] == a[4]) || (a[0] == a[1] && a[3] == a[4])) {
		result[7]++;
		return;
	}
	if (a[0] == a[1] || a[1] == a[2] || a[2] == a[3] || a[3] == a[4]) {
		result[8]++;
		return;
	}
	else {
		result[9]++;
		return;
	}
}

int main()
{
	int num = 0;
	scanf("%d %d", &A, &B);
	scanf("%d %d %d %d", &sz1, &hs1, &sz2, &hs2);
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			if ((i == sz1 && j == hs1) || (i == sz2 && j == hs2)) {
				continue;
			}
			p[num].sz = i;
			p[num].hs = j;

			num++;
		}
	}
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			for (int k = j + 1; k < num; k++) {
				check(i, j, k);
			}
		}
	}
	for (int i = 1; i < 10; i++) {
		printf("%d\t", result[i]);
	}
	return 0;
}