/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string ser="";
    int idx=0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
        {
            return "null";
        }

        return to_string(root->val)+' '+serialize(root->left)+' '+serialize(root->right)+' ';
    }

    // Decodes your encoded data to tree.
    
    TreeNode *deserialize_helper(stringstream &ss)
    {
        string s;
        if(!(ss>>s) || s=="null")
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(s));
        root->left=deserialize_helper(ss);
        root->right=deserialize_helper(ss);
        return root;
        
    }
    TreeNode* deserialize(string data) {
    stringstream ss(data);
        return deserialize_helper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));