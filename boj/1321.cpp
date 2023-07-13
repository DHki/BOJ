#include <iostream>
#include <vector>
using namespace std;

/*
세그먼트 트리는 노드의 합을 저장하고 찾아야 하는 군번이 들어왔을 때
왼쪽 노드에 군번이 포함되는지, 오른쪽 노드에 군번이 포함되는지 확인하며 리프 노드까지 내려간다
리프노드까지 내려갔다면 해당 노드(부대 번호)가 군번이 포함된 부대이다.
*/
class segTree{
    public:
        segTree(){}
        segTree(int n){
            for(; size < n; size *= 2);
            tree.resize(size * 2, 0);
        }

        void make_tree(const vector<int>& arr){
            for(int idx = size, i = 1; i < arr.size(); i++, idx++){
                tree[idx] = arr[i];
                
                int tmp = idx; // 리프노드에서부터 위로 올라가면서 더해준다
                while(tmp){
                    tree[tmp / 2] += arr[i];
                    tmp /= 2;
                }
            }
        }

        void print(){
            for(int i = 1; i < tree.size(); i++) cout << tree[i] << " ";
            cout << "\n";
        }

        void update(const int idx, const int offset){
            int tmp = idx + size - 1; // 인덱스를 리프노드로 설정

            while(tmp){
                tree[tmp] += offset;
                tmp /= 2;
            }
        }

        int find(const int num, const int idx){
            if(idx >= size) return idx - size + 1; // 현재 노드가 리프노드라면 현재 부대를 리턴

            if(num <= tree[idx * 2]) return find(num, idx * 2); // 찾아야 하는 군번이 왼쪽 노드에 포함된다면
            else return find(num - tree[idx * 2], idx * 2 + 1); // 찾아야 하는 군번이 오른쪽 노드에 포함된다면 (왼쪽 노드를 무시하고 오른쪽 노드에서 다시 찾는다)
        }

    private:
        int size = 1; // 리프 노드의 수를 정하게 되는 size
        vector<int> tree;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> soldiers(n + 1); // 각 부대에 필요한 군인의 수
    segTree s = segTree(n);
    for(int i = 1; i <= n; i++){
        cin >> soldiers[i];
    }
    s.make_tree(soldiers); // 세그먼트 트리를 만든다
    

    int m;
    cin >> m;
    while(m--){
        int k;
        cin >> k;
        if(k == 1){
            int a, b;
            cin >> a >> b;

            s.update(a, b);
        }
        else if(k == 2){
            int a;
            cin >> a;

            cout << s.find(a, 1) << "\n";
        }
    }

    return 0;
}