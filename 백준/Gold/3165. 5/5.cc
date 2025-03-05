#define ll long long
#include<bits/stdc++.h>

using namespace std;

int count(ll num){
    int f_cnt = 0;
    ll temp = num;
    while(temp > 0){
        if(temp % 10 == 5) f_cnt++;
        temp /= 10;
    }
    return f_cnt;
}

ll recur(ll num, int k){
    int f_cnt = count(num);
    if(f_cnt >= k) return num;
    ll temp = num;
    for(int i = 0;i < 10;i++){
        if(count(temp) >= k) return temp;
        if(temp % 10 == 5){       
            return recur(temp / 10, k - 1) * 10 + 5; 
        }
        temp++;
    }
}

int main(){
    ll N;
    int K;
    cin >> N >> K;
    cout << recur(N + 1, K) << endl;
    return 0;
}