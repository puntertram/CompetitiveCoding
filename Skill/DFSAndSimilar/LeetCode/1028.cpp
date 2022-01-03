#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;

/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 /**/
class Solution {
    stack<TreeNode*> S;
public:
    TreeNode* recoverFromPreorder(string traversal) {
        
        while(!traversal.empty()) {
            // extract the number of dashes 
            int dashes = 0;
            while(!isdigit(traversal[0])) {
                traversal.erase(traversal.begin());
                ++dashes;
            }

            // extract the node number 
            int nodeValue = 0;
            while(isdigit(traversal[0])) {
                nodeValue = nodeValue * 10 + (traversal[0] - '0');
                traversal.erase(traversal.begin());
            }
            if(!S.empty() and (S.size() > dashes)) {
                TreeNode* cur = S.top();
                S.pop();
                while((!S.empty()) and (S.size() >= dashes)) {
                    addChild(S.top(), cur);
                    cur = S.top();
                    S.pop();
                }
                S.push(cur);
            }
            TreeNode *node = new TreeNode(nodeValue);
            S.push(node);
        }
        TreeNode* cur = NULL;
        if(!S.empty()) {
            cur = S.top();
            S.pop();
            while(!S.empty()) {
                addChild(S.top(), cur);
                cur = S.top();
                S.pop();
            }
        }
        return cur;
    }
    void addChild(TreeNode* par, TreeNode* child) {
        if(!par->left) {
            par->left = child;
        } else if(!par->right) {
            par->right = child;
        } else {
            exit(-1);
        }
    }
};


int main() {
    Solution *S = new Solution();
    TreeNode *root = S->recoverFromPreorder("1-2--3---4----5---7----8----9-6");

    return 0;
}