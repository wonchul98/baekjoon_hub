#include<bits/stdc++.h>

using namespace std;

int N, K;
int I[1'001]; // 중요도
int T[1'001]; // 시간
int dp[1'001][10'001];

void make_dp(){
    for(int i = 1; i <= K;i++){
        for(int j = 1; j <= N; j++){
            if(j - T[i] < 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j - T[i]] + I[i]);
        }
    }
    
}
int main(){
    cin >> N >> K;
    for(int i = 1; i <= K;i++){
        cin >> I[i] >> T[i];
    }
    make_dp();
    cout << dp[K][N] << endl;
    return 0;
}