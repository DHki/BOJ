// 랜선 자르기
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 최대 랜선 길이를 리턴해주는 함수
long long getAnswer(const vector<int>& lines, int need){
    // !!! 주의 !!!
    // left, right, mid는 long long으로 선언해주셔야 합니다.
    // overflow가 나는 경우, 시간 초과를 받습니다.
    // ans는 mid를 대입하기에 데이터 누락을 없애기 위해 long long이 바람직합니다.
    long long left = 0, right = INT_MAX;

    long long ans;
    while(left <= right){ // PS를 이용합니다.
        long long mid = (left + right) / 2;

        int cnt = 0;
        for(int i = 0; i < lines.size(); i++) cnt += lines[i] / mid;

        if(cnt >= need){
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<int> lines(k);
    for(int i = 0; i < k; i++) cin >> lines[i];

    long long ans = getAnswer(lines, n);
    cout << ans << "\n";

    return 0;
}