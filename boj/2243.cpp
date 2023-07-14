#include <iostream>
#include <vector>
using namespace std;

class segTree{
    public:
        segTree(){
            for(;size < 1000000; size *= 2){} // 리프노드는 2의 지수승으로 만들어야 한다

            candies.resize(2 * this->size, 0);
        }

        void update(int flavor, int cnt){
            int idx = flavor + size - 1;
            while(idx){
                candies[idx] += cnt;
                idx /= 2;
            }
        }

        int find(int rank, int idx){
            if(idx >= size) return idx - size + 1;

            if(candies[idx * 2] >= rank) return find(rank, idx * 2);
            else return find(rank - candies[idx * 2], idx * 2 + 1);
        }
    private:
        int size = 1;
        vector<int> candies;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    segTree tree = segTree();
    while(n--){
        int a;
        cin >> a;

        if(a == 1){
            int b;
            cin >> b;

            int idx = tree.find(b, 1);
            cout << idx << "\n";

            tree.update(idx, -1);
        }
        else if(a == 2){
            int b, c;
            cin >> b >> c;

            tree.update(b, c);
        }
    }

    return 0;
}