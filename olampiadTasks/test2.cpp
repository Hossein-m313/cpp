#include <iostream>
#include <vector>

using namespace std;

void sortSet(int set[][3], int size){
    int indices[size], set_copy[size][3];
    for (int i = 0; i < size; i++) indices[i] = 0;
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (set[i][2] == set[j][2]) {
                if (set[i][0] < set[j][0]) indices[i]++;
                else indices[j]++;
            }
            else if (set[i][2] < set[j][2]) indices[i]++;
            else indices[j]++;
        }
    }
    for (int i = 0; i < size; i++) {
        set_copy[indices[i]][0] = set[i][0];
        set_copy[indices[i]][1] = set[i][1];
        set_copy[indices[i]][2] = set[i][2];
    }
    for (int i = 0; i < size; i++) {
        set[i][0] = set_copy[i][0];
        set[i][1] = set_copy[i][1];
        set[i][2] = set_copy[i][2];
    }
}

void logSet(int set[][3], int size){
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << set[i][0] << " " << set[i][1] << " " << set[i][2] << endl;
    cout << endl;
}

int main(){
    int tasks_num, a, b, c;
    cin >> tasks_num >> a >> b >> c;
    int tasks[tasks_num][3];
    for (int j = 0; j < tasks_num; j++) {
        cin >> tasks[j][0] >> tasks[j][1] >> tasks[j][2];
    }
    sortSet(tasks, tasks_num);
    logSet(tasks, tasks_num);
}