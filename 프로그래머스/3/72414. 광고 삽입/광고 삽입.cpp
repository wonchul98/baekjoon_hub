#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

long long window[360'000];

string to_time(int sec) {
    int hours = sec / 3600;
    sec %= 3600;

    int minutes = sec / 60;
    sec %= 60;

    int seconds = sec;

    stringstream ss;
    ss << setw(2) << setfill('0') << hours << ":"
       << setw(2) << setfill('0') << minutes << ":"
       << setw(2) << setfill('0') << seconds;

    return ss.str();
}

string find_max_window(int play_time_sec, int adv_time_sec){
    long long cur_window = 0;
    int ret_sec = 0;

    for(int i = 0; i < adv_time_sec; i++){
        cur_window += window[i];
    }

    long long cur_max_window = cur_window;

    for(int i = adv_time_sec; i < play_time_sec; i++){
        cur_window = cur_window - window[i - adv_time_sec] + window[i];
        if(cur_max_window < cur_window) {
            ret_sec = i - adv_time_sec + 1;
            cur_max_window = cur_window;
        }
    }
    return to_time(ret_sec);
}

void make_window(vector<pair<int, int>> &v, int play_time_sec){
    fill(window, window + play_time_sec + 2, 0);

    for(auto &vv : v){
        if(vv.second == 0) window[vv.first] += 1; 
        else window[vv.first] -= 1;    
    }

    for(int i=1; i<=play_time_sec; i++){
        window[i] += window[i-1];
    }
}

int to_sec(string time){
    int hour = stoi(time.substr(0, 2));
    int min = stoi(time.substr(3, 2));
    int sec = stoi(time.substr(6, 2));

    return hour * 3600 + min * 60 + sec;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int play_time_sec = to_sec(play_time);
    int adv_time_sec = to_sec(adv_time);

    vector<pair<int,int>> v;
    for(string log : logs){
        int start = to_sec(log.substr(0, 8));
        int end = to_sec(log.substr(9, 8));
        v.push_back(make_pair(start, 0));
        v.push_back(make_pair(end, 1));
    }

    sort(v.begin(), v.end());

    make_window(v, play_time_sec);
    return find_max_window(play_time_sec, adv_time_sec);
}
