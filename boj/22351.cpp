#include <iostream>
#include <string>
using namespace std;

int main(){
    string assign;
    cin >> assign;

    int len = assign.length();
    
    string a = "";
    int b = 0;
    for(int i = 0; i < len; i++){
        if(b) break;

        a += assign[i];

        int curr = stoi(a);
        string tmp = "";
        while(tmp.length() <= len){
            tmp += to_string(curr);
            if(!tmp.compare(assign)){
                b = curr;
                break;
            }
            curr++;
        }
    }

    cout << a << " " << b << "\n";
    return 0;
}