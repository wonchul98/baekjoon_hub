/**
 * 1. brute force : 950 C 50 => 너무 크다. 
 * 2. dp : X
 * 3. greedy : 구간 사이에 몇개를 넣을지만 결정 (어차피 n등분 하게 배치해야함)
 * -> 149C49 : 너무 크다
 * 4. 이분 탐색 : 전체 길이가 1000이하이므로 적절하다. 
 */

#include<bits/stdc++.h>

using namespace std;
/**
 *  0 ≤ N ≤ 50
    1 ≤ M ≤ 100
    100 ≤ L ≤ 1,000
 */
int N, M, L;
vector<int> loc, dist;

bool isAble(int x){
    bool flag = false;
    int left = M;
    for(int i = 0;i < dist.size();i++){
        if(dist[i] >= x && dist[i] % x == 0){
            left -= (dist[i]/x - 1);
        }else if(dist[i] >= x && dist[i] % x != 0){
            left -= (dist[i]/x);
        }
    }
    if(left < 0) return false;
    return true;
}

int main(){
    cin >> N >> M >> L;
    loc.push_back(0);
    for(int i = 0; i < N ; i++){
        int input;
        cin >> input;
        loc.push_back(input);
    }
    loc.push_back(L);

    sort(loc.begin(), loc.end());

    for(int i = 1; i <= N + 1;i++){
        dist.push_back(loc[i] - loc[i-1]);
    }

    int start = 1, end = L - 1;

    //이분탐색
    // NNNNYYYY
    while(start < end){
        int mid = (start + end) / 2;
        // cout << "mid: " << mid << endl;
        if(isAble(mid)){
            end = mid;
        }else{
            start = mid + 1;
        }
    }
    cout << start << endl;

    return 0;
}