// 트리 순회
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> adList[26];

void preorder(int curr);
void inorder(int curr);
void postorder(int curr);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        char a, b, c;
        cin >> a >> b >> c;

        adList[a - 'A'].first = b - 'A'; // first에 left child가 들어갑니다.
        adList[a - 'A'].second = c - 'A'; // second에 right child가 들어갑니다.
    }

    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);

    return 0;
}

void preorder(int curr){
    if(curr == '.' - 'A') return; // '.' - 'A' 가 curr값이라면 child가 존재하지 않는 노드입니다. 

    // preorder는 curr를 앞에서 출력합니다.
    cout << char(curr + 'A');
    preorder(adList[curr].first);
    preorder(adList[curr].second);
}

void inorder(int curr){
    if(curr == '.' - 'A') return;

    // inorder는 curr를 중간에 출력합니다.
    inorder(adList[curr].first);
    cout << char(curr + 'A');
    inorder(adList[curr].second);
}

void postorder(int curr){
    if(curr == '.' - 'A') return;

    // postorder는 curr를 뒤에서 출력합니다.
    postorder(adList[curr].first);
    postorder(adList[curr].second);
    cout << char(curr + 'A');
}