#include <bits/stdc++.h>
#include <list>
using namespace std;

int main() {
    int test_cases_num;
    cin >> test_cases_num;
    for(int i = 0; i< test_cases_num; i++){
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        int xp, yp;
        if (x - a > 0) xp = x - a;
        if (y - b > 0) yp = y - b;
        if (xp + yp <= c) cout << "No";
        else cout << "Yes";
    }
}