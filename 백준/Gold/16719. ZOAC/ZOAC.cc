#include<iostream>

using namespace std;

string str;
bool visited[101];

void printWord(){
    for(int i = 0; i < str.length();i++){
        if(visited[i]) cout << str[i];
    }
    cout << "\n";
}

void recur(int s, int e){
    if(s > e) return;
    // printf("recur(%d, %d)\n", s, e);
    int cur = 'Z' + 1;
    int idx = 0;
    for(int i = s; i <= e;i++){
        int c = str[i];
        if(c < cur){
            idx = i;
            cur = c;
        }
    }
    visited[idx] = true;
    printWord();
    recur(idx+1,e);
    recur(s, idx-1);
}

int main(){
    
    cin >> str;
    recur(0, str.length()-1);
    return 0;
}