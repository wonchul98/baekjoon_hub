#include<bits/stdc++.h>

using namespace std;

int n, m; //n : 컴퓨터 수, m : 연결 수
int parent[1'001];

struct INFO{
    int from, to, dist;

    INFO(int from, int to, int dist) : from(from), to(to), dist(dist) {}

    bool operator<(const INFO& a) const{
        return dist > a.dist;
    }
};

vector<INFO> ans;

int findParent(int a){
    if(parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

void unionGroup(int a, int b){
    a = findParent(a);
    b = findParent(b);
    
    if(a == b) return;

    parent[a] = b;
}

bool isUnion(int a, int b){
    return findParent(a) == findParent(b);
}

int main(){
    priority_queue<INFO> pq;
    
    cin >> n >> m;
    for(int i = 1; i <= n;i++) parent[i] = i;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        unionGroup(x, y);
    }
    
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n;j++){
            int distance;
            cin >> distance;
            if(i == 1 || j == 1 || i==j) continue;
            pq.push(INFO(i, j, distance));
        }
    }
    while(!pq.empty()){
        INFO cur = pq.top();
        pq.pop();
        if(isUnion(cur.from, cur.to)) continue;
        unionGroup(cur.from, cur.to);
        ans.push_back(cur);
    }
    int cnt = 0;
    for(INFO info : ans){
        cnt += info.dist;
    }
    cout << cnt << " " << ans.size() << endl;
    for(int i = 0; i < ans.size();i++){
        cout << ans[i].from << " " << ans[i].to << endl;
    }
    return 0;
}