#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> price(n); // price[k] : k번째 도시에서의 리터당 가격
    vector<long long> dist(n - 1); // dist[k] : k번째 도시에서 k + 1번째 도시까지의 거리

    for(int i = 0; i < n - 1; i++) cin >> dist[i];
    for(int i = 0; i < n; i++) cin >> price[i];
    


    long long ans = 0;
    long long curr_price = price[0];
    for(int i = 0; i < n - 1; i++){ // i : 현재 위치, n - 2번째 도시까지만 가면 n - 1번째 도시에서는 주유할 필요가 없음
        if(curr_price > price[i + 1]){
            ans += curr_price * dist[i];
            curr_price = price[i + 1];
        }
        else{
            ans += curr_price * dist[i];
        }
    }

    cout << ans << "\n";

    return 0;
}