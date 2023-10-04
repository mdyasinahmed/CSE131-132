#include<bits/stdc++.h>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

void selectActivities(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compareActivities);

    int selected = 0;
    cout << "Selected activities: ";
    cout << "(";
    cout << activities[selected].start << ", " << activities[selected].finish;
    cout  << ") ";

    for(int i = 1; i<activities.size(); i++) {
        if(activities[i].start >= activities[selected].finish) {
            selected = i;
            cout << "(";
            cout << activities[selected].start << ", " << activities[selected].finish;
            cout  << ") ";
        }
    }

    cout << endl;
}

int main() {
    vector<Activity> activities = {{1, 3}, {2, 5}, {3, 6}, {5, 7}, {6, 8}, {8, 9}};

    selectActivities(activities);

    return 0;
}
