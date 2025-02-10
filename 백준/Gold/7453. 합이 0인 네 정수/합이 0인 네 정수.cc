#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll A[4000], B[4000], C[4000], D[4000];

void solution() {
    ll ans = 0;
    vector<ll> AB_sum, CD_sum;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB_sum.push_back(A[i] + B[j]);
            CD_sum.push_back(C[i] + D[j]);
        }
    }

    sort(AB_sum.begin(), AB_sum.end());
    sort(CD_sum.begin(), CD_sum.end());

    int AB_idx = 0;
    int CD_idx = CD_sum.size() - 1;

    while (AB_idx < AB_sum.size() && CD_idx >= 0) {
        ll sum = AB_sum[AB_idx] + CD_sum[CD_idx];

        if (sum == 0) {
            // 같은 값 개수 세기
            ll AB_cnt = 0, CD_cnt = 0;
            ll target_AB = AB_sum[AB_idx];
            ll target_CD = CD_sum[CD_idx];

            while (AB_idx < AB_sum.size() && AB_sum[AB_idx] == target_AB) {
                AB_idx++;
                AB_cnt++;
            }
            while (CD_idx >= 0 && CD_sum[CD_idx] == target_CD) {
                CD_idx--;
                CD_cnt++;
            }

            ans += AB_cnt * CD_cnt;  
        }
        else if (sum > 0) {
            CD_idx--;
        }
        else {
            AB_idx++;
        }
    }

    cout << ans << endl; 
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solution();
    return 0;
}
