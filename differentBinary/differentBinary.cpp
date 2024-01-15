#include <iostream>
using namespace std;

string print(int n, string input, int x = 0) {
    if (n > 1) {
        string new_input = print(n - 1, input, x + 1);
        new_input[x] = (char)(!(new_input[x] - 48) + 48);
        return print(n - 1, new_input, x + 1);
    } else {
        cout << input << endl;
        input[x] = (char)(!(input[x] - 48) + 48);
        cout << input << endl;
        return input.substr(0, n + x);
    }
}

int main() {
    int n;
    cin >> n;
    string full_zero;
    for (int i = 0; i < n; i++) full_zero += "0";
    print(n, full_zero);
}