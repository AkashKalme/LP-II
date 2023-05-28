#include <iostream>
#include <algorithm>

using namespace std;

class Job
{
public:
    string id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

void jobSchedule(Job arr[], int n)
{
    sort(arr, arr + n, compare);
    int result[n] = {-1};
    bool slot[n] = {false};

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
}

int main()
{
    int n;
    cout << "Enter the Total Number of Jobs: ";
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++)
    {
        Job inp;
        inp.id = "Job" + to_string(i + 1);
        cout << "Input Deadline for Job " << i + 1 << ": ";
        cin >> inp.deadline;
        cout << "Enter Profit for Job " << i + 1 << ": ";
        cin >> inp.profit;
        arr[i] = inp;
    }
    cout << "Job Sequence for Maximum Profit: ";
    jobSchedule(arr, n);
    return 0;
}

// {{'a', 2, 20}, {'b', 2, 15}, {'c', 1, 10}, {'d', 3, 5}, {'e', 3, 1}}
// 7
// 4 60 2 40 2 20 6 70 5 50 3 30 1 10