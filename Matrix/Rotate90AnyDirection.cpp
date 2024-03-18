#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld long double
#define nl "\n"
#define fastinput ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//----------------------------------------------------------------///
void rotateClocwise(vector<vector<int>>a) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            swap(a[i][j], a[j][i]);
        }
    }
    for(int i = 0; i < n; i++) {
        reverse(a[i].begin(), a[i].end());
    }
    cout << "Clockwise" << nl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << nl;
    }
}
void rotateAntiClockwise(vector<vector<int>>a) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    int ind = n - 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n / 2; j++) {
            int temp = a[j][i];
            a[j][i] = a[ind][i];
            a[ind][i] = temp;
            ind--;
        }
        ind = n - 1;
    }
    cout << "AntiClockwise" << nl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << nl;
    }
}
int main() {
    fastinput;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>>a = {{1,2,3,4,5},
                           {6,7,8,9,10},
                           {11,12,13,14,15},
                           {16,17,18,19,20},
                           {21,22,23,24,25}};
    int n = a.size();
    cout << "Before Rotation " <<  nl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << nl;
    }
    rotateClocwise(a);
    rotateAntiClockwise(a);
    return 0;
}