// 가장 긴 증가하는 부분수열 (1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<int> DP(n); // DP[i] = i번째 수 까지 봤을 때 가장 긴 증가하는 부분수열의 길이를 저장합니다.
    for(int i = 0; i < n; i++){
        DP[i] = 1; // 자기 자신으로 길이 1은 적어도 확정됩니다.

        // 자신보다 앞에 있는 수들을 확인 합니다.
        for(int j = 0; j < i; j++){
            // 앞에 있는 수보다 자신의 크기가 더 크다면
            // 부분수열 뒤에 자신이 들어갈 수 있습니다.
            // 들어갔을 때와, 들어가지 않았을 때 길이를 비교해 더 큰 값을 넣어줍니다.
            if(nums[i] > nums[j]) DP[i] = max(DP[i], DP[j] + 1);
        }
    }
    
    // DP배열 중 가장 큰 값을 출력합니다.
    cout << *max_element(DP.begin(), DP.end()) << "\n";

    return 0;
}