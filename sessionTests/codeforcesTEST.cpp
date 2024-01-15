#include <iostream>
#include <vector>
using namespace std;

int final_result[2] = {0, 0};

void turnOn(int lamps[], int colors[][2], int num, int range[2], int result1, int result2, int result3, vector<bool> lamps_status);

void calculate(int lamps[], int colors[][2], int num, vector<bool> lamps_status, int result1 = 1, int result2 = 1, int result3 = 2) {
    int maximum = colors[0][1] - colors[0][0], index = 0;
    for (int i = 1; i < num / 2; i++) {
        int difference = colors[i][1] - colors[i][0];
        if (difference > maximum){
            maximum = difference;
            index = i;
        } 
    }
    turnOn(lamps, colors, num, colors[index], result1, result2, result3, lamps_status);
}

void turnOn(int lamps[], int colors[][2], int num, int range[2], int result1, int result2, int result3, vector<bool> lamps_status) {
    lamps_status[range[0]] = true;
    lamps_status[range[1]] = true;
    for (int i = range[0] + 1; i < range[1]; i++) {
        int another_index = colors[lamps[i] - 1][0] + colors[lamps[i] - 1][1] - i;
        lamps_status[i] = true;
        lamps_status[another_index] = true;
    }
    for (int i = range[0] + 1; i < range[1]; i++) {
        int another_index = colors[lamps[i] - 1][0] + colors[lamps[i] - 1][1] - i;
        for (int j = i + 1; j < another_index; j++)
            if (lamps_status[j]) {
                result3 += 2;
                break;
            }
    }
    bool check = false, first = true, err = false;
    int nrs = -1; // new range start
    int nre = 0; // new range end
    int new_num = 0; // for new recalling
    int nc[num]; // for new recalling
    for (int i = 0; i < num; i++) nc[i] = 0;
    for (int i = 0; i < num; i++) {
        if (lamps_status[i]) {
            nre = i;
            if (first) {
                nrs = i;
                first = false;
            }
        }
        else if ((nrs + 1) && !lamps_status[i]) check = true;
        if ((nrs + 1) && check && lamps_status[i]) err = true;
        if (!lamps_status[i] && !nc[i]) {
            nc[i] = new_num + 1;
            nc[colors[lamps[i] - 1][0] + colors[lamps[i] - 1][1] - i] = new_num + 1;
            new_num++;
        }
    }
    if (err) {
        int new_range[2] = {nrs, nre};
        turnOn(lamps, colors, num, new_range, result1, result2, result3, lamps_status);
    }
    else if (nrs == 0 && nre == num - 1) {
        result2 *= result3;
        final_result[0] = result1;
        final_result[1] = result2;
    }
    else {
        int new_lamps[new_num * 2], new_colors[new_num][2], index = 0; // also for new recalling
        new_num *= 2;
        vector<bool> new_lamps_status = {};
        new_lamps_status.assign(new_num, false);
        for (int i = 0; i < new_num / 2; i++) {
            new_colors[i][0] = -1;
            new_colors[i][1] = -1;
        }
        for (int i = 0; i < num; i++) {
            if (!lamps_status[i]) {
                int c = nc[i];
                new_lamps[index] = c;
                if (!(new_colors[c - 1][0] + 1)) new_colors[c - 1][0] = index;
                else new_colors[c - 1][1] = index;
                index++;
            }
        }
        result2 *= result3;
        calculate(new_lamps, new_colors, new_num, new_lamps_status, result1 + 1, result2);
    }
}

int main() {    
    int tcn;
    cin >> tcn;
    for (int i = 0; i < tcn; i++) {
        int num;
        cin >> num;
        num *= 2;
        int lamps[num], colors[num / 2][2];
        for (int j = 0; j < num; j++) colors[j / 2][j % 2] = -1;
        for (int j = 0; j < num; j++) {
            cin >> lamps[j];
            if (!(colors[lamps[j] - 1][0] + 1)) colors[lamps[j] - 1][0] = j;
            else colors[lamps[j] - 1][1] = j;
        }
        vector<bool> lamps_status = {};
        for (int i = 0; i < num; i++) lamps_status.push_back(false);
        calculate(lamps, colors, num, lamps_status);
        cout << final_result[0] << " " << final_result[1] << endl;
    }
}