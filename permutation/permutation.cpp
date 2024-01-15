#include <iostream>
using namespace std;

void print(int list[], int n, string print_nums = "") {
    if (!n) cout << print_nums << endl;
    else {
        for (int i = 0; i < n; i++) {
            int index = 0, copy_list[n - 1];
            for (int j = 0; j < n; j++) 
                if (j != i) {
                    copy_list[index] = list[j];
                    index++;
                }
            print(copy_list, n - 1, print_nums + (char)(list[i] + 48) + " ");
        }
    }
}

int main() {
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n; i++) list[i] = i + 1;
    print(list, n);
}