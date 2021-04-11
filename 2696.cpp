// 중앙값 구하기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    // 문제의 원래 의도는 우선순위 큐를 이용해서 푸는 것인 것 같지만...
    // TLE가 나지 않기에 답은 맞힐 수 있습니다. 나중에 다시 풀어볼게용
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n); // 수를 먼저 입력받습니다.
        for(int i = 0; i < n; i++) cin >> arr[i];

        vector<int> sortedArr, ans;
        for(int i = 0; i < n; i++){
            sortedArr.push_back(arr[i]);
            if(i % 2 == 0){ // 홀수 번째 원소에 접근할 때마다 (index가 0부터 시작하기에 짝수 인덱스일 때)
                sort(sortedArr.begin(), sortedArr.end());
                ans.push_back(sortedArr[i / 2]); // 출력해야 할 답을 추가해줍니다.
            }
        }

        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
            if(i % 10 == 9) cout << "\n"; // 주의 : 한 줄에 9개만 출력해야 하는 조건이 있습니다.
        }
        cout << "\n";
    }

    return 0;
}