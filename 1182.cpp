// 부분수열의 합
#include <iostream>
#include <vector>
using namespace std;

int n, s;
vector<int> nums;
int ans;
void BackTracking(int idx, int sum, int num_add);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    nums.resize(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    BackTracking(0, 0, 0);

    cout << ans << "\n";

    return 0;
}

// 백트래킹으로 풀어보려 합니다...
void BackTracking(int idx, int sum, int num_add){
    if(idx == n){
        if(sum == s && num_add != 0) ans += 1;

        return;
    }

    BackTracking(idx + 1, sum + nums[idx], num_add + 1); // 지금 보는 인덱스를 추가하는 경우
    BackTracking(idx + 1, sum, num_add); // 지금 보는 인덱스를 추가하지 않는 경우
}