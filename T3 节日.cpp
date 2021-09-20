#include <bits/stdc++.h>
using namespace std;

bool rn(int x)
{
    return (x % 400 == 0) || (x % 100 != 0 && x % 4 == 0);
}

int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int a, b, c, y1, y2;
    while (cin >> a >> b >> c >> y1 >> y2)
    {
        int d = 0;
        for (int y = 1850; y < y1; y++)
            d += 365 + rn(y);
        for (int y = y1; y <= y2; y++)
        {
            int day = d;
            if (rn(y))
                m[2] = 29;
            else
                m[2] = 28;
            for (int i = 1; i < a; i++)
                day += m[i];
            int week = (day % 7 + 2) % 7; //a月1号是星期几
            if (week == 0)
                week = 7;
            day = (b - 1) * 7 + 1;
            if (c >= week)
                day += c - week;
            else
                day += 7 - week + c;
            if (day > m[a])
                cout << "none" << endl;
            else
                printf("%04d/%02d/%02d\n", y, a, day);
            d += 365 + rn(y);
        }
    }
    system("pasue");
    return 0;
}