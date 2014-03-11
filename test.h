#ifndef _TEST_H_
#define _TEST_H_
#include<string>
#include<vector>
#include<stack>
#include<iostream>

using namespace std;

namespace _TEST{
    int candy(vector<int> &ratings);
    int findmaxlenth(vector<int> &vec,int begin,int end);
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



    class TreeConstruct{
    public:
        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

        static TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
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

        static TreeNode* buildTree2(vector<int> &preorder,vector<int> &inorder){
            assert(preorder.size() == inorder.size());
            if(preorder.empty())
                return NULL;
            TreeNode * tmpNode = new TreeNode(preorder[0]);
            vector<int>::iterator iter = inorder.begin();
            while(iter != inorder.end()){
                if(*iter == preorder[0])
                    break;
                ++iter;
            }
            vector<int> in2;
            in2.assign(++iter,inorder.end());
            inorder.erase(--iter,inorder.end());
            vector<int> pre2;
            pre2.reserve(inorder.size());
            iter = preorder.end();
            for(int i = 0 ; i <in2.size();++i)
                --iter;
            pre2.assign(iter,preorder.end());
            preorder.erase(iter,preorder.end());
            preorder.erase(preorder.begin());
            tmpNode->left = buildTree(preorder,inorder);
            tmpNode->right = buildTree(pre2,in2);
            return tmpNode;
        }
    };

    class ListSolution{
    public:
        struct ListNode{
            int val;
            ListNode *next;
            ListNode(int x):val(x),next(NULL){}
        };
        static ListNode* mergeTwoList(ListNode* l1,ListNode* l2)
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

        static ListNode* insertionSortList(ListNode* head){
            if(!head || !head->next)
                return head;
            ListNode* curr = head->next;
            ListNode* currpre = head;
            while(curr){
                ListNode *p1,*pre;
                p1 = pre = head;
                if(curr->val < p1->val){
                    currpre->next = curr->next;
                    head = curr;
                    head->next = p1;
                    curr = currpre->next;
                    continue;
                }else{
                    p1 = p1->next;
                    while(p1!=curr && curr->val > p1->val){
                        p1 = p1->next;
                        pre = pre->next;
                    }
                    if(p1 == curr){
                        currpre=curr;
                        curr = curr->next;
                    }else{
                        currpre->next = curr->next;
                        curr->next = pre->next;
                        pre->next = curr;
                        curr = currpre->next;
                    }

                }
            }
            return head;
        }
        static void printList(ListNode* l1){
            while(l1){
                cout<<l1->val<<"  ";
                l1 = l1->next;
            }
            cout<<endl;
        }
    };

    class TreeNodeSolution{
    public:
        struct TreeNode{
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x):val(x),left(NULL),right(NULL){}
        };
        static void PostOrder(TreeNode* root){
            if(!root)   return;
            stack<TreeNode*> S;
            TreeNode* tmp;
            TreeNode* pre = NULL;
            S.push(root);
            while(!S.empty()){
                tmp = S.top();
                if((!tmp->left && !tmp->right) || (pre && (pre == tmp->left || pre==tmp->right))){
                    cout<<tmp->val<<" ";
                    S.pop();
                    pre = tmp;
                }else{
                    if(tmp->right)
                        S.push(tmp->right);
                    if(tmp->left)
                        S.push(tmp->left); 
                }
            }
        }
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
        vector<int> vec;
        vec.push_back(1);
        vec.push_back(0);
        vec.push_back(2);

  /*      vec.push_back(1);
        vec.push_back(6);
        vec.push_back(7);
        vec.push_back(8);
        vec.push_back(9);
        vec.push_back(8);
        vec.push_back(7);
        vec.push_back(6);
        vec.push_back(5);
        vec.push_back(4);
        vec.push_back(3);
        vec.push_back(2);
        vec.push_back(1);
  */
        candy(vec);
        /*  ListSolution::ListNode head(4);
        ListSolution::ListNode l1(3);
        ListSolution::ListNode l2(4);
        ListSolution::ListNode l3(5);
        head.next = &l1;
        ListSolution::printList(&head);
        ListSolution::printList(ListSolution::insertionSortList(&head));
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
        TreeNodeSolution::PostOrder(tmproot);
        vector<vector<int> > vecRes = TreeNodeSolution::pathSum(tmproot,22);
        TreeNodeSolution::printResult(vecRes);

        vector<int> inorder1,preorder1;
        inorder1.push_back(1);inorder1.push_back(2);
        preorder1.push_back(2);preorder1.push_back(1);
        TreeConstruct::TreeNode* tmp = TreeConstruct::buildTree2(inorder1,preorder1);

        string aa = "aabac";
        cout<<palindromeSolution1::longestPalindrome(aa);
        palindromeSolution1::printRes(palindromeSolution1::Findpalindrome(aa));


        //test buildTree
        vector<int> inorder,postorder;
        inorder.push_back(1);inorder.push_back(3);inorder.push_back(2);
        postorder.push_back(3);postorder.push_back(2);postorder.push_back(1);
        TreeConstruct::TreeNode *tmp2 = TreeConstruct::buildTree(inorder,postorder);
        */
    }


    int candy(vector<int> &ratings){
        int candies = 0;
        if(ratings.empty())
            return 0;
        int begin = 0,end = 0;
        bool tag = true;//递增
        candies = findmaxlenth(ratings,0,ratings.size()-1);
        
        return candies;
    }
    int findmaxlenth(vector<int> &vecinput,int beginpos,int endpos){  //找出连续递增或者递减最大的长度
        if(beginpos> endpos)
            return 0;

        vector<int> vec;
        for(int i = beginpos; i <= endpos; ++i){
            vec.push_back(vecinput[i]);
        }
        int begin = 0,end = 0;
        int length = 0;
        int maxlength = length;
        int beginpre = 0;
        int beginnow = 0;
        bool tag = true; //tag=true递增 ,false 递减
        for(int i = 1 ; i < vec.size(); ++i){
            if(vec[i]>vec[i-1] && tag){
                length += 1;
                tag = true;
            }else if(vec[i]>vec[i-1] && !tag){
                if(maxlength <length){
                    beginpre = beginnow;
                    maxlength = length;
                }
                beginnow = i-1;
                length = 1;
                tag = true;
            }else if(vec[i]<vec[i-1] &&  tag){
                if(maxlength < length){
                    beginpre = beginnow;
                    maxlength = length;
                }
                beginnow = i-1;
                length = 1;
                tag = false;
            }else if(vec[i]<vec[i-1] && !tag){
                length +=1;
                tag = false;
            }
        }
        if(maxlength < length){
            maxlength = length;
            begin = beginnow;
            end = begin + maxlength;
        }
        else{
            begin = beginpre;
            end = begin+maxlength;
        }
        
        int candy =  (int)(maxlength+1)*(maxlength+2)/2;
        if(vecinput[beginpos+begin]<=vecinput[beginpos+end] && begin>0 && 
            vecinput[beginpos + begin]>vec[beginpos + begin-1])
            candy += maxlength+1;
        else if(vecinput[beginpos + begin] >= vecinput[beginpos + end] && end<=vec.size()-1 &&
            vecinput[beginpos + end]>vecinput[beginpos + end+1])
            candy +=maxlength+1;
        return candy + findmaxlenth(vecinput,beginpos + 0,beginpos + begin-1) +
            findmaxlenth(vecinput,beginpos + end+1,vecinput.size()-1);
    }
}
#endif