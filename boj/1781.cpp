#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int fin = 0;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        fin = max(fin, arr[i].second);
    }
    sort(arr.begin(), arr.end());

    int ans = 0, idx = 0; // ans : 최대 컵라면의 개수, idx : 현재까지 걸린 시간
    priority_queue<int> s; // s : 현재까지 푼 문제의 컵라면 개수를 저장하는 큐
    for(int i = 0; i < n; i++){
        if(idx < arr[i].first){
            // 데드라인이 현재까지 걸린 시간보다 크다면
            // 문제를 풀어서 컵라면을 더 받으면 된다.
            ans += arr[i].second;
            s.push(-arr[i].second);
            idx++;
        }
        else{
            int tmp = -s.top();
            if(tmp < arr[i].second){
                // 현재까지 푼 문제들 중에 가장 적은 컵라면을 주는 문제보다 컵라면을 많이 준다면
                // 해당 문제 대신 이번 문제를 푸는 게 더 많이 받을 수 있다
                ans -= tmp;
                s.pop();
                ans += arr[i].second;
                s.push(-arr[i].second);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}