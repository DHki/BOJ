#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int start = 0, end = 0;
    int len = n + 1, sum = arr[0];
    while(end < n){
        if(sum >= s){
            len = min(len, end - start + 1);
            sum -= arr[start++];

            continue;
        }
        else{
            sum += arr[++end];
        }

        if(start > end){
            sum += arr[++end];
        }
    }

    if(len == n + 1) cout << 0 << "\n";
    else cout << len << "\n";

    return 0;
}