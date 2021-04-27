// 주식
#include <iostream>
#include <vector>
using namespace std;

long long getAnswer(const vector<int>& arr){
    int maxCost = -1;
    long long money = 0; // 자료형 주의 !! 64bit 이상으로 표현 가능하다고 했으니 넉넉하게 long long으로 선언했습니다.

    maxCost = arr[arr.size() - 1];
    for(int i = arr.size() - 2; i >= 0; i--){ // arr를 역순으로 돌면서, 주식을 사야 최고치에 팔 수 있을지 결정합니다.
        if(arr[i] < maxCost) money += (maxCost - arr[i]);
        else maxCost = arr[i]; // 그렇지 않다면, 최고치 갱신
    }

    return money;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n); // 각 날의 주가를 기록하는 배열
        for(int i = 0; i < n; i++) cin >> arr[i];

        long long ans = getAnswer(arr);
        cout << ans << "\n";
    }

    return 0;
}