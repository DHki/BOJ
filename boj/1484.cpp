#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int g;
    cin >> g; // 1 <= g <= 100'000
    
    
    
    // 두 포인터를 이용해 현재 몸무게를 구한다
    // 현재 몸무게, 기억하는 몸무게에 대한 단서가 모두 없기 때문에
    int prev = 1, curr = 1;
    vector<int> ans;
    while(true){
        // 현재 몸무게의 제곱 - 이전 몸무게의 제곱이 g라면 정답에 추가
        if(curr * curr - prev * prev == g) ans.push_back(curr);
        
        // 인접한 제곱수의 차가 g보다 크다면 더 이상 구할 수 없음
        if(curr - prev == 1 && curr * curr - prev * prev > g) break;
        
        if(curr * curr - prev * prev < g) curr++;
        else prev++;
    }
    
    if(!ans.size()){ // ans가 비어있다면
        cout << "-1\n";
        return 0;
    }
    else{
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << "\n";
        }
    }
    

    return 0;
}
