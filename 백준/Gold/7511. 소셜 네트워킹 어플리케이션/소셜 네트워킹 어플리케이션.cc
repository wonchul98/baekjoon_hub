#include<iostream>

using namespace std;

int T, n, k, m;

int parent[100'001];

int findParent(int a){
    if(parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

void unionGroup(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a != b) parent[a] = b;
}

bool isConnected(int a, int b){
    return findParent(a) == findParent(b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    cin >> T;
    for(int test_case = 1;test_case <= T;test_case++){
        cout << "Scenario " << test_case << ":\n";
        cin >> n;

        //부모 배열 초기화
        for(int i = 0 ; i <= n;i++){
            parent[i] = i;
        }

        cin >> k;
        for(int i = 0; i < k;i++){
            int a, b;
            cin >> a >> b;
            unionGroup(a, b);
        }
        cin >> m;
        for(int i = 0; i < m;i++){
            int a, b;
            cin >> a >> b;
            cout << (isConnected(a, b) ? 1 : 0) << "\n";
        }
        cout << "\n";
    }
    return 0;
}