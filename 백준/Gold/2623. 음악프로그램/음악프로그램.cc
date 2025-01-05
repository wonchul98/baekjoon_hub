#include<iostream>
#include<vector>

using namespace std;

int N, M; // N : 가수의 수, M : PD의 수
int left_node;
int before_count[1001];
bool visited[1001];
bool flag;

 // N은 1이상 1,000이하의 정수이고, M은 1이상 100이하의 정수

vector<vector<int>> next_node(1001); //현재 노드 다음에 와야하는 노드들

vector<int> scan(){ // before count가 0인 노드
    vector<int> ret;
    for(int i = 1; i <= N;i++){
        if(before_count[i] == 0 && !visited[i]){
            ret.push_back(i);
            left_node--;
            visited[i] = true;
        }
    }
    return ret;
}

void print_info(){
    cout << "left_node: " << left_node << endl;
    for(int i = 1 ; i <= N;i++){
        cout << "before_count[" << i <<"]: " << before_count[i] << endl; 
    }
    cout <<"---------------------"<<endl;
}

int main(){
    cin >> N>> M;
    left_node = N; // 몇개의 노드가 남았는지
    for(int i = 0; i < M;i++){
        int num;
        cin >> num;
        int before, cur;
        for(int j= 0; j < num;j++){
            int cur;
            cin >> cur;
            if(j != 0) {
                next_node[before].push_back(cur);
                before_count[cur]++;
            }
            before = cur;
        }
    }

    vector<int> ans;
    while(left_node>0){
        // print_info();
        vector<int> z_node = scan();
        if(z_node.size() == 0){
            flag = true;
            break;
        }
        for(int i = 0; i < z_node.size();i++){
            int cur_node = z_node[i];
            for(int j = 0; j < next_node[cur_node].size();j++){
                int n_node = next_node[cur_node][j];
                if(visited[n_node]) { // 다음 노드가 이미 방문했던 노드 -> 모순 발생
                    flag = true;
                    break;
                }
                before_count[n_node]--;
            }
            ans.push_back(z_node[i]);
        }
        // cout << "//////////" << left_node << endl;
    }

    if(flag){
        cout << "0" << endl;
        return 0;
    }

    for(int i = 0; i < ans.size();i++){
        cout << ans[i] << "\n";
    }
    return 0;
}