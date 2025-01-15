#include<bits/stdc++.h>

using namespace std;

int N, M, X;
vector<vector<int>> fwd(10'001);
vector<vector<int>> rvs(10'001);
bool visited[10'001];

int main(){
    cin >> N >> M >> X;

    for(int i = 0; i < M;i++){
        int to, from;
        cin >> to >> from;
        fwd[from].push_back(to);
        rvs[to].push_back(from);
    }
    int nextCnt = 0;

    // BFS forward
    queue<int> q;
    q.push(X);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        nextCnt++;
        visited[cur] = true;
        for(int next : fwd[cur]){
            if(visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }

    // BFS reverse
    for(int i = 1; i<= N;i++){
        visited[i] = false;
    }
    int prevCnt = 0.;
    q.push(X);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        prevCnt++;
        visited[cur] = true;
        for(int next : rvs[cur]){
            if(visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }
    cout << nextCnt << " " << N + 1 - prevCnt << endl;
    return 0;
}