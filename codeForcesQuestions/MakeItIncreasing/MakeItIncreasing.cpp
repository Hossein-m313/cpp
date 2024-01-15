#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_cases_num;
    bool error = true;
    cin >> test_cases_num;
    for(int i = 0; i < test_cases_num; i++){
        int result = 0;
        int num = 0;
        cin >> num;
        int list[num];
        for (int j = 0; j < num; j++) cin >> list[j];
        for (int j = num - 1; j > 0 && error; j--){
            while(true){
                if(list[j - 1] >= list[j] && list[j - 1] != 0){
                    list[j - 1] /= 2;
                    result++;
                }
                else if(list[j - 1] == 0 && list[j - 1] >= list[j]) {
                    error = false;
                    cout << -1;
                    break;
                }
                else break;
            }
        }
        if(error)cout << result;
    }
}