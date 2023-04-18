// 수 정렬하기 3
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> cnt(10'001, 0); // 카운팅 소트를 이용합니다. (입력 수가 많고, 범위는 비교적 작기 때문)
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;

        cnt[tmp]++; // 들어온 숫자의 인덱스 값을 증가시킵니다.
    }

    for(int i = 1; i < 10'001; i++){
        if(cnt[i]){
            while(cnt[i]){ // cnt[i]의 값만큼 i를 출력합니다.
                cout << i << "\n";
                cnt[i]--;
            }
        }
    }

    return 0;
}
/*
    처음에는 들어오는 숫자의 수만 봐서 일반적인 소트함수로는 안될 것 같다고 생각했음.
    시간초과가 나지 않기 위해 머지소트를 사용하려고 했음.
    메모리초과가 나타남. int 를 2천만개를 저장하려고 했으니 메모리 초과가 나지....
    그래서 카운팅 소트를 사용했고, 별로 신경쓰지 않았던 정렬 방법인데 다시 보게 됨
*/