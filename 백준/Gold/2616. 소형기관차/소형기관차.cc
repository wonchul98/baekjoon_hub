#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> train;
vector<int> prefixSum;

int dp[4][50'001]; //dp배열

void make_dp(){
    for(int i = 1; i < 4;i++){
        for(int j = i * M - 1; j < N;j++){
            if(i == 1 && j == i * M - 1){
                dp[i][j] = prefixSum[M - 1];
            }else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - M] + prefixSum[j] - prefixSum[j - M]); // max(이전에 먹은경우, 이번에 먹는경우)
            }
        }
    }
}

int main(){
    cin >> N;
    int sum = 0;
    for(int i = 0; i < N;i++){
        int num;
        cin >> num;
        train.push_back(num);
        sum += num;
        prefixSum.push_back(sum);
    }

    cin >> M;

    make_dp();

    // for(int i = 1; i < 4;i++){
    //     for(int j = 0; j < N;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[3][N-1];

    return 0;
}