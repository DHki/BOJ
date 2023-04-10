#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class segment{
    private:
        vector<int> tree;

        void set_tree(){
            int idx = tree.size() / 2;

            for(; idx < tree.size(); idx += 2){
                int tmp = idx;

                while(tmp){
                    if(tmp % 2 == 0) tree[tmp / 2] = min(tree[tmp], tree[tmp + 1]);
                    else tree[tmp / 2] = min(tree[tmp], tree[tmp - 1]);

                    tmp /= 2;
                }
            }
        }

    public:
        segment(int n, const vector<int> arr){
            int tmp = 1;
            while(tmp < 2 * n) {tmp *= 2;}

            tree.resize(tmp, INT_MAX);

            tmp /= 2;

            for(int i = 0; i < arr.size(); i++, tmp++){
                tree[tmp] = arr[i];
            }

            set_tree();
        }

        int get_min(int a, int b, int start, int end, int idx){
            if(b < start || end < a) return INT_MAX;

            if(a <= start && end <= b) return tree[idx];

            return min(get_min(a, b, start, (start + end) / 2, idx * 2), get_min(a, b, (start + end) / 2 + 1, end, idx * 2 + 1));
        }

        int get_size(){
            return tree.size() / 2;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    segment seg = segment(n, arr);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        cout << seg.get_min(a, b, 1, seg.get_size(), 1) << "\n";
    }

    return 0;
}