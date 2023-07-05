#include <iostream>
using namespace std;

long long n, l, k;
long long dp[32][32]; // [자릿수][1을 사용한 횟수]

long long fill(int i, int j){
    if(j == l || i >= n) return 1;
    if(dp[i][j]) return dp[i][j];
    return dp[i][j] = fill(i + 1, j) + fill(i + 1, j + 1);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> l >> k;
    for(int i = 1, j = 0; i <= n; i++){
        if(fill(i, j) >= k){
            cout << 0;
        }
        else{
            cout << 1;
            k -= fill(i, j);
            j++;
        }
    }
    cout << "\n";

    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= l; j++) cout << dp[i][j] << " ";
        cout << "\n";
    }

    return 0;
}