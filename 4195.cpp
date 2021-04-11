// 친구 네트워크
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

// 친구관계가 100'000을 넘지 않는다....
// 새로운 사람의 쌍이 100'000개가 들어올 수 있다....
// 사람 수의 최대 수는 200'000이 될 것이다.. 
vector<int> parent(200001);
vector<int> setsize(200001);

int findParent(int k){
    if(parent[k] == k) return k;

    else return parent[k] = findParent(parent[k]);
}

void unite(int a, int b){

    parent[a] = b;
    setsize[b] += setsize[a]; // setsize를 하나로 합쳐주는 과정
    setsize[a] = 0; // 나머지 하나는 0으로 설정합니다.
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        for(int i = 0; i <= 200'000; i++){
            parent[i] = i;
            setsize[i] = 1;
        }

        map<string, int> name; // 들어오는 사람마다, 새로운 사람이라면 번호를 부여할 겁니다.
        int idx = 1;
        for(int i = 0; i < n; i++){
            string a, b;
            cin >> a >> b;

            if(name.count(a) == 0) name.insert({a, idx++});
            if(name.count(b) == 0) name.insert({b, idx++});

            int parentA = findParent(name[a]);
            int parentB = findParent(name[b]);

            if(parentA == parentB) cout << max(setsize[parentA], setsize[parentB]) << "\n";
            else{
                unite(parentA, parentB);
                cout << max(setsize[parentA], setsize[parentB]) << "\n";
            }
        }
    }

    return 0;
}