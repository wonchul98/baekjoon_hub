#include <iostream>
#include <queue>
using namespace std;

int K, W, H;
int board[200][200];
bool visited[31][200][200];

int monkeyDx[4] = {-1,0,1,0};
int monkeyDy[4] = {0,1,0,-1};
int horseDx[8]  = {-2,-1,1,2, 2, 1,-1,-2};
int horseDy[8]  = {1, 2,2,1,-1,-2,-2,-1};

struct State {
    int x, y, kUsed, dist;
};

bool inRange(int x, int y) {
    return (0 <= x && x < H && 0 <= y && y < W);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> W >> H;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> board[i][j];
        }
    }

    // BFS 초기화
    queue<State> q;
    visited[K][0][0] = true;
    q.push({0, 0, K, 0});

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int kLeft = q.front().kUsed;
        int dist = q.front().dist;
        q.pop();

        if(x == H-1 && y == W-1) {
            cout << dist << "\n";
            return 0; 
        }

        for(int i=0; i<4; i++){
            int nx = x + monkeyDx[i];
            int ny = y + monkeyDy[i];
            if(inRange(nx, ny) && !board[nx][ny] && !visited[kLeft][nx][ny]) {
                visited[kLeft][nx][ny] = true;
                q.push({nx, ny, kLeft, dist+1});
            }
        }

        if(kLeft > 0){
            for(int i=0; i<8; i++){
                int nx = x + horseDx[i];
                int ny = y + horseDy[i];
                if(inRange(nx, ny) && !board[nx][ny] && !visited[kLeft-1][nx][ny]) {
                    visited[kLeft-1][nx][ny] = true;
                    q.push({nx, ny, kLeft-1, dist+1});
                }
            }
        }
    }

    // 도달 불가
    cout << -1 << "\n";
    return 0;
}
