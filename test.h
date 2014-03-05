#ifndef _TEST_H_
#define _TEST_H_
#include<string>
#include<iostream>

using namespace std;

namespace _TEST{
struct Node{
    int value;
    struct Node* next;
};

void splitlink(Node* src,Node* &ls1,Node* &ls2)
{
    Node *p2 = src->next;
    while(p2 && p2->next){
        ls2 = ls2->next;
        p2 = p2->next->next;
    }
    p2 = ls2;
    ls2 = ls2->next;
    p2->next = NULL;
}

Node* MergeSort(Node* src){
    if(!src || !(src->next))
        return src;
    Node *ls1,*ls2;
    ls1 = ls2 = src;
    splitlink(src,ls1,ls2);
    ls1 = MergeSort(ls1);
    ls2 = MergeSort(ls2);
    Node *lshead,*lstail;
    lshead = lstail = NULL;
    while(ls1 && ls2){
        if(ls1->value >= ls2->value){
            if(!lstail){
                lshead = lstail = ls1;
                ls1 = ls1->next;
                lstail->next = NULL;
                continue;
            }
            lstail->next = ls1;
            ls1 = ls1->next;
            lstail->next->next = NULL;
            lstail = lstail->next;
        }else{
            if(!lstail){
                lshead = lstail = ls2;
                ls2 = ls2->next;
                lstail->next = NULL;
                continue;
            }
            lstail->next = ls2;
            ls2 = ls2->next;
            lstail->next->next = NULL;
            lstail = lstail->next;
        }
    }
    if(ls1) lstail->next = ls1;
    if(ls2) lstail->next = ls2;
    return lshead;
}


struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
     if(inorder.empty())
            return NULL;
        assert(inorder.size() == postorder.size());
    if(postorder.size() == 1){
        TreeNode *tmp = (struct TreeNode*)malloc(sizeof(TreeNode));
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->val = postorder[0];
        return tmp;
    }
    TreeNode *tmp= (struct TreeNode*)malloc(sizeof(TreeNode));
    tmp->val = postorder[postorder.size()-1];
    int i = 0;
    vector<int>::iterator iter = inorder.begin();
    while(iter!=inorder.end()){
        if(*iter == postorder[postorder.size()-1])
            break;
        ++iter;
        ++i;
    }
    vector<int> vecin2;  
    vecin2.reserve(inorder.size()-i-1);
    vector<int>::iterator iter2 = iter;
    while((++iter2)!=inorder.end()){
        vecin2.push_back(*iter2);
    }
    inorder.erase(iter,inorder.end());
    i = 0;
    vector<int> vecpost2;
    vecpost2.reserve(vecin2.size());
    iter = postorder.begin();
    while(i<inorder.size()){
        ++iter;
        ++i;
    }
    for(i=inorder.size(); i < postorder.size()-1;++i)
        vecpost2.push_back(postorder[i]);
    postorder.erase(iter,postorder.end());
    tmp->left = buildTree(inorder,postorder);
    tmp->right = buildTree(vecin2,vecpost2);
    return tmp;
}
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* mergeTwoList(ListNode* l1,ListNode* l2)
{
    if((!l1) && (!l2))
        return NULL;
    ListNode* l3, *tail;
    l3 = tail = NULL;
    while(l1 && l2){
        if(l1->val >= l2->val){
            if(!tail){
                l3 = tail = l1;
                l1 = l1->next;
                tail->next = NULL;
            }else{
                tail->next = l1;
                l1 = l1->next;
                tail->next->next = NULL;
                tail = tail->next;
            }
        }else{
            if(!tail){
                l3 = tail = l2;
                l2 = l2->next;
                tail->next=NULL;
            }else{
                tail->next = l2;
                l2 = l2->next;
                tail->next->next = NULL;
                tail = tail->next;
            }
        }
    }
    if(l1){
        if(!tail)
            l3 = tail = l1;
        else{
            tail->next = l1;
        }
    }
    if(l2){
        if(!tail)
            l3 = tail = l2;
        else 
            tail->next = l2;
    }
    return l3;
}

void printList(ListNode* l1){
    while(l1){
        cout<<l1->val<<"  ";
        l1 = l1->next;
    }
    cout<<endl;
}

class TreeNodeSolution{
public:
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x):val(x),left(NULL),right(NULL){}
    };
    static vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> vecTmp;
        vector<vector<int> > vecRes;
        if(root)
            findpath(root,sum,vecRes,vecTmp);
        return vecRes;
    }
    static void findpath(TreeNode* root,int sum,vector<vector<int> > &vecRes,vector<int> vecTmp){
        if(!root->left && !root->right && sum == root->val){
            vecTmp.push_back(root->val);
            vecRes.push_back(vecTmp);
            return;
        }
        vecTmp.push_back(root->val);
        if(root->left){
            findpath(root->left,sum-root->val,vecRes,vecTmp);
        }
        if(root->right){
            findpath(root->right,sum-root->val,vecRes,vecTmp);
        }
        return;
    }
    static void printResult(vector<vector<int> > &vec){
        for(int i = 0; i < vec.size(); ++i){
            for(int j = 0 ; j < vec[i].size(); ++j)
                cout<<vec[i][j]<<" ";
            cout<<endl;
        }
    }
};
    
