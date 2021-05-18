#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return dfs(arr, start, visited);
    }

private:
    bool dfs(vector<int>& arr, int s, vector<bool>& visited) {
        if (s < 0 || s >= arr.size() || visited[s])
            return false;
        visited[s] = true;
        if (0 == arr[s])
            return true;
        return dfs(arr, s - arr[s], visited) || dfs(arr, s + arr[s], visited);
    }
};
