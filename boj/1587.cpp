#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int m;
    cin >> m;

    // 간선의 정보를 line 변수에 저장
    vector<pair<int, int>> line;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        line.push_back({x, y});
    }

    /*
    거의 이분 그래프이기에 A집합, B집합에서 최대의 간선 개수를 먼저 구할 수 있다.
    (i, i + 1)이 이어져있다. -> 하나의 집합에서 최대한 많은 간선을 먼저 포함시키자

    1. A, B 모두 짝수일 때 : 각각 최대한의 개수를 포함시킨다.
    2. A, B 중 하나만 홀수일 때 : 어떻게든 하나의 정점은 남는다 -> 1과 동일
    3. 모두 홀수일 때 : 포함시킬 수 있는 간선을 모두 포함시키고, 양쪽에서 하나씩 남는 정점을 이을 수 있는 간선이 있다면 + 1
        -> 간선의 x, y가 모두 홀수인 경우 포함시킬 수 있다.
    */
    int ans = 0;
    if(a % 2 == 0  && b % 2 == 0) ans = a / 2 + b / 2;
    else if(a % 2 && b % 2){
        ans = a / 2 + b / 2;
        for(pair<int, int> tmp : line){
            if(tmp.first % 2 && tmp.second % 2){
                ans++;
                break;
            }
        }
    }
    else{
        ans = a / 2 + b / 2;
    }

    cout << ans << "\n";
    return 0;
}