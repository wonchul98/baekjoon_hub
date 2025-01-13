/**
 * 상근이는 오른쪽 그림과 같은 지도에서 진행하는 게임을 만들었다.

지도는 총 2개의 줄로 나누어져 있으며, 각 줄은 N개의 칸으로 나누어져 있다. 칸은 위험한 칸과 안전한 칸으로 나누어져 있고, 안전한 칸은 유저가 이동할 수 있는 칸, 위험한 칸은 이동할 수 없는 칸이다.

가장 처음에 유저는 왼쪽 줄의 1번 칸 위에 서 있으며, 매 초마다 아래 세 가지 행동중 하나를 해야 한다.

한 칸 앞으로 이동한다. 예를 들어, 현재 있는 칸이 i번 칸이면, i+1번 칸으로 이동한다.
한 칸 뒤로 이동한다. 예를 들어, 현재 있는 칸이 i번 칸이면, i-1번 칸으로 이동한다.
반대편 줄로 점프한다. 이때, 원래 있던 칸보다 k칸 앞의 칸으로 이동해야 한다. 예를 들어, 현재 있는 칸이 왼쪽 줄의 i번 칸이면, 오른쪽 줄의 i+k번 칸으로 이동해야 한다.
N번 칸보다 더 큰 칸으로 이동하는 경우에는 게임을 클리어한 것이다.

게임을 재밌게 하기 위해서, 상근이는 1초에 한 칸씩 각 줄의 첫 칸이 사라지는 기능을 만들었다. 즉, 게임을 시작한지 1초가 지나면 1번 칸이 사라지고, 2초가 지나면 2번 칸이 사라진다. 편의상 유저가 먼저 움직이고, 칸이 사라진다고 가정한다. 즉, 이번에 없어질 칸이 3번 칸인데, 상근이가 3번 칸에 있다면, 3번 칸에서 다른 칸으로 이동하고 나서 3번 칸이 없어지는 것이다.

각 칸의 정보가 주어졌을 때, 게임을 클리어 할 수 있는지, 없는지 구하는 프로그램을 작성하시오.

첫째 줄에 N과 k가 주어진다. (1 ≤ N, k ≤ 100,000)

둘째 줄에는 왼쪽 줄의 정보가 주어진다. i번째 문자가 0인 경우에는 위험한 칸이고, 1인 경우에는 안전한 칸이다. 셋째 줄에는 오른쪽 줄의 정보가 주어지고, 각 문자의 의미는 왼쪽 줄의 의미와 동일하다.

왼쪽 줄의 1번 칸은 항상 안전한 칸이다.
 */

#include<bits/stdc++.h>

using namespace std;

int N, k;
string tiles[2];
bool visited[2][100'001];

struct INFO{
    int x, y, t;

    INFO(int x, int y, int t) : x(x), y(y), t(t){}
};

int flipflop(int a){
    if(a==0) return 1;
    return 0;
}

int main(){
    cin >> N >> k >> tiles[0] >> tiles[1];
    for(int i = 0; i < k;i++){
        tiles[0].push_back('1');
        tiles[1].push_back('1');
    }
    //BFS
    bool flag = false;
    queue<INFO> q;
    q.push(INFO(0,1,0));
    visited[0][1] =true;

    while(!q.empty()){
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int cur_t = q.front().t;
        // cout << cur_x << " " << cur_y << " " << cur_t << endl;
        q.pop();
        if(cur_y > N){
            flag = true;
            break;
        }
        int ff_x = flipflop(cur_x);
        if(tiles[cur_x][cur_y] == '1' && !visited[cur_x][cur_y + 1]) {
            q.push(INFO(cur_x, cur_y+1, cur_t + 1));
            visited[cur_x][cur_y+1] = true;
        }
        if(tiles[cur_x][cur_y - 2] == '1' && cur_y - 2 > cur_t && !visited[cur_x][cur_y - 1]) {
            q.push(INFO(cur_x, cur_y-1, cur_t + 1));
            visited[cur_x][cur_y-1] = true;
        }
        if(tiles[ff_x][cur_y + k - 1] == '1' && !visited[ff_x][cur_y + k]) {
            q.push(INFO(ff_x, cur_y + k, cur_t + 1));
            visited[ff_x][cur_y+k] = true;
        }
    }
    if(flag)cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}