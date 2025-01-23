#include<iostream>
#include<vector> 
using namespace std;

int k, n; // 참가 인원 / 줄 수
string start, result;
vector<string> lines;
bool same[26];

void goDown(int a){
    string curLine = lines[a];
    string temp;
    temp = start; 
    for(int i =0; i < k-1;i++){
        if(curLine[i] == '-'){
            temp[i] = start[i+1];
            temp[i+1] = start[i];
        }
    }

    start = temp;
}

void goUp(int a){
    string curLine = lines[a];
    string temp;
    temp = result; 
    for(int i =0; i < k-1;i++){
        if(curLine[i] == '-'){
            temp[i] = result[i+1];
            temp[i+1] = result[i];
        }
    }
    result = temp;
}

string findAns(){
    string ret;
    for (int i = 0; i < k - 1; i++){
        if (start[i] == result[i]){
            ret.push_back('*');
        }else if(start[i] == result[i + 1] && start[i + 1] == result[i]) {
            swap(start[i], start[i + 1]);
            ret.push_back('-');
        }else{
            string disable;
            for (int j = 0; j < k - 1; j++){
                disable.push_back('x');
            }
            return disable;
        }
    }
    return ret;
}

int main(){
    cin >> k;
    cin >> n;
    for(int i = 0; i < k;i++){
        start.push_back('A' + i);
    }

    cin >> result;
    int qLine;
    
    for(int i = 0; i < n;i++){
        string input;
        cin >> input;
        lines.push_back(input);
        if(input[0] == '?') qLine = i;
    }

    for(int i = 0; i < qLine;i++){
        goDown(i);
    }
    for(int i = n - 1; i > qLine;i--){
        goUp(i);
    }
    cout << findAns() << endl;
    return 0;
}