#include <iostream>
#include <vector>
using namespace std;

// O(nLog(n)) time | O(n) space
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
    sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){return a[0] < b[0];});// O(nLog(n)) time
    vector<vector<int> *> mergedIntervals;// O(n) space
    vector<int> *currentInterval = &intervals[0];// O(1) space
    mergedIntervals.push_back(currentInterval);// O(1) time
    for(vector<int> &nextInterval : intervals) {// O(n) time
        int currentLast = currentInterval->at(1);// O(1) time | O(1) space
        int nextFirst = nextInterval[0];// O(1) time | O(1) space
        int nextLast = nextInterval[1];// O(1) time | O(1) space
        if(currentLast >= nextFirst) {// O(1) time
            currentInterval->at(1) = max(currentLast, nextLast);// O(1) time
        } else {
            currentInterval = &nextInterval;// O(1) time
            mergedIntervals.push_back(currentInterval);// O(1) time
        }
    }
    vector<vector<int>> mergedIntervalsCopy;// O(n) space
    for(auto interval : mergedIntervals) {// O(n) time
        mergedIntervalsCopy.push_back(*interval);// O(1) time
    }
    return mergedIntervalsCopy;
}

int main() {
    vector<vector<int>> input = {
            {1, 2},
            {3, 5},
            {4, 7},
            {6, 8},
            {9, 10}
    };
    vector<vector<int>> result = mergeOverlappingIntervals(input);
    for(const vector<int>& interval : result) {
        for(int element : interval) {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}
