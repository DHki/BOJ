#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> times(m + 1);
    for(int i = 1; i <= m; i++) cin >> times[i];
    
    if(n <= m){
        cout << n << "\n";
        return 0;
    }
    
    long long left = 0, right = 60000000000;
    long long totalTime; // time of all children can ride 
    while(left <= right){
        long long mid = (left + right) / 2;
        
        long long tmp = m;
        for(int i = 1; i <= m; i++){
            tmp += mid / times[i];
        }
        
        if(tmp >= n){
            totalTime = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    
    long long ride = m; // the number of ridded
    for(int i = 1; i <= m; i++){
        ride += (totalTime - 1) / times[i];
    }
    
    for(int i = 1; i <= m; i++){
        if (!(totalTime % times[i])) ride++;
        
        if(ride == n){
            cout << i << "\n";
            break;
        }
    }

    return 0;
}
