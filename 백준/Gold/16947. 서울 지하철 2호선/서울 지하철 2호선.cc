#include<iostream>
#include<vector>

using namespace std;

bool isCycle[3001];
bool isVisited[3001];
int dist[3001]; // 노드 - 순환선 거리
int N;
bool startFlag;
bool findFlag;

vector<vector<int>> nextNodes(3001);

void DFS(int startNode, int beforNode, int curNode){
    // cout << "DFS: " << startNode <<", " << curNode << endl;
    isVisited[curNode] = true;
    if(curNode == startNode){
        if(startFlag){
            startFlag = false;
            isVisited[curNode] = false; // 시작 노드를 재 방문할 수 있도록
        }else{
            isCycle[curNode] = true;
            findFlag = true;
            return;
        }
    }
    for(auto nextNode : nextNodes[curNode]){
        if(isVisited[nextNode] || nextNode == beforNode) continue;
        DFS(startNode, curNode, nextNode);
        if(findFlag) return;
    }
}

int distDFS(int dist, int node){
    // cout << "distDFS " << dist << " " << node << endl;
    isVisited[node] = true;
    if(isCycle[node]) return dist;
    for(auto nextNode : nextNodes[node]){
        if(isVisited[nextNode]) continue;
        int curDist = distDFS(dist + 1, nextNode);
        if(curDist != 0) return curDist;
    }
    return 0;
}

void initVisited(){
    for(int i = 1; i <= N;i++){
        isVisited[i] = false;
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N;i++){
        int left, right;
        cin >> left >> right;
        nextNodes[left].push_back(right);
        nextNodes[right].push_back(left);
    }
    for(int i = 1;i <= N;i++){
        startFlag = true;
        findFlag = false;
        DFS(i, 0, i);
        initVisited();
    }

    for(int i = 1;i <= N;i++){
        dist[i] = distDFS(0, i);
        initVisited();
    }

    for(int i = 1;i<=N;i++){
        cout << dist[i] << " "; 
    }
    cout << "\n";
    
    return 0;
}