//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
     void topo(int i, vector<int> &vis, stack<int> &s, vector<pair<int, int>> adj[]){
         vis[i] = true;
         for(auto it : adj[i]){
             if(!vis[it.first]){
                 topo(it.first, vis, s, adj);
             }
         }
         s.push(i);
     }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        for(int i = 0; i < M; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        stack<int> s;
        vector<int> vis(N, false);
        for(int i = 0; i < N; i++){
            if(!vis[i]){
                topo(i, vis, s, adj);
            }
        }
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while(!s.empty() and s.top() != 0){
            s.pop();
        }
        while(!s.empty()){
            int node = s.top();
            s.pop();
            for(auto it : adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends