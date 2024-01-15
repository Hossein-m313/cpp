#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long int result = 0;
    int min = 0, size = n;
    vector<long long int> p;
    p.assign(n, 0);
    cin >> p[0];
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        if (p[min] > p[i] || (p[min] == p[i] && p[i - 1] == p[i])) min = i;
    }
    while (true) {
        int index = min + 1;
        if (index >= size) index = 0;
        auto it = p.begin();
        if (size == 2 && p[index] < p[min] * 2) {
            result += (p[min] + p[index]) / 3;
            break;
        } else if (size == 3 && p[index] < p[min] * 2) {
            if (p[index] == 1 && p[min] == 1) {
                result++;
                break;
            } else if (p[index] % 2) {
                result += p[index] / 2;
                p[min] -= p[index] / 2;
                p[index] = 1;
            } else {
                result += p[index] / 2;
                p[min] -= p[index] / 2;
                p.erase(it + index);                
            }
        } else if (p[index] == p[min] * 2) {
            result += p[min];
            p.erase(it + index);
            if (min + 1 < n) p.erase(it + min);
            else p.erase(it + min - 1);
        } else if (p[index] > p[min] * 2) {
            result += p[min];
            p[index] -= p[min] * 2;
            p.erase(it + min);
        } else {
            result += p[min];
            int index2 = index + 1, minus = p[index];
            if (index2 >= size) {
                p.erase(it + index);
                p[0] -= p[min] * 2 - minus;
                p.erase(it + min);
            } else {
                p[index2] -= p[min] * 2 - minus;
                p.erase(it + min);
                p.erase(it + index);
            }
        }
        size = p.size();
        if (size < 2) break;
        min = 0;
        for (int i = 1; i < size; i++) {
            if (p[min] > p[i] || (p[min] == p[i] && p[i - 1] == p[i])) min = i;
        }
    }
    cout << result;
}