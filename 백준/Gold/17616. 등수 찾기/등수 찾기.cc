#include <bits/stdc++.h>
using namespace std;

int N, M, X;
vector<vector<int>> fwd(100001);
vector<vector<int>> rvs(100001);
bool visited[100001];

int bfs(vector<vector<int>> &graph, int start) {
    fill(visited, visited + N + 1, false); // visited 초기화
    queue<int> q;
    int cnt = 0;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;

        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return cnt;
}

int main() {
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        fwd[from].push_back(to); // 정방향 그래프
        rvs[to].push_back(from); // 역방향 그래프
    }

    int nextCnt = bfs(fwd, X);
    int prevCnt = bfs(rvs, X);

    int U = prevCnt;         
    int V = N - nextCnt + 1; 
    cout << U << " " << V << endl;

    return 0;
}
