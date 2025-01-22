#include<iostream>

using namespace std;

struct Info {
    int x1, y1, x2, y2;

    Info(){}
    Info(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2){}
};

int parent[1000];
Info infos[1000];
int N;
bool rootVisited[1000];

int getParent(int a){
    if(parent[a] == a) return a;
    return parent[a] = getParent(parent[a]);
}

void unionGroup(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if(a == b) return;
    parent[a] = b;
}

bool isConnect(int i, int j){
    Info a = infos[i];
    Info b = infos[j];
    
	if (b.y2 > a.y2 && a.x2 < b.x2 && a.y1 > b.y1 && b.x1 < a.x1)
		return false;
	if (a.y2 > b.y2 && b.x2 < a.x2 && b.y1 > a.y1 && b.x1 > a.x1)
		return false;
	if (b.y1 > a.y2 || b.x1 > a.x2 || a.y1 > b.y2 || b.x2 < a.x1)
		return false;
	return true;
}

bool containOrigin(Info a){
    return (a.x1 == 0 && a.y1 * a.y2 <= 0 ) || (a.x2 == 0 && a.y1 * a.y2 <= 0 ) || 
            (a.y1 == 0 && a.x1 * a.x2 <= 0 ) || (a.y2 == 0 && a.x1 * a.x2 <= 0 ); 
}

int main(){
    cin >> N;
    for(int i = 0; i < N;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        infos[i] = Info(x1, y1, x2, y2);
    }

    for(int i = 0; i < N;i++) parent[i] = i;
    
    for(int i = 0 ; i <= N-2;i++){
        for(int j = i + 1; j <= N-1;j++){
            if(isConnect(i, j)) {
                unionGroup(i, j);
            }
        }
    }

    // 몇 덩어리인지 
    int cnt = -1;
    for(int i = 0; i < N;i++){
        if(!rootVisited[getParent(i)]){
            cnt++;
            rootVisited[getParent(i)] = true;
        }
    }

    // (0,0)을 포함하는지 
    bool flag = false;
    for(int i = 0; i < N;i++){
        if(containOrigin(infos[i])){
            flag = true;
            break;
        }
    }
    if(!flag) cnt++;
    cout << cnt << endl;
    return 0;
}