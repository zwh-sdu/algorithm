#include <bits/stdc++.h>
using namespace std;

struct Data
{
    string op;
    double price;
    long long num;
    int flag;
};

struct Money
{
    double price;
    long long buy;
    long long sell;
};

vector<Data> datas;
vector<Money> money;

bool cmp(Data a, Data b)
{
    if (a.flag == b.flag)
    {
        return a.price > b.price;
    }
    return a.flag > b.flag;
}

void hb(double price, string s, long long num)
{
    Money temp;
    int f = 0;
    for (int i = 0; i < money.size(); i++)
    {
        if (money[i].price == price)
        {
            f = 1;
            if (s == "buy")
                money[i].buy += num;
            else
                money[i].sell += num;
            break;
        }
    }
    //如果这个价格之前没有插入过，就插入一个新的价格
    if (!f)
    {
        temp.price = price;
        if (s == "buy")
        {
            temp.buy = num;
            temp.sell = 0;
        }
        else
        {
            temp.sell = num;
            temp.buy = 0;
        }
        money.push_back(temp);
    }
}

int main()
{
    Data t;
    while (cin >> t.op)
    {
        if (t.op == "cancel")
        {
            cin >> t.price;
            t.flag = 0;
            datas[t.price - 1].flag = 0;
        }
        else
        {
            cin >> t.price >> t.num;
            t.flag = 1;
        }
        datas.push_back(t);
    }
    sort(datas.begin(), datas.end(), cmp);
    for (int i = 0; i < datas.size(); i++)
    {
        if (datas[i].flag == 1)
        {
            hb(datas[i].price, datas[i].op, datas[i].num);
        }
        else
        {
            break;
        }
    }
    double monMax;
    long long numMax = -1;
    for (int i = 0; i < money.size(); i++)
    {
        long long sumb = 0;
        long long sums = 0;
        for (int j = 0; j <= i; j++)
        { // 买单量
            sumb += money[j].buy;
        }
        for (int j = i; j < money.size(); j++)
        { // 卖单量
            sums += money[j].sell;
        }
        long long minn = sumb < sums ? sumb : sums; // min(买单量,卖单量)
        if (minn > numMax)
        {
            numMax = minn;
            monMax = money[i].price;
        }
    }
    printf("%.2f %lld\n", monMax, numMax);
    system("pause");
    return 0;
}