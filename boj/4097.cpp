// 수익
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getMax(const vector<int>& arr){ // 카데인 알고리즘을 사용합니다.
    int sum = 0, res = -987654321;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i]; // 첫번째 수부터 sum에 더해줍니다.

        res = max(res, sum); // res와 sum 중에, 더 큰 수를 저장합니다.
        sum = max(sum, 0);
        // sum이 0보다 작다면, 구간합이 음수가 됩니다. (가장 큰 구간 합이 되기 어려움)
        // 그 경우에 지금까지의 합은 지우고, 새로운 합을 만들어줍니다.
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true){
        int n;
        cin >> n;

        if(n == 0) break;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        int ans = getMax(arr);
        cout << ans << "\n";
    }

    return 0;
}