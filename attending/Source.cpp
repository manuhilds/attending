#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
    int s_time;
    int duration;
    int e_time;
};

struct Available_Workshops {
    int n{};
    Workshop* aw = new Workshop[n];
};

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    Available_Workshops* me = new Available_Workshops;
    Workshop* w = new Workshop[n];
    for (int i{}; i < n; ++i) {
        w[i].s_time = start_time[i];
        w[i].duration = duration[i];
        w[i].e_time = start_time[i] + duration[i];
    }
    me->n = n;
    me->aw = w;
    return me;
}
bool passable(vector<vector<int>> list, vector<int>w) {
    bool good = true;
    for (auto i : list)
    {
        if (!(w[0] > i[1] || i[0] > w[1]))
        {
            good = false;
            break;
        }
        
    }
    return good;
}
int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int max{};
    sort(ptr->aw[0].e_time, ptr->aw[ptr->n].e_time);
    for (int i{}; i < ptr->n; ++i)
    {
        int count{};
        vector<vector<int>> list{ { ptr->aw[i].s_time,ptr->aw[i].e_time } };
        for (int j{ i+1 }; j < ptr->n; ++j)
        {
            vector<int>w{ ptr->aw[j].s_time,ptr->aw[j].e_time };
            //bool my{ (ptr->aw[i].s_time >= ptr->aw[j].e_time) || (ptr->aw[j].s_time >= ptr->aw[i].e_time) };
            //if (my)
            //    count++;
            if (passable(list, w))
            {
                list.push_back(w);
                count++;
            }
        }
        max = (max > count) ? max : count;
    }
    return max;
}

int main(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}