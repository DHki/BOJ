#include <iostream>
#include <vector>

using namespace std;

vector<int> gates;

int find(int node){
    if(gates[node] == node) return node;

    return gates[node] = find(gates[node]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int g, p;
    cin >> g >> p;

    gates.resize(g + 1);
    for(int i = 1; i <= g; i++) gates[i] = i;

    vector<int> planes(p);
    for(int i = 0; i < p; i++) cin >> planes[i];

    
    int cnt = 0;
    for(int i = 0; i < p; i++){

        int gate = find(planes[i]);

        if(gate != 0){
            cnt++;
            gates[gate] = gate - 1;
        }
        else{
            break;
        }
    }

    cout << cnt << "\n";
    return 0;
}