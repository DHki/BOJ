// 숫자 구슬
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; // 구슬의 개수, 그룹의 수
    cin >> n >> m;

    vector<int> balls(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> balls[i];
        sum += balls[i];
    }

    int left = 0, right = sum;
    int ans;
    while(left <= right){ // ans의 값을 추론하는 과정 PS 사용
        int mid = (left + right) / 2;
        int tmp = 0, cnt = 1; // tmp : 수의 합, cnt : 그룹의 개수
        bool check = true;

        for(int i = 0; i < n; i++){ // 한 그룹에 적어도 하나 이상 들어가야 합니다.
            if(balls[i] > mid){
                check = false;
                break;
            }

            tmp += balls[i];
            if(tmp > mid){
                cnt++;
                tmp = balls[i];
            }
        }

        if(cnt > m || check == false) left = mid + 1; // 그룹의 개수가 더 많거나, 아무것도 없는 그룹이 있을 때
        else {
            right = mid - 1;
            ans = mid;
        }
    }

    cout << ans << "\n";
    
    vector<int> group;
    int tmp = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        tmp += balls[i];
        cnt++;

        if(tmp > ans){
            tmp = balls[i];
            group.push_back(cnt - 1);
            cnt = 1;
        }
    }
    group.push_back(cnt);

    int diff = m - group.size();
        for(int i = 0; i < group.size(); i++){
            if(group[i] == 1) cout << group[i] << " ";
            else{
                while(group[i] >= 2 && diff >= 1){
                    cout <<"1 ";
                    group[i]--; diff--;
                }
                cout << group[i] << " ";
            }
        }   

    return 0;
}