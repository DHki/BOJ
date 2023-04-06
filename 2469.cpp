#include <iostream>
using namespace std;
 
int k, n;
char map[1000][25];
char up[26];
char down[26];
char q[25];
int qLine;
bool isAble = true;
 
int main() {
 
    //입력
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        up[i] = 'A' + i;
        cin >> down[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k - 1; j++) {
            cin >> map[i][j];
            if (map[i][j] == '?') {
                qLine = i;
            }
        }
    }
 
    //위에서부터 '?'전까지 문자 순서 바꾸기
    for (int i = 0; i < qLine; i++) {
        for (int j = 0; j < k - 1; j++) {
            if (map[i][j] == '-') {
                char tmp = up[j];
                up[j] = up[j + 1];
                up[j + 1] = tmp;
            }
        }
    }
 
    //아래에서부터 '?'전까지 문자 순서 바꾸기
    for (int i = n - 1; i > qLine; i--) {
        for (int j = 0; j < k - 1; j++) {
            if (map[i][j] == '-') {
                char tmp = down[j];
                down[j] = down[j + 1];
                down[j + 1] = tmp;
            }
        }
    }
 
    //위에 문자열, 아래 문자열 비교
    for (int i = 0; i < k - 1; i++) {
 
        //위에 문자 == 아래 문자 : *
        if (up[i] == down[i]) {
            q[i] = '*';
        }
        // 1 2 // 2 1 처럼 교차 : -
        else if (up[i] == down[i + 1] && up[i + 1] == down[i]) {
            q[i] = '-';
            char tmp = up[i];
            up[i] = up[i + 1];
            up[i + 1] = tmp;
        }
        //위에 두경우가 아닐경우 : x
        else {
            isAble = false;
            break;
        }
    }
 
    //출력
    if (isAble) {
        for (int i = 0; i < k - 1; i++) {
            cout << q[i];
        }
        cout << "\n";
    }
    else {
        for (int i = 0; i < k - 1; i++) {
            cout << 'x';
        }
        cout << "\n";
    }
}