#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<double> points_X(n);
    vector<double> points_Y(n);
    for(int i = 0; i < n; i++){
        cin >> points_X[i] >> points_Y[i];
    }

    int k;
    cin >> k;
    vector<double> where(k);
    for(int i = 0; i < k; i++){
        cin >> where[i];
    }

    for(int i = 0; i < k; i++){
        int idx = lower_bound(points_X.begin(), points_X.end(), where[i]) - points_X.begin();
        
        if(points_Y[idx - 1] < points_Y[idx]) cout << "1\n";
        else if(points_Y[idx - 1] > points_Y[idx]) cout << "-1\n";
        else cout << "0\n";
    }

    return 0;
}