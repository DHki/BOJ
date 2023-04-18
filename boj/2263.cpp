// 트리의 순회
#include <iostream>

#define MAX 1000000 + 1

using namespace std;

int inorder[MAX];
int postorder[MAX];
int idx[MAX];

void preOrder(int inStart, int inEnd, int postStart, int postEnd){
    if(inStart > inEnd || postStart > postEnd) return;

    int tmp = postorder[postEnd];
    cout << tmp << " ";

    //트리의 왼쪽
    //inorder의 idx만큼보다 앞부분이 왼쪽에 해당
    //postorder는 처음부터 idx만큼이 왼쪽에 해당
    preOrder(inStart, idx[tmp] - 1, postStart, postStart + idx[tmp] - inStart - 1);

    //트리의 오른쪽
    //inorder의 idx만큼보다 뒷부분에 오른쪽에 해당
    //postorder는 idx부터 끝까지가 오른쪽에 해당
    preOrder(idx[tmp] + 1, inEnd, postStart + idx[tmp] - inStart, postEnd - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> inorder[i];
    for(int i = 0; i < n; i++) cin >> postorder[i];

    for(int i = 0; i < n; i++) idx[inorder[i]] = i; // 계산의 편의를 위해 inorder의 순서를 각 값에 idx를 부여합니다

    preOrder(0, n - 1, 0, n - 1);

    return 0;
}