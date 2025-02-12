#include <bits/stdc++.h>
using namespace std;

int M, N, mmax = 0;
int mmap[1000][1000];
int dp[1000][1000];

int main() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mmap[i][j];
        }
    }

    // 첫 번째 행과 열 초기화 및 최대 크기 갱신
    for (int i = 0; i < M; i++) {
        dp[i][0] = (mmap[i][0] == 0 ? 1 : 0);
        mmax = max(mmax, dp[i][0]); // 최댓값 갱신
    }
    for (int j = 0; j < N; j++) {
        dp[0][j] = (mmap[0][j] == 0 ? 1 : 0);
        mmax = max(mmax, dp[0][j]); // 최댓값 갱신
    }

    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            if (mmap[i][j] == 0) { // 장애물이 없는 경우
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                mmax = max(mmax, dp[i][j]); 
            } else {
                dp[i][j] = 0; 
            }
        }
    }

    cout << mmax << endl;
    return 0;
}
