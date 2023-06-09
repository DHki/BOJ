#include <iostream>
using namespace std;

int main(){
    float a, d, k;
    cin >> a >> d >> k;
    
    d /= 100;
    k /= 100;

    double ans = 0, prev = 1, cnt = 1;
    while(true){
        ans += cnt * a * prev * d;
        cnt++;

        if(d == 1) break;

        prev = prev * (1 - d);
        d += d * k;
        if(d >= 1) d = 1;
    }

    cout.precision(7);
    cout << fixed << ans << "\n";

    return 0;
}