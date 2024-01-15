#include <iostream>
#include <vector>
using namespace std;

int n;
vector<string> printed;

void print_r(int x) {
    if (x > 0) {
        int size = printed.size();
        string result;
        for (int j = size - 1; j > -1; j--) {
            result = "";
            for (int i = 0; i < x - 1; i++) result += '0';
            result += '1';
            result += printed[j].substr(x, n);
            printed.push_back(result);
            cout << result << endl;
        }
        print_r(x - 1);
    }
}

void print(string input) {
    cout << input << endl;
    printed.push_back(input);
    input[n - 1] = '1';
    cout << input << endl;
    printed.push_back(input);
    print_r(n - 1);
}

int main() {
    cin >> n;
    string full_zero;
    for (int i = 0; i < n; i++) full_zero += "0";
    print(full_zero);
}