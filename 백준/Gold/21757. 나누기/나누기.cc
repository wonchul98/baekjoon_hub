#define ll long long

#include <bits/stdc++.h>
using namespace std;

int N, sum = 0, avg;
vector<int> A;
vector<int> prefixSum;
ll dp[4];

void make_dp() {
    for (int i = 1; i <= N; i++) {
        int cur = prefixSum[i];
        if (cur == avg) {               
            dp[1]++;
        } else if (cur == avg * 2) {    
            dp[2] += dp[1];
        } else if (cur == avg * 3) {     
            dp[3] += dp[2];
        }
    }
}

int main() {
    cin >> N;
    A.resize(N);
    prefixSum.resize(N + 1, 0);  

    bool only_zero = true;  
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] != 0) only_zero = false;  
        sum += A[i];
    }

    for (int i = 0; i < N; i++) {
        prefixSum[i + 1] = prefixSum[i] + A[i];
    }

    if (only_zero) {  
        cout << (ll)(N - 1) * (N - 2) * (N - 3) / 6 << endl;
        return 0;
    }

    if (sum == 0) {  
        int count = 0;  
        ll result = 0;  

        for (int i = 1; i <= N; i++) {
            if (prefixSum[i] == 0) count++;
        }

        if (count >= 4) {
            result = (ll)(count - 1) * (count - 2) * (count - 3) / 6;
        }
        cout << result << endl;
        return 0;
    }

    if (sum % 4 != 0) { 
        cout << 0 << endl;
        return 0;
    }

    avg = sum / 4; 
    make_dp();  

    cout << dp[3] << endl;
    return 0;
}
