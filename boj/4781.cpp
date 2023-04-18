// 사탕가게
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> arr; // <사탕의 칼로리, 사탕의 가격>
long long DP[10'001];

long long findAnswer(int n, int m){

    for(int i = 0; i <= m; i++) DP[i] = 0;

    for(int i = 0; i < arr.size(); i++){
        for(int j = arr[i].second; j <= m; j++){
            // j(Money)가 arr[i].second보다 작으면, 그 사탕을 살 수 없습니다.
            // 그래서 j = arr[i].second부터 시작하면 시간을 더 줄일 수 있습니다.
            DP[j] = max(DP[j], DP[j - arr[i].second] + arr[i].first);
        }
    }

   return DP[m];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true){
        int n; float m;
        cin >> n >> m;

        if(n == 0 && m == 0.00) break;
        else arr.clear();

        for(int i = 0; i < n; i++){
            int a; float b;
            cin >> a >> b;

            // 사탕의 가격에 *100을 해서 정수로 변환합니다.
            // 이 때 0.5를 변환한 값에 더해줘서 오차를 없애야 합니다.
            arr.push_back({a, b * 100 + 0.5});
        }

        cout << findAnswer(n, m * 100 + 0.5) << "\n";
    }

    return 0;
}