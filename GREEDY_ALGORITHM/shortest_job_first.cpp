/*
The shortest job first (SJF) or shortest job next is a scheduling policy 
that selects the waiting process with the smallest execution time to execute next. 
Given an array of integers bt[] of size n, where bt[] denotes the burst time of each process, 
calculate the average waiting time of all the processes and return the nearest integer 
which is smaller or equal to the output.

Note: Consider all processes are available at time 0.

Examples:
Input: bt[] = [4,3,7,1,2]
Output: 4
Explanation: After sorting burst times by shortest job policy, 
calculated average waiting time is 4.

Input: bt[] = [1,2,3,4]
Output: 2
*/

class Solution {
  public:
    int solve(vector<int>& a) {
        sort(a.begin(), a.end());  // SJF order
        int waitingtime = 0, totaltime = 0;
        int n = a.size();

        for(int i = 0; i < n; i++) {
            waitingtime += totaltime;   // waiting time of current process
            totaltime += a[i];          // advance CPU time
        }

        return waitingtime / n;  // floor division
    }
};
