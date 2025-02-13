#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        int input;
        cin >> input;
        auto pos = lower_bound(v.begin(), v.end(), input);
        if(pos == v.end())v.push_back(input);
        else{
            *pos = input;
        }
    }
    cout << v.size() << endl;

    return 0;
}