#include <iostream>
#include <queue>

using namespace std;

int map[50][50]; // 1: 꽃이 있는 칸, 0: 깨끗한 칸, -1: 쓰레기가 있는 칸, -2: 쓰레기의 옆칸
int xx[4] = { -1, 1, 0, 0 };
int yy[4] = { 0, 0, 1, -1 };
bool visit[50][50] = {{false, }, }; // visit 설정. pq를 이용하기 때문에 하나의 경로만 탐색하게 된다

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    pair<int, int> start; // x, y
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char tmp;
            cin >> tmp;
            
            if(tmp == 'F') map[i][j] = 1;
            else if (tmp == 'g'){ // 쓰레기 칸이 들어오면 쓰레기 칸, 그 옆칸을 모두 설정한다
                map[i][j] = -1;
                
                for(int k = 0; k < 4; k++){
                    int nx = j + xx[k];
                    int ny = i + yy[k];
                    
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || map[ny][nx] != 0) continue;
                    map[ny][nx] = -2;
                }
            }
            else if (tmp == 'S'){
                start.first = j; start.second = i;
            }
        }
    }
    
    priority_queue<pair<pair<int, int>, pair<int, int>>> pq; // pair<pair<쓰레기 칸, 그 옆칸>, pair<x, y>>
    pq.push({{0, 0}, {start.first, start.second}}); // 시작 위치 설정
    visit[start.second][start.first] = true;
    
    while(!pq.empty()){
        pair<int, int> garbage = pq.top().first;
        pair<int, int> location = pq.top().second;
        pq.pop();
        
        if (map[location.second][location.first] == 1){ // 다음 위치가 도착지점이라면 정답 출력 후 break
            cout << -garbage.first << " " << -garbage.second << "\n";
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = location.first + xx[i];
            int ny = location.second + yy[i];
            
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || visit[ny][nx]) continue;
            
            visit[ny][nx] = true;
            if (map[ny][nx] == -1) pq.push({{garbage.first - 1, garbage.second}, {nx, ny}});
            else if (map[ny][nx] == -2) pq.push({{garbage.first, garbage.second - 1}, {nx, ny}});
            else pq.push({{garbage.first, garbage.second}, {nx, ny}});
        }
    }
    
    return 0;
}
