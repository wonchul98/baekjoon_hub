#include<bits/stdc++.h>

using namespace std;

struct Lecture{
    int lectureNum, start, end;

    Lecture(int lectureNum, int start, int end) : lectureNum(lectureNum), start(start), end(end){}

	bool operator<(Lecture a){
		if(start == a.start) return end < a.end;
		return start < a.start;
	}
};

int N, mmax = 0;
vector<Lecture> v;

void print_vector(vector<int> v){
    for(int vv : v){
        cout << vv << " ";
    }
    cout << "\n";
}

int main(){
    cin >> N;

    for(int i = 0; i < N;i++){
        int lectureNum, start, end;
        cin >> lectureNum >> start >> end;
		v.push_back(Lecture(lectureNum, start, end));
    }

	sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for(Lecture cur : v){        
        while(!pq.empty() && cur.start >= pq.top()){
            pq.pop();
        }
        pq.push(cur.end);
        mmax = max(mmax, (int)pq.size());
    }
    cout << mmax << endl;

    return 0;
}