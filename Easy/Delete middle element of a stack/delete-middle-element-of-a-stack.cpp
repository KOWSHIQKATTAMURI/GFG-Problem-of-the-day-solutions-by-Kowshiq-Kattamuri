//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    void deleting(stack<int>& s, int n, int &index){
        if(index == (n - (ceil((n + 1)/2)))){
            s.pop();
            return;
        }
        int start = s.top();
        s.pop();
        index += 1;
        deleting(s, n, index);
        s.push(start);
    }
    void deleteMid(stack<int>&s, int sizeOfStack){
        int n = sizeOfStack, index = 0;
        deleting(s, n, index);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends