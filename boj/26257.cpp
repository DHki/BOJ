#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> pointers(m + 1);
    for(int i = 1; i <= m; i++) cin >> pointers[i];


    for(int i = 0; i < q; i++){
        string decide;
        cin >> decide;

        if(decide == "assign"){
            int a, b;
            cin >> a >> b;

            pointers[a] = pointers[b];
        }
        else if(decide == "swap"){
            int a, b;
            cin >> a >> b;

            int tmp = pointers[a];
            pointers[a] = pointers[b];
            pointers[b] = tmp;
        }
        else{
            int a;
            cin >> a;
            pointers[a] = 0;
        }
    }

    set<int> s;
    for(int i = 1; i <= m; i++){
        if(pointers[i] != 0){
            s.insert(pointers[i]);
        }
    }

    cout << s.size() << "\n";
    for(int tmp : s){
        cout << tmp << "\n";
    }

    return 0;
}