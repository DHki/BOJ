#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtracking(int idx, vector<int>& arr, long long weight, vector<long long>& lst){
    if(idx == arr.size()){
        lst.push_back(weight);
        return;
    }

    backtracking(idx + 1, arr, weight, lst); // arr[idx]를 포함하지 않는 경우
    backtracking(idx + 1, arr, weight + arr[idx], lst); // arr[idx]를 포함하는 경우
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, c;
    cin >> n >> c; // n : 물건의 개수, c : 가방의 용량

    // 절반으로 나누어서 완전탐색을 진행할 예정
    // arr1, arr2로 나누어서 입력을 받는다
    vector<int> arr1, arr2;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;

        if(i % 2) arr1.push_back(tmp);
        else arr2.push_back(tmp);
    }

    // 각각의 경우에 모든 경우의 수를 구해보자 시간복잡도 O(2 ^ (n / 2))
    vector<long long> lst1, lst2;
    backtracking(0, arr1, 0, lst1);
    backtracking(0, arr2, 0, lst2);

    // 시간복잡도를 절반으로 최적화하고 나서, 완전탐색으로 진행하면 다시 원래 시간복잡도를 통하는 방법이다.
    sort(lst1.begin(), lst1.end());
    sort(lst2.begin(), lst2.end());

    long long ans = 0;
    for(int i = 0; i < lst1.size(); i++){
        // 시간복잡도 O(log N)을 가지는 방법을 사용한다 → 최적화 유지 가능
        long long tmp = upper_bound(lst2.begin(), lst2.end(), c - lst1[i]) - lst2.begin();
        ans += tmp;
    }

    cout << ans << "\n";
    return 0;
}