/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// we initialize the root as 0, 0 position, left of it we say -ve and right side we call +ve
// now everytime we go left we put the value of column as col-1 and viceversa

void levelorder(TreeNode* root, map<int, vector<int>>& hash)
{
    // make a queue that would hold values column number and values in that column
    queue<pair<TreeNode*, int>> Q; 
    // initialize it for root
    Q.push({root, 0});
    TreeNode* current;
    
    while(!Q.empty())
    {
        int size = Q.size();
        // for every level we do the following
        for(int i = 0; i<size; i++)
        {
            current = Q.front().first; // store the first element in current
            int col = Q.front().second; // store the column value for the element
            Q.pop();
            // corresponding to the col, we set the value to obtain vertical alignment
            hash[col].push_back(current->val); 
            // if we have node at left we reduce the column count and go left
            if(current->left != NULL) Q.push({current->left, col-1});
            // vice-versa
            if(current->right != NULL) Q.push({current->right, col+1});
        }
    }
        
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) 
{
    vector<vector<int>> answer;
    if(A == NULL) return answer;
    // we're using map because we want sorted keys, left most should occur first
    map<int, vector<int>> hash;
    
    levelorder(A, hash);
    // we have our hash map which has elements in each column 
    
    // take the values from the hash map and append in the answer
    for(auto& c : hash)
    {
        vector<int> current;
        for(auto& i : c.second)
            current.push_back(i);
        answer.push_back(current);
    }
    return answer;
    
}
