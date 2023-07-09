#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int find(int index, vector<int>& chk){
    if(chk[index] == index){ // 낸 적 없는 카드라면
        // 다음 번에 카드가 필요할 시 다음 카드를 제출하도록 설정하고 현재 카드 리턴
        chk[index] = index + 1;
        return index;
    }
    // 낸 적 있는 카드라면
    else return chk[index] = find(chk[index], chk); // 다음 카드를 확인하고 index를 리턴

    /*
    완전히 이상적인 함수 선언은 아닌 거 같습니다.
    
    카드를 낸 적 없을 때,
    chk[index] = index + 1;로 재정의하고 index값을 리턴하기 때문에 return chk[index] = find(chk[index], chk) 구분에서
    사용할 수 있는 카드의 인덱스를 리턴하지만, chk[index]의 값은 사용할 수 없는 카드의 인덱스로 정의됩니다.
    최소 한 번 더 find 함수를 거쳐야 합니다.
    */
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cards(m);
    vector<int> chk(m); // 한번 사용한 카드는 버려야 하기 때문에 사용했다면 다른 카드를 내야 한다.
    for(int i = 0; i < m; i++){
        cin >> cards[i];
        chk[i] = i; // chk[i] == i 라면 사용하지 않은 카드라고 정의하자.
    }

    vector<int> games(k);
    for(int i = 0; i < k; i++) cin >> games[i];

    // binary search (uppder bound)를 위해 정렬시킨다
    sort(cards.begin(), cards.end());

    for(int game : games){
        // 상대의 카드 크기에 대해서 낼 수 있는 가장 작은 카드를 고른다. (카드를 냈는지 여부는 상관하지 않고)
        int tmp = upper_bound(cards.begin(), cards.end(), game) - cards.begin();

        int idx = find(tmp, chk); // 카드를 냈다면, 낼 수 있는 다른 카드 중에 가장 작은 카드를 선정한다.
        cout << cards[idx] << "\n";
    }

    return 0;
}