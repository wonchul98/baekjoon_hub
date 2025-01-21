#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>

using namespace std;

struct Info{
    int x, y, cnt;

    Info(int x, int y, int cnt) : x(x), y(y), cnt(cnt){}
};

int R, C, s_x, s_y;
int map[50][50];
int waterMap[50][50];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int, int>> waters;
bool waterVisited[50][50];
bool hedgehogVisited[50][50];

bool inRange(int x, int y){
    return x >= 0 && y >= 0 && x < R && y < C;
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R;i++){
        string input;
        cin >> input;
        for(int j = 0 ; j < C;j++){
            map[i][j] = input[j];
            if(map[i][j] == '*') waters.push_back(make_pair(i, j));
            if(map[i][j] == 'S') {
                s_x = i;
                s_y = j;
            }
        }
    }

    // water BFS
    queue<Info> q;
    for(auto p : waters){
        q.push(Info(p.first, p.second, 0));
        waterVisited[p.first][p.second] = true;
    }

    while(!q.empty()){
        Info cur = q.front();
        q.pop();
        for(int i = 0; i < 4;i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(!inRange(nx, ny) || waterVisited[nx][ny] || map[nx][ny] == 'X' || map[nx][ny] == 'D') continue;
            waterVisited[nx][ny] = true;
            q.push(Info(nx, ny, cur.cnt + 1));
            waterMap[nx][ny] = cur.cnt + 1;
        }
    }

    // hedgehog BFS
    bool flag = false;
    int ans = 0;
    q.push(Info(s_x, s_y, 0));
    hedgehogVisited[s_x][s_y] = true;
    while(!q.empty()){
        Info cur = q.front();
        q.pop();
        if(map[cur.x][cur.y] == 'D'){
            flag = true;
            ans = cur.cnt;
        }
        for(int i = 0; i < 4;i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(!inRange(nx, ny) || hedgehogVisited[nx][ny] || map[nx][ny] == 'X') continue;
            if(waterMap[nx][ny] != 0 && waterMap[nx][ny] <= cur.cnt+1) continue;
            hedgehogVisited[nx][ny] = true;
            q.push(Info(nx, ny, cur.cnt + 1));
        }
    }
    if(flag) cout << ans << endl;
    else cout << "KAKTUS" << endl;

    return 0;
}