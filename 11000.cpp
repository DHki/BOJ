#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> lectures(n);
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        cin >> lectures[i].first >> lectures[i].second;
        pq.push(-lectures[i].second);
    }
    sort(lectures.begin(), lectures.end());

    for(int i = 0; i < n; i++){
        if(lectures[i].first >= -pq.top()){
            pq.pop();
        }
    }

    cout << pq.size() << "\n";

    return 0;
}