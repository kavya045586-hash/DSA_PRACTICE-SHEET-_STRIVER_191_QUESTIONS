/*
Job Sequencing Problem:
Given two arrays `deadline[]` and `profit[]` of size N, where each job has a deadline and associated profit.
The task is to schedule jobs in such a way that the maximum number of jobs are done within their deadlines
and the total profit earned is maximized.

Return a vector of two integers:
1. The count of jobs done
2. The total profit earned
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        int count = 0, totalprofit = 0;
        int mx = *max_element(deadline.begin(), deadline.end());
        
        vector<pair<int,int>> jobs;
        vector<int> slot(mx+1, -1);  // slots for jobs
        
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        
        sort(jobs.rbegin(), jobs.rend());  // sort by profit descending
        
        for (auto &a : jobs) {
            int pf = a.first;
            int d  = a.second;
            
            for (int i = d; i > 0; i--) {
                if (slot[i] == -1) {
                    slot[i] = pf;
                    count++;
                    totalprofit += pf;
                    break;
                }
            }
        }
        
        return {count, totalprofit};
    }
};