class palindromeSolution1{
public:

    //找出一个字符串中的所有回文字串
    static vector<string> Findpalindrome(string S){
        vector<string> vecStr;
        for(int i = 0 ; i < S.length(); ++i){
            int j = 0;
            while((i-j)>=0 && (i+j)<S.length()){
                if(S[i-j] == S[i+j]){
                    string stmp = S.substr(i-j,1+2*j);
                    vecStr.push_back(stmp);
                    ++j;
                }else
                    break;
            }
            j = i+1;
            int k = i;
            while(k>=0 && j<S.length()){
                if(S[k] == S[j]){
                    string stmp = S.substr(k,j-k+1);
                    vecStr.push_back(stmp);
                    --k;
                    ++j;
                }else
                    break;
            }
        }
        return vecStr;
    }
    static string longestPalindrome(string s) {
        string stmp;
        int rb=0;
        int rl=0;
        for(int i = 0 ; i < s.length();++i){
            int j = 0;
            while((i-j) >=0 && (i+j)<s.length()){
                if(s[i-j] != s[i+j]){
                    if(rl < 2*j-1){
                        rb = i-j+1;
                        rl = 2*j-1;
                    }
                    break;
                }
                ++j;
            }
            if(rl<2*j-1){
                rb = i-j+1;
                rl = 2*j-1;
            }
            j = i;
            int k = i+1;
            while(j>=0 && k<s.length()){
                if(s[j]!=s[k]){
                    if(rl < k-j-1){
                        rb=j+1;
                        rl = k-j-1;
                    }
                    break;
                }
                --j;
                ++k;
            }
            if(rl<k-j-1){
                rb = j+1;
                rl = k-j-1;
            }
        }
        stmp = s.substr(rb,rl);
        return stmp;
    }
    static void printRes(const vector<string> &vecRes){
        for(int i= 0 ; i < vecRes.size();++i)
            cout<<vecRes[i]<<endl;
    }
};



void test(){

    string aa = "aabac";
    cout<<palindromeSolution1::longestPalindrome(aa);
    palindromeSolution1::printRes(palindromeSolution1::Findpalindrome(aa));
    
    //test list merge sort
    struct Node *head,*tail;
    head = new Node;
    head->value = 0;
    head->next = 0;
    tail = head;
    for(int i = 1; i < 5;i++){
        struct Node *node = new Node;
        node->value = 9-i;
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
    }
    tail = MergeSort(head);
    //test buildTree
    vector<int> inorder,postorder;
    inorder.push_back(1);inorder.push_back(3);inorder.push_back(2);
    postorder.push_back(3);postorder.push_back(2);postorder.push_back(1);
    TreeNode *tmp = buildTree(inorder,postorder);

    //test merge two list
    ListNode* l1 = NULL;
    ListNode* l2 = new ListNode(0);
    ListNode* l3 = mergeTwoList(l1,l2);
    printList(l3);

    //test TreeNodeSolution
    TreeNodeSolution::TreeNode *tmproot = new TreeNodeSolution::TreeNode(5);
    TreeNodeSolution::TreeNode *left0= new TreeNodeSolution::TreeNode(4);
    tmproot->left = left0;
    TreeNodeSolution::TreeNode *right0 = new TreeNodeSolution::TreeNode(8);
    tmproot->right = right0;
    TreeNodeSolution::TreeNode *left1 = new TreeNodeSolution::TreeNode(11);
    left0->left = left1;
    TreeNodeSolution::TreeNode *left2 = new TreeNodeSolution::TreeNode(7);
    left1->left = left2;
    TreeNodeSolution::TreeNode *right1 = new TreeNodeSolution::TreeNode(2);
    left1->right = right1;
    TreeNodeSolution::TreeNode *left3 = new TreeNodeSolution::TreeNode(13);
    right0->left = left3;
    TreeNodeSolution::TreeNode *right2 = new TreeNodeSolution::TreeNode(4);
    right0->right = right2;
    TreeNodeSolution::TreeNode *left4 = new TreeNodeSolution::TreeNode(5);
    right2->left = left4;
    TreeNodeSolution::TreeNode *right3 = new TreeNodeSolution::TreeNode(1);
    right2->right = right3;
    vector<vector<int> > vecRes = TreeNodeSolution::pathSum(tmproot,22);
    TreeNodeSolution::printResult(vecRes);
}

}
#endif