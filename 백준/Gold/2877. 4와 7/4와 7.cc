#define ll long long
#include<iostream>

using namespace std;

string ans;

void find(ll start, ll length, ll idx){
    // printf("find(%lld, %lld, %lld)\n", start, length, idx);
    if(length <= 1) return;
    if(idx < start+length/2) {
        ans.push_back('4');
        find(start, length/2, idx);
    }else{
        ans.push_back('7');
        find(start + length/2, length/2, idx);
    }
}

int main(){
    ll x;
    cin >> x;
    ll temp = 0;
    ll p = 2;
    ll i; // 자리수
    bool flag = false;
    for(i = 1; i <= 30;i++){
        temp += p;
        // cout << "i: " << i << " temp: " << temp << " p: " << p << endl;
        p *= 2;
        if(x <= temp) {
            break;
            flag = true;
        }
    }
    // cout << "temp: " << temp << " p: " << p << endl;

    // temp - p + 1 부터 p만큼
    find(temp/2, p/2, x);
    cout << ans << endl;
    return 0;
}