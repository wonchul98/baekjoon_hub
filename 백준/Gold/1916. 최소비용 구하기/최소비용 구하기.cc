#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

struct Info {
    int node, distance;
    bool operator<(const Info& c) const {
        return distance > c.distance;
    }
};

vector<Info> vec[100001];
int dist[100001];

void dijkstra(int start) {
    priority_queue<Info> pq;
    pq.push({ start, 0 });
    dist[start] = 0;

    while (!pq.empty()) {
        int cur = pq.top().node;
        int distance = pq.top().distance;
        pq.pop();

        if (dist[cur] < distance) continue;

        for (Info next : vec[cur]) {
            int nextNode = next.node;
            int nextDistance = distance + next.distance;

            if (nextDistance < dist[nextNode]) {
                dist[nextNode] = nextDistance;
                pq.push({ nextNode, nextDistance });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int start, end;
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) dist[i] = INF;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({ v, w });
    }

    cin >> start >> end;
    dijkstra(start);

    cout << dist[end] << endl;
    return 0;
}
