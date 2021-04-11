// 베르트랑 공준
#include <iostream>
using namespace std;

#define MAX 2 * 123456 + 1

bool arr[MAX]; // 에라토스테네스의 체를 적용할 배열입니다.
int main(){
    // true이면 소수가 아니고, false일 때 소수입니다.
    arr[0] = arr[1] = true;
    for(int i = 2; i*i < MAX; i++){
        if(!arr[i])
            for(int j = i + i; j < MAX; j += i) arr[j] = true;
    }

    while(true){
        int n;
        cin >> n;

        if(n == 0) break;

        int ans = 0;
        for(int i = n + 1; i <= 2 * n; i++){ // 주의 : n보다 크고, 2n보다 작거나 같은 수 중에서
            if(!arr[i]) ans += 1;
        }

        cout << ans << "\n";
    }

    return 0;
}