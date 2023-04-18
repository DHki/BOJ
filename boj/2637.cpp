// 2637 장난감조립
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> v; // vector<int, int> : 필요한 부품, 개수
int ans[101][101]; // 답을 저장할 배열 [k][i] : k의 부품을 만들 때 필요한 i의 개수
vector<int> ind; // indegree

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    v.resize(n + 1);
    ind.resize(n + 1);
    for(int i = 0; i <= n; i++) ind[i] = 0;

    int m;
    cin >> m;

    // queue를 이용한 위상정렬을 사용할 생각입니다.
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        ind[a]++;
        v[b].push_back({a, c});
    }

    queue<int> q;
    for(int i = 0; i < n; i++)
        if(ind[i] == 0){ // 기본부품이라면
            q.push(i);
            ans[i][i] = 1;
        }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(pair<int, int> next : v[cur]){ // 현재의 부품으로 만들 수 있는 다음 부품에 대한 정보를 갱신합니다.
            
            for(int i = 0; i <= n; i++){
                ans[next.first][i] += ans[cur][i] * next.second;
            }

            // 현재 부품의 정보 갱신이 완료되었으면 queue에 추가합니다.
            ind[next.first]--;
            if(ind[next.first] == 0) q.push(next.first);
        }
    }

    for(int i = 0; i < n; i++){
        // 기본 부품만 저장되기 때문에, i를 0부터 n까지 돌리면서 값이 0보다 크다면 출력합니다.
        if(ans[n][i]) cout << i << " " << ans[n][i] << "\n";
    }
    return 0;
}
/*
    위상정렬을 이용해 문제를 해결하면 DFS 보다 빠른 속도를 낼 수 있는 것 같음
    DFS로 먼저 문제를 풀려다가 시간 초과가 났음
    DFS를 활용한 위상 정렬도 있던데, 차이가 무엇인지 확인해 볼 필요가 생겨버림
*/