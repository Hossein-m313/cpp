#include <iostream>
#include <vector>
using namespace std;

const int num = 1000000;
int ss[num / 2], es[num / 2], lamps[num];

int main() {
    int tcn;
    cin >> tcn;
    while (tcn > 0) {
        tcn--;
        int n;
        cin >> n;
        n *= 2;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            lamps[i] = x;
            if (ss[x - 1]) es[x - 1] = i + 1;
            else ss[x - 1] = i + 1;
        }
        long long int r2 = 1;
        int r1 = 0, cr2 = 1, s = -1, e = -1;
        for (int i = 0; i < n; i++) {
            if (i > e) {
                r1++;
                r2 *= cr2;
                cr2 = 2;
                s = i;
                e = es[lamps[i] - 1] - 1;
            } else {
                
            }
        }
        r2 *= cr2;
        cout << r1 << " " << r2 % 998244353 << endl;
    }
}