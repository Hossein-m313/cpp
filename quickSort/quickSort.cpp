#include <iostream>
#include <vector>
using namespace std;

vector<int> sorted;

void sort(int list[], int n) {
    vector<int> a, b;
    for (int i = 1; i < n; i++)
        if (list[0] < list[i]) b.push_back(list[i]);
        else if (list[0] >= list[i]) a.push_back(list[i]);
    int index = 0;
    while (a.size()) {
        index = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] < a[index]) index = i;
        sorted.push_back(a[index]);
        a.erase(a.begin() + index);
    }
    sorted.push_back(list[0]);
    index = 0;
    while (b.size()) {
        index = 0;
        for (int i = 0; i < b.size(); i++)
            if (b[i] < b[index]) index = i;
        sorted.push_back(b[index]);
        b.erase(b.begin() + index);
    }
}

int main() {
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++) cin >> input[i];
    sort(input, n);
    for (int i = 0; i < n; i++) cout << sorted[i] << " ";
    cout << endl;
}