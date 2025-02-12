#define ll long long

#include<bits/stdc++.h>

using namespace std;

struct Info{
    ll loc, sum;

    Info(ll loc, ll sum) : loc(loc), sum(sum){}

    bool operator<(Info a){
        return loc < a.loc;
    }
};

int N;
ll A[100'001]; // 위치
ll X[100'001]; // 사람 사는 수
ll D[100'001]; // D[i] = (A[i+1] - A[i]) * {(sum(A[1]~A[i]) - (sum(A[i+1]~A[N])}
vector<Info> v;
vector<ll> sum_forward; // 1부터 k까지의 합
vector<ll> sum_backward; // k부터 N까지의 합합
ll find(ll input){
    ll target = input%2==0?input/2 : input/2+1;
    sum_forward.push_back(0);
    ll sum = 0;
    for(int i = 0;i < N;i++){
        sum += v[i].sum;
        if(sum >= target) return v[i].loc;
    }
}

int main(){
    cin >> N;
    ll sum = 0;
    for(int i =1;i<=N;i++){
        cin >> A[i] >> X[i];
        v.push_back(Info(A[i], X[i]));
        sum += X[i];
    }
    // 위치 기반 정렬
    sort(v.begin(), v.end());

    //누적합
    cout << find(sum) << endl;

    return 0;
}