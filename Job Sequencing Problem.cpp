#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// struct Job {
//     int id;     // Job Id
//     int dead;   // Deadline of job
//     int profit; // Profit if job is done
// };

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

class Solution 
{
public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, compare);
        
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        vector<bool> slot(maxDeadline + 1, false);
        
        int jobCount = 0; 
        int totalProfit = 0; 
        
        for (int i = 0; i < n; i++) {
            for (int j = min(maxDeadline, arr[i].dead); j > 0; j--) {
                if (!slot[j]) {
                    slot[j] = true; 
                    jobCount++;
                    totalProfit += arr[i].profit; 
                    break; 
                }
            }
        }
        
        return {jobCount, totalProfit};
    } 
};
