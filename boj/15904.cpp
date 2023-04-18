#include <iostream>
using namespace std;

//백준 15904 - UCPC는 무엇의 약자일까?
int main(){
    string s;
    getline(cin, s);

    // UCPC라는 문자열을 만들고
    // s에 UCPC라는 문자가 나오는지 확인한다
    string tmp = "UCPC";
    int cnt = 0;

    for(int i = 0; i < s.length(); i++){
        // cnt = 4라면 UCPC가 나올 수 있다. break
        if(cnt == 4) break;
        // 우리가 원하는 문자가 나오는지 확인
        if(s[i] == tmp[cnt]) cnt++;
    }

    if(cnt == 4) cout << "I love UCPC\n";
    else cout << "I hate UCPC\n";


    return 0;
}