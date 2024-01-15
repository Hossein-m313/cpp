#include <iostream>
using namespace std;

void moveTower(int s, int e, int n) {
    if (n > 1) {
        int otherone = 6 - s - e;
        moveTower(s, otherone, n - 1);
        cout << s << endl << e << endl << "_____" << endl;
        moveTower(otherone, e, n - 1);
    } else {
        cout << s << endl << e << endl << "_____" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    moveTower(1, 3, n);
}