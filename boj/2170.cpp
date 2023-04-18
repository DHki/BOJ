// 선 긋기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<long long, long long>> arr(n); // <from, to> : from에서 to까지 선을 긋는다는 의미입니다.
    for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end());
    
    // from를 기준으로 정렬을 합니다. left는 가장 왼쪽의 점으로 설정됩니다.
    long long left = arr[0].first, right = arr[0].second;
    long long ans = 0;
    for(int i = 1; i < n; i++){
        if(arr[i].first > right){ // 선이 겹치지 않는다면 (right보다 다음 오는 first가 더 크다면)
            // ans에 길이를 추가해주고 left, right를 업데이트합니다.
            // 이 때, from을 기준으로 정렬했기 때문에, 현재 left보다 작은 firt는 이후에 나타날 수 없습니다.
            ans += (right - left);
            left = arr[i].first;
            right = arr[i].second;
        }// arr[i].first > right && arr[i].second < right의 경우는 포함되는 선분이므로 생략
        else if(arr[i].first < right && arr[i].second > right) right = arr[i].second;
        // arr[i].second가 right보다 큰 경우에 선분이 더 길어집니다. right를 업데이트합니다.
    }
    ans += (right - left);
    // 마지막 남은 right와 left를 이용해 선분의 길이 추가

    cout << ans << "\n";
    return 0;
}