#include <bits/stdc++.h>
using namespace std;

int main() {
    // Q1
    int a;
    cin >> a;
    int result = 0;
    for(int i = 1; i <= a; i++)
        result += i;
    cout << result << endl;

    // Q2
    int b;
    cin >> b;
    int result2 = 0;
    for(int i = 1; i <= b; i++)
        result2 += i;
    cout << (float)result2 / b << endl;
    
    // Q3
    int c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < c; j++)
            cout << '*';
        cout << endl;
    }
    
    // Q4
    int d;
    cin >> d;
    for(int i = 0; i < d; i++) {
        for(int j = 0; j <= i; j++)
            cout << '*';
        cout << endl;
    }
    
    // Q5
    int e;
    cin >> e;
    for(int i = 0; i < e; i++) {
        for(int j = 0; j < e - i; j++)
            cout << '*';
        cout << endl;
    }
    
    // Q6
    int f;
    cin >> f;
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < f - i - 1; j++)
            cout << ' ';
        for(int j = 0; j <= i; j++)
            cout << '*';
        cout << endl;
    }
    
    // Q7
    int g;
    cin >> g;
    for(int i = g; i > 0; i--) {
        for(int j = 0; j < g - i; j++)
            cout << ' ';
        for(int j = 0; j < i; j++)
            cout << '*';
        cout << endl;
    }
    
    // Q8
    int h;
    cin >> h;
    h = (h + 1) / 2;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < h - i - 1; j++)
            cout << ' ';
        for(int j = 0; j < i * 2 + 1; j++)
            cout << '*';
        cout << endl;
    }
    
    // Q9
    int k;
    cin >> k;
    k = (k + 1) / 2;
    for(int i = k - 1; i >= 0; i--) {
        for(int j = 0; j < k - i - 1; j++)
            cout << ' ';
        for(int j = 0; j < i * 2 + 1; j++)
            cout << '*';
        cout << endl;
    }

    // Q10
    int l;
    cin >> l;
    l = (l + 1) / 2;
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < l - i - 1; j++)
            cout << ' ';
        for(int j = 0; j < i * 2 + 1; j++)
            cout << '*';
        cout << endl;
    }
    for(int i = l - 2; i >= 0; i--) {
        for(int j = 0; j < l - i - 1; j++)
            cout << ' ';
        for(int j = 0; j < i * 2 + 1; j++)
            cout << '*';
        cout << endl;
    }
}