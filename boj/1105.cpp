// 팔
#include <iostream>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    int ans = 0;
    // a, b의 자릿수가 다르다면 8은 한번도 나오지 않을 수 있습니다.
    if(a.length() == b.length()){
        
        for(int i = 0; i < a.length(); i++){
            // i번째 위치에서 두 수가 다르다면, 그 뒤에오는 수는 8이 아닌 수로 바꿀 수 있습니다.
            // ex) 8838 ~ 8848 -> 8840
            if(a[i] != b[i]) break;
            else if(a[i] == '8' && b[i] == '8') ans += 1;
        }
    }

    cout << ans << "\n";

    return 0;
}