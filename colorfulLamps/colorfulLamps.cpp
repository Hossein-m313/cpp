#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> connections;
vector<bool> turned_on;
vector<int> lamps;
long long signed int result1, result2;

void findLargest(int colors[][2], int n);

void findRange(int c, int colors[][2], int n, vector<bool> used = {}, vector<bool> related = {}, int min = -1, int max = -1) {
    int size = connections[c].size();
    bool err = true;
    if (min == -1) {
        related.assign(n, false);
        used.assign(n, false);
        used[c] = true;
        related[c] = true;
        turned_on[c] = true;
        min = colors[c][0];
        max = colors[c][1];
    }
    for (int i = 0; i < size; i++) {
        int connected_c = connections[c][i];
        related[connected_c] = true;
        turned_on[connected_c] = true;
        if (colors[connected_c][0] < min) min = colors[connected_c][0];
        if (colors[connected_c][1] > max) max = colors[connected_c][1];
    }
    for (int i = 0; i < n; i++) {
        if (!used[i] && related[i]) {
            used[i] = true;
            err = false;
            findRange(i, colors, n, used, related, min, max);
            break;
        }
    }
    if (err) {
        int result = 0, check = 0;
        for (int i = min + 1; i < max; i++) turned_on[lamps[i] - 1] = true;
        for (int i = 0; i < n; i++) {
            if (related[i]) result++;
            if (turned_on[i]) check++;
        }
        if (result2) result2 *= result * 2;
        else result2 = result * 2;
        if (n > check) {
            result1++;
            findLargest(colors, n);
        }
    }
}

void findLargest(int colors[][2], int n) {
    int maximum = -10, result_color = 0, x;
    for (int i = 0; i < n; i++) {
        if (!turned_on[i]) {
            x = colors[i][1] - colors[i][0];
            if (x > maximum) {
                maximum = x;
                result_color = i;
            }
        }
    }
    findRange(result_color, colors, n);
}

void calculate(int colors[][2], int n) {
    result1++;
    findLargest(colors, n);
}

int main() {
    int tcn;
    cin >> tcn;
    while (tcn > 0) {
        tcn--;
        int num;
        cin >> num;
        result1 = 0;
        result2 = 0;
        lamps.clear();
        turned_on.clear();
        connections.clear();
        turned_on.assign(num, false);
        connections.assign(num, {});
        int colors[num][2];
        for (int i = 0; i < num; i++) {
            colors[i][0] = -1;
            colors[i][1] = -1;
        }
        for (int i = 0; i < num * 2; i++) {
            int x;
            cin >> x;
            lamps.push_back(x);
            if (colors[x - 1][0] + 1) colors[x - 1][1] = i;
            else colors[x - 1][0] = i;
        }
        for (int i = 0; i < num; i++) {
            int s = colors[i][0] + 1, e = colors[i][1];
            for (int j = s; j < e; j++) {
                if (colors[lamps[j] - 1][0] < s) connections[i].push_back(lamps[j] - 1);
                if (colors[lamps[j] - 1][1] > e) connections[i].push_back(lamps[j] - 1);
            }
        }
        calculate(colors, num);
        cout << result1 << " " << result2 % 998244353 << endl;
    }
}