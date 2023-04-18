// 골드바흐의 추측
#include <iostream>
using namespace std;

bool era[1'000'001]; // false : 소수인 수
pair<int, int> checkTrue(int n);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 에라토스테네스의 체를 만드는 과정
    era[0] = true;
    era[1] = true;
    for(int i = 2; i * i <= 1'000'000; i++){
        if(!era[i]){
            for(int j = i * 2; j <= 1'000'000; j += i) era[j] = true;
        }
    }
    
    int n;
    while(cin >> n, n != 0){
        pair<int, int> ans = checkTrue(n); // 함수 checkTrue에서 두 개의 홀수인 소수로 표현 가능한지 확인합니다.

        if(ans.first == 0) cout << "Goldbach's conjecture is wrong.\n";
        else cout << n << " = " << ans.first << " + " << ans.second << "\n";
    }

    return 0;
    
}

pair<int, int> checkTrue(int n){
    pair<int, int> ret = {0, n}; // 리턴할 pair

    while(true){
        for(int i = ret.second; i > 2; i--){
            if(!era[i]){ // 첫 번째 수를 찾습니다. (2보다 큰 소수는 모두 홀수입니다.)
                ret.second = i;
                break;
            }
        }

        if(!era[n - ret.second]){ // 찾은 첫 번째 수와 상응하는 수가 소수가 맞다면
            ret.first = n - ret.second;
            break; // 답을 찾았습니다.
        }
        else if(ret.second == 3) break; // ret.second가 3까지 내려왔다면 답을 찾을 수 없습니다.
        else ret.second -= 1; // while문의 시작으로. ret.second -= 1을 해서 첫 번째 for문의 범위를 조절합니다.
    }

    return ret;
}