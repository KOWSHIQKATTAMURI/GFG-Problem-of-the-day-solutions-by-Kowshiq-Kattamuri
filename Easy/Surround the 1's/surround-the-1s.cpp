//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix){
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1){
                    int count = 0;
                    //up
                    if(i - 1 >= 0 and matrix[i - 1][j] == 0){
                        count++;
                    }
                    //down
                    if(i + 1 < n and matrix[i + 1][j] == 0){
                        count++;
                    }
                    //right
                    if(j + 1 < m and matrix[i][j + 1] == 0){
                        count++;
                    }
                    //left
                    if(j - 1 >= 0 and matrix[i][j - 1] == 0){
                        count++;
                    }
                    //rud
                    if(i - 1 >= 0 and j + 1 < m and matrix[i - 1][j + 1] == 0){
                        count++;
                    }
                    //lud
                    if(i - 1 >= 0 and j - 1 >= 0 and matrix[i - 1][j - 1] == 0){
                        count++;
                    }
                    //rdd
                    if(i + 1 < n and j + 1 < m and matrix[i + 1][j + 1] == 0){
                        count++;
                    }
                    //ldd
                    if(i + 1 < n and j - 1 >= 0 and matrix[i + 1][j - 1] == 0){
                        count++;
                    }
                    //final ans
                    if(count != 0 and count%2 == 0){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends