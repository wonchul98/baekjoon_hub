#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int checked[500'001][2];
int dp[500'001];

int solution(std::vector<int> a) {
    int answer = -1;
    for(int i = 0;i <= a.size();i++){
        checked[i][0] = -1;
        checked[i][1] = -1;
    }
    for(int i = 1;i < a.size();i++){
        if(a[i-1] == a[i]) continue;
        if(a[i-1] != checked[i-1][0] && a[i-1] != checked[i-1][1]) {
            dp[a[i-1]]++;
            checked[i][0] = a[i-1];
        }
            
        if(a[i] != checked[i-1][0] && a[i] != checked[i-1][1]) {
            dp[a[i]]++;
            checked[i][1] = a[i];
        }
        
    }
    // for(int i = 0; i < a.size();i++){
    //     printf("dp[%d]: %d\n", i, dp[i]);
    // }
    int mmax = 0;
    for(int i = 0; i < a.size();i++){
        mmax = max(mmax, dp[i]);
    }
    answer = mmax * 2;
    return answer;
}