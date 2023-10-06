//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse(Node *head){
        if(!head or !head -> next){
            return head;
        }
        Node *node = head, *prev = NULL;
        while(node){
            Node *temp = node -> next;
            if(node){
                node -> next = prev;
            }
            prev = node;
            node = temp;
        }
        return prev;
    }
    void rearrange(struct Node *odd){
        if(!odd or !odd -> next){
            return;
        }
        Node *even = odd -> next;
        Node *even_head = even;
        Node *odd_head = odd;
        while(even and even -> next){
            if(odd){
                odd -> next = even -> next;
                odd = odd -> next;
            }
            if(even){
                even -> next = odd -> next;
                even = even -> next;
            }
        }
        if(odd){
            odd -> next = reverse(even_head);
        }
        odd = odd_head;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends