#define INF 987654321
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> graph[10'001];

pair<int, vector<int>> dijkstra(int start, int target, vector<int> &dist) {
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
    
    pq.push({0, {start}});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [curDist, curPath] = pq.top();
        int curNode = curPath.back();
        pq.pop();

        if (curNode == target) {
            return {curDist, curPath};
        }

        for (auto [nextNode, weight] : graph[curNode]) {
            int newDist = curDist + weight;

            if (newDist < dist[nextNode]) {
                vector<int> newPath = curPath;
                newPath.push_back(nextNode);
                dist[nextNode] = newDist;
                pq.push({newDist, newPath});
            }
        }
    }
    return {INF, {}};
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back({to, 1});
        graph[to].push_back({from, 1});
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    int s, e;
    cin >> s >> e;

    vector<int> dist(N + 1, INF);
    auto [sToE, path] = dijkstra(s, e, dist);
    
    if (sToE == INF) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> dist2(N + 1, INF);
    for (int node : path) {
        dist2[node] = 0;  
    }
    dist2[s] = INF;  

    auto [eToS, path2] = dijkstra(e, s, dist2);
    
    if (eToS == INF) {
        cout << -1 << endl;
        return 0;
    }

    cout << sToE + eToS << endl;
    return 0;
}
