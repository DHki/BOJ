// 보석 상자
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; // 학생의 수, 보석의 색상 수
    cin >> n >> m;

    vector<int> jewerly(m);
    for(int i = 0; i < m; i++){ // 각 색상의 보석의 개수를 받는 과정
        cin >> jewerly[i];
    }

    //유추해야 할 범위의 left, right를 설정한다.
    int left = 1, right = *max_element(jewerly.begin(), jewerly.end());
    int ans;
    while(left <= right){
        int mid = (left + right) / 2;
        int student = 0;

        for(int i = 0; i < m; i++){
            student += jewerly[i] / mid;

            if(jewerly[i] % mid != 0)
                student++;
        }

        // ans값과 mid값을 비교할 필요는 없습니다.
        // ans에 값이 들어가면, 다음 범위는 더 작은 범위가 됩니다.
        // ans에 값이 들어갈 수 있으면, 항상 mid는 ans보다 더 작습니다.
        if(student <= n){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}