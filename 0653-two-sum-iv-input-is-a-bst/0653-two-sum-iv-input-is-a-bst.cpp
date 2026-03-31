/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getNext(stack<TreeNode*>& st){
        TreeNode* top = st.top(); st.pop();
        if(top->right){
            TreeNode* curr = top->right;
            st.push(curr);
            while(curr->left){
                curr = curr->left;
                st.push(curr);
            }
        }
        return top->val;
    }
    int getBefore(stack<TreeNode*>& st){
        TreeNode* top = st.top(); st.pop();
        if(top->left){
            TreeNode* curr = top->left;
            st.push(curr);
            while(curr->right){
                curr = curr->right;
                st.push(curr);
            }
        }
        return top->val;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        stack<TreeNode*> nextStack;
        stack<TreeNode*> beforeStack;

        TreeNode* curr = root;
        nextStack.push(curr);
        while(curr->left){
            curr = curr->left;
            nextStack.push(curr);
        }
        int next = getNext(nextStack);

        curr = root;
        beforeStack.push(curr);
        while(curr->right){
            curr = curr->right;
            beforeStack.push(curr);
        }
        int before = getBefore(beforeStack);

        while(next < before){
            if(next + before == k)
                return true;
            else if(next + before < k)
                next = getNext(nextStack);
            else
                before = getBefore(beforeStack);
        }
        return false;
    }
};