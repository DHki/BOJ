// 파일 합치기
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

vector<int> files;
vector<int> sum;
int DP[501][501];

int findAnswer(int end){
    for(int i = 1; i < end; i++){ // i : interval. j와 end 사이의 거리를 i를 통해 조절합니다.
        for(int j = 1; j + i <= end; j++){ // j : 구할 비용구간의 첫번째 파일
            int k = j + i; // k : 구할 비용구간의 마지막 파일
            DP[j][k] = INT_MAX;

            for(int mid = j; mid < k; mid++){
                DP[j][k] = min(DP[j][k], DP[j][mid] + DP[mid + 1][k] + sum[k] - sum[j - 1]);
            }
        }
    }

    return DP[1][end];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int k;
        cin >> k;

        files.clear();
        sum.clear();
        files.push_back(-1); sum.push_back(0); // DP index와 index를 동일시하기 위한 추가

        for(int i = 0; i < k; i++){
            int tmp;
            cin >> tmp;

            files.push_back(tmp);
            sum.push_back(sum.back() + tmp);
        }

        cout << findAnswer(k) << "\n";
    }

    return 0;
}

/* 재귀함수를 이용한 풀이입니다.
mid를 start부터 end - 1까지 설정하고 mid가 변화함에 따라 DP배열이 최쇠비용으로 갱신됩니다.
** 재귀함수를 이용할 때에는 main에 이 코드를 추가해야 합니다. **
    for(int i = 0; i <= k; i++)
            for(int j = 0; j <= k; j++)
                DP[i][j] = INT_MAX;

int findAnswer(int start, int end){

    if(DP[start][end] != INT_MAX) return DP[start][end]; // 이미 갱신되어있다면 이를 리턴합니다.
    if(start == end) return DP[start][end] = 0; // 비용이 0인 경우입니다.
    if(start + 1 == end) return DP[start][end] = files[start] + files[end]; // 1만큼 차이가 난다면 갱신한 뒤 리턴합니다.

    for(int mid = start; mid < end; mid++){ // 위의 경우에 해당되지 않는다면 DP값을 다시 갱신합니다.
        int left = findAnswer(start, mid);
        int right = findAnswer(mid + 1, end);

        DP[start][end] = min(DP[start][end], left + right);
    }

    return DP[start][end] += sum[end] - sum[start - 1]; // start에서 end - 1까지 합한 결과이기에 sum[end] - sum[start - 1]을 더해줍니다.

}
*/