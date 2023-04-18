//백준 1080 - 행렬
#include <iostream>
using namespace std;

int matrix_1[50][50], matrix_2[50][50];
void reverseMatrix(int i, int j);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int r, c; // row, col
    cin >> r >> c;

    for(int i = 0; i < r; i++){
        string tmp;
        cin >> tmp;

        for(int j = 0; j < c; j++){
            matrix_1[i][j] = tmp[j] - '0';
        }
    }

    for(int i = 0; i < r; i++){
        string tmp;
        cin >> tmp;

        for(int j = 0; j < c; j++){
            matrix_2[i][j] = tmp[j] - '0';
        }
    }

    // 답을 저장할 변수입니다.
    int ans = 0;

    // matrix를 탐색하면서 1과 2가 다르다면 배열을 뒤집습니다.
    for(int i = 0; i < r - 3 + 1; i++){
        for(int j = 0; j < c - 3 + 1; j++){
            if(matrix_1[i][j] != matrix_2[i][j]){
                reverseMatrix(i, j);
                ans += 1;
            }
        }
    }

    bool ans_check = true;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            // matrix가 서로 다르다면 false를 저장합니다.
            if(matrix_1[i][j] != matrix_2[i][j]) { ans_check = false; break; }
        }

        if(!ans_check) break;
    }

    if(ans_check) cout << ans << "\n";
    else cout << "-1\n";

    return 0;
}

void reverseMatrix(int y, int x){
    // x, y : 뒤집어야할 3x3 배열의 왼쪽 윗부분
    for(int i = y; i < y + 3; i++){
        for(int j = x; j < x + 3; j++){
            if(matrix_1[i][j] == 1) matrix_1[i][j] = 0;
            else matrix_1[i][j] = 1;
        }
    }
}