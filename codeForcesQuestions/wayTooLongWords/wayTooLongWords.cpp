#include <bits/stdc++.h>
using namespace std;

int main() {
    int number = 0;
    cin >> number;
    string results[number] = {};
    for(int i = 0; i < number; i++){
        string input = "";
        cin >> input;
        results[i] = input;
    }
    for(int i = 0; i < number; i++){
        if(results[i].length() > 10){
            cout << results[i][0] << results[i].size() - 2 << results[i][results[i].length() - 1] << endl;
        }else {
            cout << results[i] << endl;
        }
    }
}