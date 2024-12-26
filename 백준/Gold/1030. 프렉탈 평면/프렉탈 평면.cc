#include<bits/stdc++.h>

using namespace std;

int s, N, K, C1, C2, R1, R2;
int mid_start;
int mmap[51][51];

bool inCenter(int r, int c, int s){
    int center_start = mid_start * pow(N, s-1);
    int size = K * pow(N, s-1);
    int center_end = center_start + size - 1;
    if(r >= center_start && c >= center_start && r <= center_end && c <= center_end) return true;
    return false;
}

bool inBlack(int r, int c, int s){
    bool flag = false;
    while(s >= 1){
        if(inCenter(r, c, s)){
            flag = true;
            break;
        }
        int next_size = pow(N, s-1);
        s--;
        r = r % next_size;
        c = c % next_size;
    }
    return flag;
}

int main(){
    cin >> s >> N >> K >> C1 >> C2 >> R1 >> R2;
    mid_start = (N-K) / 2;
    for(int i = C1; i <= C2;i++){
        for(int j =R1; j <= R2;j++){
            bool black = inBlack(i,j,s);
            cout << black ? 1 : 0;
        }
        cout <<"\n";
    }
    return 0;
}