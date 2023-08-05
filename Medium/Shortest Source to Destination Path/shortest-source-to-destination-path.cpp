//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y){
        if(A[0][0] == 0){
            return -1;
        }
        if(X == 0 and Y == 0){
            return 0;
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        vector<vector<int>> distance(N, vector<int>(M, INT_MAX));
        distance[0][0] = 0;
        vector<int> dist_x = {-1, 0, 1, 0}, dist_y = {0, -1, 0, 1};
        while(!q.empty()){
            int dist = q.front().first;
            pair<int, int> temp = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                if(temp.first + dist_x[i] < N and temp.first + dist_x[i] >= 0 and temp.second + dist_y[i] < M and temp.second + dist_y[i] >= 0 and A[temp.first + dist_x[i]][temp.second + dist_y[i]] == 1 and dist + 1 < distance[temp.first + dist_x[i]][temp.second + dist_y[i]]){
                    distance[temp.first + dist_x[i]][temp.second + dist_y[i]] = dist + 1;
                    if(X == temp.first + dist_x[i] and Y == temp.second + dist_y[i]){
                        return dist + 1;
                    }
                    q.push({dist + 1, {temp.first + dist_x[i], temp.second + dist_y[i]}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends