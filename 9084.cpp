// 동전
#include <iostream>
#include <vector>
using namespace std;

vector<int> coins;
vector<int> DP;

int findAnswer(int m){
    DP.resize(m + 1);
    for(int i = 0; i <= m; i++) DP[i] = 0;

    DP[0] = 1; // idx == value일 때 만들 수 있는 경우의 수는 적어도 1개 이상입니다.
    for(int value : coins){
        for(int idx = value; idx <= m; idx++){
            DP[idx] += DP[idx - value]; // idx - value의 경우의 수가 idx의 경우의 수가 됩니다. (누적 합)
        }
    }

    return DP[m];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        coins.clear();
        DP.clear();

        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;

            coins.push_back(tmp);
        }

        int m;
        cin >> m;

        cout << findAnswer(m) << "\n";
    }

    return 0;
}