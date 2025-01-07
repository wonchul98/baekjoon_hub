#include<iostream>

using namespace std;

int N, M; //파티장의 크기 N(5 ≤ N ≤ 500)과 서비스를 요청한 손님의 수 M(1 ≤ M ≤ 10,000)
int map[501][501];

string isAble(int from, int to, int time){
    return map[from][to] <= time ? "Enjoy other party" : "Stay here";
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= N;j++){
            cin >> map[i][j];
        }
    }

    //floyd warshall
    for(int mid = 1; mid <= N; mid++){
        for(int start = 1; start <= N;start++){
            if(mid == start) continue;
            for(int end = 1; end <=N;end++){
                if(start == end) continue;
                map[start][end] = min(map[start][end], map[start][mid]+ map[mid][end]);
            }
        }
    }

    for(int i = 0; i < M;i++){
        int from, to, time;
        cin >> from >> to >> time;
        cout << isAble(from, to, time) << endl;
    }

    return 0;
}