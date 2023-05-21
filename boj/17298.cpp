#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    
    stack<int> s;
    vector<int> ans(n + 1);
    
    for(int i = n; i >= 1; i--){
        
        while(!s.empty() && arr[i] >= s.top()) s.pop();
        
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        
        
        s.push(arr[i]);
        
    }
    
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}
