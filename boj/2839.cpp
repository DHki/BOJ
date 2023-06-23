#include <iostream>
#include <algorithm>
using namespace std;

int ans[5001] = {0, };

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n + 1; i++){
        ans[i] = 987654321;

        if(i % 3 == 0){
            ans[i] = min(ans[i], i / 3);
        }
        if(i % 5 == 0){
            ans[i] = min(ans[i], i / 5);
        }

        if(i >= 3 && ans[i - 3] != 987654321) ans[i] = min(ans[i], ans[i - 3] + 1);
        if(i >= 5 && ans[i - 5] != 987654321) ans[i] = min(ans[i], ans[i - 5] + 1);
    }

    if(ans[n] == 987654321) cout << "-1\n";
    else cout << ans[n] << "\n";

    return 0;
}