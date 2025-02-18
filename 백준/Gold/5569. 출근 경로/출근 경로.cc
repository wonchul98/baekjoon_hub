#include<bits/stdc++.h>

using namespace std;
struct Info{
    int left_not_turn, left_turn, down_not_turn, down_turn;

    Info() {};
    Info(int a, int b, int c, int d) : left_not_turn(a), left_turn(b), down_not_turn(c), down_turn(d) {};
};

int w, h;
Info dp[101][101];

int main(){
    cin >> w >> h;
    for(int i = 2 ; i <= w; i++){
        dp[i][1] = Info(1,0,0,0);
    }
    for(int i = 2 ; i <= h; i++){
        dp[1][i] = Info(0,0,1,0);
    }
    for(int i = 2; i <= w;i++){
        for(int j = 2; j <= h; j++){
            int lnt = (dp[i-1][j].left_not_turn + dp[i-1][j].left_turn) % 100000;
            int lt = dp[i-1][j].down_not_turn % 100000;
            int dnt = (dp[i][j-1].down_not_turn + dp[i][j-1].down_turn) % 100000;
            int dt = dp[i][j-1].left_not_turn % 100000;
            dp[i][j] = Info(lnt, lt, dnt, dt);
        }
    }
    cout << (dp[w][h].left_not_turn + dp[w][h].left_turn + dp[w][h].down_not_turn + dp[w][h].down_turn) % 100000 << endl;
    return 0;
}