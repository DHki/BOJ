// 노트북의 주인을 찾아서
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v; // i번째 사람이 원하는 노트북들
vector<bool> visit; // 노트북이 정해졌는지 아닌지 확인
vector<int> want; // 특정 노트북을 누가 가져가는지에 대한 값

bool solve(int i){
    // 이분 매칭을 이용해 문제를 해결하려고 합니다.

    for(int idx : v[i]){
        if(visit[idx]) continue; // 원하는 노트북이 이미 정해졌다면 다음 노트북으로 넘어갑니다.

        visit[idx] = true; // 노트북을 true로 바꿉니다.
        if(want[idx] == 0 || solve(want[idx])){ // 아무도 그 노트북을 선점하지 않았거나, 선점한 사람이 다른 노트북으로 넘어갈 수 있다면
            want[idx] = i; // 그 노트북을 자신이 가져가고, true를 리턴합니다.
            return true;
        }
    }

    return false; // 그게 아니라면 false를 리턴합니다.
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    v.resize(n + 1);
    visit.resize(n + 1);
    want.resize(n + 1, 0);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int i = 1; i <= n; i++) visit[i] = false; // visit은 solve 내에서 loop가 생기는 것을 방지하기 위함이므로, 항상 리셋해줍니다.

        if(solve(i)) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}