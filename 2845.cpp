// 파티가 끝나고 난 뒤
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int real = a * b; // 파티에 참가한 사람의 수(정확한 수)

    for(int i = 0; i < 5; i++){
        int tmp;
        cin >> tmp; // 기사에 나타난 수

        cout << tmp - real << " "; // 그 차이를 출력합니다.
    }

    return 0;
}