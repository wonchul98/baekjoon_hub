/**
 *  첫째 줄에 배열의 크기 N과 M이 주어진다. (1 ≤ N ≤ 5,000, 1 ≤ M ≤ N)

    둘째 줄에 배열에 들어있는 수가 순서대로 주어진다. 배열에 들어있는 수는 1보다 크거나 같고, 10,000보다 작거나 같은 자연수이다.

    이분 탐색으로 하자. 
 */

#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;

bool isAble(int x) {
    // printf("isAble(%d)\n", x);
    int cur_cnt = 1, cur_min = INF, cur_max = 0;
    for(int i = 0; i < N;i++){        
        int cur_num = v[i];
        cur_min = min(cur_min, cur_num);
        cur_max = max(cur_max, cur_num);
        int score = cur_max - cur_min;
        if(score > x){ // 이번 거를 먹을 경우에는 만족 못한다면
            cur_cnt++;
            cur_min = cur_num;
            cur_max = cur_num;
        }
    }
    // cout << "cur_cnt: " << cur_cnt << endl;
    if(cur_cnt > M){
        return false;
    }
    return true;
}

int main(){
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    // NNNNYYYY
    int s = 0, e = 10000;
    while(s < e){
        int mid = (s+e)/2;
        // cout << "mid: " << mid << endl;
        if(isAble(mid)){
            e = mid;
        }else{
            s = mid + 1;
        }
    }
    cout << s << endl;
    return 0;
}