// 직각삼각형
#include <iostream>
using namespace std;

bool check(int a, int b, int c){
    // 가장 긴 변의 제곱 == 나머지 두 변의 제곱의 합에 따라 리턴 값이 달라집니다.
    if(a > b && a > c){
        if((a * a) == (b * b + c * c)) return true;
        else return false;
    }
    else if(b > c && b > a){
        if((b * b) == (a * a + c * c)) return true;
        else return false;
    }
    else if(c > a && c > b){
        if((c * c) == (a * a + b * b)) return true;
        else return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 단순 구현 문제
    while(true){
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 0 && b == 0 && c == 0) break; // 입력이 끝나는 조건

        if(check(a, b, c)) cout << "right\n";
        else cout << "wrong\n";
    }

    return 0;
}