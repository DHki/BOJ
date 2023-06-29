#include <iostream>
#include <algorithm>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int INF = 1e9 + 5;

int T,n,m,score[11],M=INF,cnt,sum,dp[105][5005],ans;

int main() {
    FIO;
    for (cin >> T;T > 0;T--) {
        cin >> n >> m;M = INF;
        for (int i = 0;i < m;i++) {
            cin >> score[i];
            if (score[i] < M)M = score[i];
        }
        sort(score, score + m);
        for (int i = 0;i < 105;i++)for (int j = 0;j <=n;j++)dp[i][j] = -1;
        ans = -1,sum = 0, cnt = 1;
        dp[0][0] = 0;
        while (sum <= n) {
            for (int i = 0;i <= n;i++) {
                if (dp[cnt - 1][i] == -1)continue;
                for (int j = 0;j < m;j++) {
                    int num = i + score[j] * cnt;
                    if (num > n)break;
                    dp[cnt][num] = max(dp[cnt][num], dp[cnt - 1][i] + score[j]);
                }
            }
            ans = max(ans, dp[cnt][n]);
            sum += cnt * M;
            cnt++;
        }
        cout << ans<<'\n';
    }
}