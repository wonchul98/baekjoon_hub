#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int> v;

bool isAble(int val){
    int cnt = 0; // 상한선이 val일 때 써야하는 돈
    for(int i = 0; i < N;i++){
        if(v[i] <= val) cnt += v[i];
        else cnt += val;
    }
    if(cnt > M) return false;
    return true;
}

int main(){
    cin >> N; // 3이상 10000이하
    for(int i = 0;i < N;i++){
        int input; // 100'000이하
        cin >> input;
        v.push_back(input);
    }
    cin >> M; // N이상 1'000'000'000 이하
    int s, e, ans;
    s = 1;
    e = *max_element(v.begin(), v.end());
    // YYYYYNNNNN 구조
    while(s<=e){
        int mid = (s + e) / 2; // 오버플로우 안남
        if(isAble(mid)){
            ans = mid; //가능한 값 저장
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}