#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    
    vector<int> coins(n);
    vector<int> money(k + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    money[0] = 1;
    for(int coin : coins){
        for(int i = 1; i <= k; i++){
            if (coin > i) continue;

            money[i] = money[i] + money[i - coin];
        }
    }

    cout << money[k] << "\n";

    return 0;
}