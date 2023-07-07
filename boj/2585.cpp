#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<double, double>> points; // 0 : start point, n + 1 : end point
    points.push_back({0,0});
    for(int i = 0; i < n; i++){
        double a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }
    points.push_back({10000, 10000});
    
    if(k == 0){ //도착점까지 한번에 가야하는 경우 처리
        cout << "1415\n";
        return 0;
    }

    // 각각의 점들을 기준으로 edges를 만드는 과정
    int tmp = points.size();
    vector<pair<int, long double>> edges[n + 2];
    for(int i = 0; i < tmp - 1; i++){
        for(int j = i + 1; j < tmp; j++){
            long double distance = sqrtl(powl((points[i].first - points[j].first), 2) + powl((points[i].second - points[j].second), 2));
            edges[i].push_back({j, distance});
            edges[j].push_back({i, distance});
        }
    }

    //parametric search
    long minimum = 1, maximum = 1415;
    long long ans;
    while(minimum <= maximum){
        long long mid = (minimum + maximum) / 2; // 연료 용량 설정
        vector<bool> visit(n + 2, false);


        //BFS 이용, 도착지점까지 갈 수 있는지 확인
        queue<pair<int, int>> q; // <curr point, cnt>
        q.push({0,0});
        visit[0] = true;

        bool flag = false; // 현재 연료통 용량으로 갈 수 있는지 체크
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();

            for(pair<int, long double> next : edges[curr.first]){
                if(visit[next.first]) continue; // 이미 지나온 길
                else if(next.second > mid * 10) continue; // 갈 수 없는 길

                if(curr.second >= k && next.first != n + 1) continue; // k번 이상 연료를 충전했지만 도착지점이 아닌 경우

                if(next.first == n + 1){ // 도착지점에 도달한 경우
                    flag = true;
                    break;
                }

                q.push({next.first, curr.second + 1});
                visit[next.first] = true;
            }

            if(flag) break;
        }

        if(flag){
            ans = mid;
            maximum = mid - 1;
        }
        else{
            minimum = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}