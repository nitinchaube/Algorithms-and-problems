//find the pair of array having maximum XOR number of pair.


#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
        trieNode* left;
        trieNode* right;
};

void insertNode(trieNode* head,int n){
    trieNode *curr=head;
    for(int i=31;i>=0;i--){
        int b= (n>>i) & 1;
        if(b==0){
            if(!curr->left){
                curr->left=new trieNode();
            }
            curr=curr->left;
        }else{
            if(!curr->right){
                curr->right=new trieNode();
            }
            curr=curr->right;
        }
    }
}

int findMaxXOrPair(trieNode * head,int n,int *arr){
    int max_pair=INT_MIN;
    for(int i=0;i<n;i++){
        int value=arr[i];
        trieNode *curr=head;
        int curr_sum=0;
        for(int j=31;j>=0;j--){
            int b=(value>>j)&1;

            if(b==0){
                if(curr->right){
                    curr=curr->right;
                    curr_sum+=pow(2,j);
                }else{
                    curr=curr->left;
                }
            }else {
                if(curr->left){
                    curr=curr->left;
                    curr_sum+=pow(2,j);
                }else{
                    curr=curr->right;
                }
            }
        }
        if(curr_sum > max_pair){
            max_pair=curr_sum;
        }
    }
    return max_pair;
}

int main(){
    //int n;
    //cin>>n;

    // int *arr=new int[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // },,
    int arr[]={8,1,2,15,10,5};
    trieNode* head=new trieNode();
    for(int i=0;i<6;i++){
        insertNode(head,arr[i]);
    }

   cout<< findMaxXOrPair(head,6,arr)<<endl;
   return 0;
}

