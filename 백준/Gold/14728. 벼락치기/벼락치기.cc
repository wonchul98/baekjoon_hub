/**
 * 첫째 줄에는 이번 시험의 단원 개수 N(1 ≤ N ≤ 100)과 시험까지 공부 할 수 있는 총 시간 T(1 ≤ T ≤ 10000)가 공백을 사이에 두고 주어진다.

둘째 줄부터 N 줄에 걸쳐서 각 단원 별 예상 공부 시간 K(1 ≤ K ≤ 1000)와 그 단원 문제의 배점 S(1 ≤ S ≤ 1000)가 공백을 사이에 두고 주어진다.
 */

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cmath>

using namespace std;

int N, T;

int dp[101][10'001];
vector<int> V; // 가치치
vector<int> W; // 공부 시간

void make_dp(){
    //초기화화

    for(int k = 1; k <= N;k++){
        for(int w = 0; w <= T;w++){
            if(w - W[k] < 0) dp[k][w] = dp[k-1][w];
            else dp[k][w] = max(dp[k-1][w], dp[k-1][w-W[k]] + V[k]);
        }
    }
}

int main(){
    cin >> N >> T;
    V.push_back(0);
    W.push_back(0);
    for(int i = 0; i < N;i++){
        int K, S;
        cin >> K >> S;
        W.push_back(K);
        V.push_back(S);
    }
    make_dp();
    cout << dp[N][T] << endl;
    return 0;
}