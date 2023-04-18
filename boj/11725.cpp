// 트리의 부모 찾기
#include <iostream>
#include <vector>
using namespace std;

vector<int> adList[100'001];
vector<int> parent(100'001);

void DFS(int curr, int bef){
    parent[curr] = bef; // parent 노드를 저장합니다. (visit처럼 사용 가능합니다.)

    for(int next : adList[curr]){
        if(!parent[next]) DFS(next, curr); // next의 parent가 정해지지 않았다면, DFS를 실행합니다.
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;

        // 아직 어느 것이 parent 노드인지 정해지지 않았기때문에, 두 노드 모두에 추가해줍니다.
        adList[a].push_back(b);
        adList[b].push_back(a);
    }

    DFS(1, 1);

    for(int i = 2; i <= n; i++) cout << parent[i] << "\n";

    return 0;
}