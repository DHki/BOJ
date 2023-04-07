#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct info{
    int x;
    int y;
    bool flag;

    info(int a, int b, bool c) : x(a), y(b), flag(c) {}
};

int map[1001][1001];
int dist[1001][1001][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char tmp;
            cin >> tmp;
            map[i][j] = tmp - '0';
            dist[i][j][0] = INT_MAX;
            dist[i][j][1] = INT_MAX;
        }
        
    }

    dist[1][1][0] = 1;
    dist[1][1][1] = 1;

    queue<info> q;
    q.push(info(1, 1, false));

    int xx[] = {-1, 1, 0, 0};
    int yy[] = {0, 0, 1, -1};
    while(!q.empty()){
        info curr = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            info next = info(curr.x + xx[i], curr.y + yy[i], curr.flag);

            if(1 <= next.x && next.x <= m && 1 <= next.y && next.y <= n){
                if(dist[next.y][next.x][next.flag] != INT_MAX) continue;

                if(!map[next.y][next.x]){
                    dist[next.y][next.x][next.flag] = dist[curr.y][curr.x][next.flag] + 1;
                    q.push(next);
                }
                else{
                    if(next.flag) continue;

                    next.flag = true;
                    dist[next.y][next.x][next.flag] = dist[curr.y][curr.x][curr.flag] + 1;
                    q.push(next);
                }
            }
        }
    }


    int ans = min(dist[n][m][0], dist[n][m][1]);
    if(ans == INT_MAX) cout << "-1\n";
    else cout << ans <<"\n";

    return 0;
}