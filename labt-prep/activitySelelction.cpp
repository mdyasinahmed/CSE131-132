#include<bits/stdc++.h>
using namespace std;

// 1
struct Activity{
    int start;
    int finish;
};

bool compareActivities(const Activity& a, const Activity& b){
    return a.finish < b.finish;
}

void selectActivities(vector <Activity>& activities) {
    // sort basis on finish time
    sort(activities.begin(), activities.end(), compareActivities);

    // select activity
    int selected = 0;
    cout << "Selected: " << "(";
    cout << activities[selected].start << "," << activities[selected].finish << ") ";

    // compare activity
    for(int i=1; i<activities.size(); i++) {
        if(activities[i].start >= activities[selected].finish){
            selected = i;
            cout << "(" << activities[selected].start << ", " << activities[selected].finish << ") ";
        }
    }

    cout << endl;
}



int main() {
    // vector <data-type> name(amra jekta dimu)
    vector <Activity> activity = {
        {1,3}, 
        {2,5},
        {3,6},
        {5,3},
        {6,8},
        {8,9},
    };
    selectActivities(activity);
}