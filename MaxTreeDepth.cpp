#include<string>
#include<vector>
#include<stack>
#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k):val(k),left(NULL),right(NULL){}
};

int FindMaxDepth(TreeNode* root);
void InOrder(TreeNode* root);
void PreOrder(TreeNode* root);
void PostOrder(TreeNode* root);
int main()
{
    TreeNode root(1);
    TreeNode left1(2);
    TreeNode right1(3);
    TreeNode right2(4);
    root.left = &left1;
    root.right = &right1;
    left1.right = &right2;
    InOrder(&root);
    PreOrder(&root);
    //FindMaxDepth(&root);

    return 1;
}
void PreOrder(TreeNode* root){
    cout<<"PreOrder:"<<endl;
    if(!root)
        return;
    stack<TreeNode*> S;
    TreeNode* tmp = root;
    while(tmp || !S.empty()){
        while(tmp){
            S.push(tmp);
            cout<<tmp->val<<" ";
            tmp = tmp->left;
        }
        if(!S.empty()){
            tmp = S.top();
            S.pop();
            tmp = tmp->right;
        }
    }
    cout<<endl;
}
void InOrder(TreeNode* root){
    cout<<"InOrder:"<<endl;
    if(!root)
        return;
    stack<TreeNode*> S;
    TreeNode* tmp = root;
    while(tmp!=NULL ||!S.empty()){
        while(tmp!=NULL){
            S.push(tmp);
            tmp = tmp->left;
        }
        if(!S.empty()){
            tmp = S.top();
            cout<<tmp->val<<"\t";
            S.pop();
            tmp = tmp->right;
        }
    }
    cout<<endl;
}
void PostOrder(TreeNode* root){
    if(!root)
        return;
    stack<TreeNode*> S;
    TreeNode* tmp  = root;
    bool bDirect = false; //false==left  true==true
    while(tmp || !S.empty()){
        while(tmp){
            S.push(tmp);
            tmp = tmp->left;
        }
        if(!S.empty()){
            tmp = S.top();
            if(!tmp->right){
                cout<<tmp->val<<" ";
                S.pop();
                if(!bDirect){
                    tmp = S.top();
                    tmp = tmp->right;
                    bDirect = true;
                }else{
                    tmp = S.top();
                    bDirect = false;
                }
            }else{
                tmp = tmp->right;
                bDirect = false;
            }
        }
    }
}

int FindMaxDepth(TreeNode* root)
{
    if(!root)
        return 0;
    int max = 0;
    int depth = 0;
    stack<TreeNode*> S;
    S.push(root);

    TreeNode* tmp = root;
    while(!S.empty()){
        
    }
    cout<<"max depth:"<<max<<endl;
}


