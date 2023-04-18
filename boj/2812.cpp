// 크게 만들기
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k; // n : 숫자의 자리수, k : 지워야할 숫자의 개수

    string num;
    cin >> num;

    /* k개를 지워야 하는데, 가장 큰 수가 가장 큰 자릿수에 있어야 합니다. 
    앞에서 부터 탐색하면서, 가장 큰 숫자를 하나씩 자릿수에 넣으며 진행합니다. */

    deque<char> dq;
    for(int i = 0; i < n; i++){
        while(k != 0 && !dq.empty() && dq.back() < num[i]){
            // k개를 이미 지웠다면 더이상 지우면 안됨
            // dq가 비어있다면 더이상 지울 수 없음
            // 가장 뒷자리의 수가 다음 탐색하는 수보다 작다면, 탐색한 수(num[i])가 그 자리에 왔을 때
            // 수가 더 커질 수 있음
            dq.pop_back();
            k--;
        }

        dq.push_back(num[i]);
    }

    // dq에 n - k개보다 더 많은 수가 저장될 수 있습니다.
    // 처음부터 dq.size - k만큼 탐색하며 출력해야 합니다.
    for(int i = 0; i < dq.size() - k; i++){
        cout << dq[i];
    }

    return 0;
}