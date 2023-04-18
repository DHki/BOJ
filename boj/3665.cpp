#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> score(n);
        vector<int> adj[n + 1];
        vector<int> indgree(n + 1, 0);

        for(int i = 0; i < n; i++){
            cin >> score[i];
            adj[i + 1].resize(n + 1, false);
        }

        for(int i = 0; i < n - 1; i++) for(int j = i + 1; j < n; j++) {
            adj[score[i]][score[j]] = true;
            indgree[score[j]]++;
        }

        int k;
        cin >> k;

        for(int i = 0; i < k; i++){
            int a, b;
            cin >> a >> b;

            if(adj[a][b]){
                adj[a][b] = false;
                adj[b][a] = true;

                indgree[b]--;
                indgree[a]++;
            }
            else{
                adj[a][b] = true;
                adj[b][a] = false;

                indgree[b]++;
                indgree[a]--;
            }
        }
        
        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(indgree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);

            indgree[front]--;

            for(int i = 1; i <= n; i++){
                if(adj[front][i]) indgree[i]--;

                if(indgree[i] == 0) q.push(i);
            }
        }

        

        if(ans.size() == n){
            for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
            cout << "\n";
        }
        else{
            cout << "IMPOSSIBLE\n";
        }

    }

    return 0;
}