#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> times(501);
vector<int> need[501];
int dp[501];

int find_time(int node){
    if(dp[node] != -1) return dp[node];

    int tmp = 0;
    for(int prev : need[node]){
        tmp = max(tmp, find_time(prev));
    }

    return dp[node] = tmp + times[node];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> times[i];
        dp[i] = -1;

        int tmp;
        while(cin >> tmp, tmp != -1){
            need[i].push_back(tmp);
        }
    }

    for(int i = 1; i <= n; i++) if(need[i].size() == 0) dp[i] = times[i];

    for(int i = 1; i <= n; i++){
        if(dp[i] == -1){
            find_time(i);
        }
    }

    for(int i = 1; i <= n; i++) cout << dp[i] << "\n";

    return 0;

}