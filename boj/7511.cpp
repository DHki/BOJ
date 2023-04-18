#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> network;

int find(int node){
    if(network[node] == node) return node;

    else return network[node] = find(network[node]);
}

void unite(int a, int b){
    int parent_a = find(a);
    int parent_b = find(b);

    if(parent_a != parent_b) network[parent_a] = parent_b;

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    int scenario = 1;
    while(scenario <= t){
        int num_friends;
        cin >> num_friends;

        network.resize(num_friends);
        for(int i = 0; i < num_friends; i++) network[i] = i;

        int num_network;
        cin >> num_network;

        
        for(int i = 0; i < num_network; i++){
            int a, b;
            cin >> a >> b;

            unite(a, b);
        }

        int num_find;
        cin >> num_find;

        queue<int> ans;
        for(int i = 0; i < num_find; i++){
            int a, b;
            cin >> a >> b;

            if(find(a) == find(b)) ans.push(1);
            else ans.push(0);
        }

        cout << "Scenario " << scenario << ":\n";
        for(int i = 0; i < num_find; i++){
            int tmp = ans.front();
            ans.pop();
            
            cout << tmp << "\n";
        }
        cout << "\n";

        scenario++;
    }

    return 0;
}