// 수 찾기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bs(const vector<int>& arr, int val);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    // binary_search를 사용하기 위해서는 nums를 sort해야 합니다.
    // algorithm 헤더에 들어있는 sort함수를 이용했습니다.
    // 시간 복잡도 : n*log(n)
    sort(nums.begin(), nums.end());

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;

        // binary_search를 사용해서 true를 리턴받았다 : 수가 존재한다
        // false를 리턴받았다 : 수가 존재하지 않는다
        if(bs(nums, tmp))
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}

// 직접 정의한 binary_search
bool bs(const vector<int>& arr, int val){
    // left index, right index를 정의
    int left = 0, right = arr.size() - 1;
    bool ret = false;

    while(left <= right){
        int mid = (left + right) / 2;

        // 찾으려는 값과 arr[mid]의 값을 비교해 index를 조절합니다.
        if(arr[mid] > val) right = mid - 1;
        else if(arr[mid] < val) left = mid + 1;
        else if(arr[mid] == val) {
            ret = true;
            break;
        }
    }

    return ret;
}   