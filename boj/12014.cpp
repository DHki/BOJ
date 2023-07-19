#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for(int caseNumber = 1; caseNumber <= t; caseNumber++){
        int n, k;
        cin >> n >> k;

        vector<int> prices(n, 0);
        for(int i = 0; i < n; i++) cin >> prices[i];

        // 가장 긴 증가하는 부분수열
        // 여러 날짜의 주가 중에서, 점점 더 커지는 주가 때마다 살 수 있기 때문에
        // 최장 증가 부분수열 알고리즘 적용
        vector<int> tmp;
        for(int price : prices){
            if(tmp.size() == 0){ // 가장 첫 날의 주가는 바로 push 한다
                tmp.push_back(price);
                continue;
            }

            // 현재 보는 날의 주가가 지금까지 고른 날들보다 더 크다면 뒤로 push
            // 그것보다 같거나 더 큰 날이 존재한다면 해당 날짜의 금액을 바꾼다
            // → 뒤에 나올 금액 중에서 고를 수 있는 금액을 최대한 많이 만들기 위함
            int idx = lower_bound(tmp.begin(), tmp.end(), price) - tmp.begin();
            if(idx == tmp.size()) tmp.push_back(price);
            else tmp[idx] = price;
        }

        cout << "Case #" << caseNumber << "\n";
        if(tmp.size() >= k) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}