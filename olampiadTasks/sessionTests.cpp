#include <bits/stdc++.h>
#include <vector>
using namespace std;

// int maxUsefulness(int a, int b, int c, int tasks[][3], int types[3]){

// }

void printTasks(vector<vector<int>> tasks){
    cout << endl;
    for(int j = 0; j < tasks.size(); j++){
        for(int t = 0; t < 3; t++) cout << tasks[j][t] << " ";
        cout << endl;
    }
}

void sortTasks(vector<vector<int>>& tasks){
    vector<vector<int>> sorted_tasks;
    sorted_tasks.assign(tasks.size(), {0, 0, 0});
    for(int i = 0; i < tasks.size(); i++){
        int index = -1;
        for(int j = 0; j < tasks.size(); j++) {
            if(tasks[i][0] < tasks[j][0])
                index++;
            else if(tasks[i][0] == tasks[j][0] && ((tasks[i][2] == tasks[j][2] && j >= i) || tasks[i][2] < tasks[j][2]))
                index++;
        }
        sorted_tasks[index][0] = *&tasks[i][0];
        sorted_tasks[index][1] = *&tasks[i][1];
        sorted_tasks[index][2] = *&tasks[i][2];
    }
    printTasks(sorted_tasks);
}

int main () {
    int tcn;
    cin >> tcn;
    for(int i = 0; i < tcn; i++){
        // int tasks_num, a, b, c;
        // cin >> tasks_num >> a >> b >> c;
        // int tasks[tasks_num][3];
        // vector<vector<int>> a_set, b_set, c_set;
        // for(int j = 0; j < tasks_num; j++){
        //     cin >> tasks[j][0] >> tasks[j][1] >> tasks[j][2];
        //     if(tasks[j][1] == 1)
        //         a_set.assign(tasks[j], tasks[j] + 3);
        //     if(tasks[j][1] == 2)
        //         b_set.assign(tasks[j], tasks[j] + 3);
        //     if(tasks[j][1] == 3)
        //         c_set.assign(tasks[j], tasks[j] + 3);
        // }
        // int a_index = 0, b_index = 0, c_index = 0;
        // for(int j = 0; j < tasks_num; j++){
        //     if(tasks[j][1] == 1){
        //         for(int t = 0; t < 3; t++)
        //             a_set[a_index][t] = tasks[j][t];
        //         a_index++;
        //     }
        //     if(tasks[j][1] == 2){
        //         for(int t = 0; t < 3; t++)
        //             b_set[b_index][t] = tasks[j][t];
        //         b_index++;
        //     }
        //     if(tasks[j][1] == 3){
        //         for(int t = 0; t < 3; t++)
        //             c_set[c_index][t] = tasks[j][t];
        //         c_index++;
        //     }
        // }
        // sortTasks(a_set);
        // sortTasks(b_set);
        // sortTasks(c_set);
        // printTasks(a_set);
        // printTasks(b_set);
        // printTasks(c_set);

        // int test[3][3] = {{1, 2, 3}, {1, 3, 2}, {3, 2, 1}};
        // a_set[0].assign(test[0], test[0] + 2);
        // printTasks(a_set);

        
        // int final_a[a][3], final_b[b][3], final_c[c][3];

    }
    vector<vector<int>> a_set;
    a_set.assign(5, {1, 2, 3});
    sortTasks(a_set);
    printTasks(a_set);
}