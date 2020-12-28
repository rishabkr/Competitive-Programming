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
    int res;
    
    int solve(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        }
        int left_diameter=solve(node->left);
        int right_diameter=solve(node->right);
        
        int temp= max(left_diameter,right_diameter)+1;//includes self and passes to above
        
        int ans=max(temp,left_diameter+right_diameter+1);//doesnt pass above
        res=max(res,ans);
        
        return temp;//pass above
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        res=INT_MIN;
        solve(root);
        return res-1;
        
    }
};

//or
/*   if (tree == NULL)
        return 0;
 
    // get the height of left and right sub-trees 
    int lheight = height(tree->left);
    int rheight = height(tree->right);
 
    // get the diameter of left and right sub-trees
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
 
    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1
    
    return max(lheight + rheight + 1,
               max(ldiameter, rdiameter));
}*/