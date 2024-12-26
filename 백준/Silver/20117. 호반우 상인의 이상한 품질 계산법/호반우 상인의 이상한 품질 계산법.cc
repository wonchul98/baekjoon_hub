#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int main(){
    cin >> N;
    for(int i = 0; i < N;i++){
        int input;
        cin >> input;
        A.push_back(input);
    }
    sort(A.begin(), A.end());
    int ans = 0;
    for(int i= N/2; i < N;i++){
        ans += 2 * A[i];
    }
    if(N % 2 == 0){
        cout << ans << endl;
    }else{
        cout << ans - A[N/2] << endl;
    }
    return 0;
}