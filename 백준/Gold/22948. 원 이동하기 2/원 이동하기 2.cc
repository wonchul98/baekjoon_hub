#include<bits/stdc++.h>

using namespace std;

struct Info{
    int num;
    int x;
    string status;

    Info(int num, int x, string status) : num(num), x(x), status(status){}

    bool operator<(const Info& I) const{
        return x > I.x;
    }
};

priority_queue<Info> pq;
stack<int> s;
vector<int> connected[200'001];
bool visited[200'001];
vector<int> visiting;

void connect(int n1, int n2){
    connected[n1].push_back(n2);
    connected[n2].push_back(n1);
}

void DFS(int n, int end){
    visited[n] = true;
    visiting.push_back(n);
    if(n==end) {
        cout << visiting.size() << endl;
        for(int n : visiting) cout << n <<" ";
        cout << "\n";
    }
    for(int next : connected[n]){
        if(visited[next]) continue;
        DFS(next, end);
    }
    visited[n] = false;
    visiting.erase(visiting.end() - 1);
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N;i++) {
        int num, x, r;
        cin >> num >> x >> r;
        pq.push(Info(num, x-r, "open"));
        pq.push(Info(num, x+r, "close"));
    }
    
    s.push(0);
    for(int i = 0;i < 2 * N;i++) {
        Info cur = pq.top();
        pq.pop();
        // cout << cur.status << endl;
        if(cur.status.compare("open") == 0){
            connect(s.top(), cur.num);
            s.push(cur.num);
        }else{
            s.pop();
        }
    }

    int start, end;
    cin >> start >> end;
    

    // DFS
    DFS(start, end);

    return 0;
}