 vector<TreeNode*> helper(int s,int e){
            //here we will try to genrate all possible nodes in the bst 
          //by considering each node as the root node
         //we will begin like if the          
        //root is  b->
       //then root->left is in the range(1,b-1);
      //ans root the right is in the range(b+1,n);
     
     
      vector<TreeNode*> temp;
        if(s>e){
            //basically it is our base case and we will return vector< here
            temp.push_back(NULL);
            return temp;
        }
        if(s==e){
            
            temp.push_back(new TreeNode(s));
            return temp;
        }
        
        for(int i=s;i<=e;i++){
            //here we do work for one node only
            //rest will be done by recursion itself
            //so we consider every node from start to end as the root node
            TreeNode* root= new TreeNode(s);
            //this call will give us the possible values of treenode in the left part
            vector<  TreeNode* >lef= helper(s,i-1);
            //This call will give right TreeNode values
            vector<  TreeNode* >rig=helper(i+1,e);
                    for(auto it:lef){
                        
                    for(auto jt:rig){
        //here we concatinate the all the values from the left and right part together
        //basically we are genrating all possible pattern of tree
                        TreeNode* root=new TreeNode(i);
                        root->left=it;
                        root->right=jt;
                        temp.push_back(root);
                    }
                }
              
        }
        //yay we found the answer 
        //return it from here
         return temp;
}
vector<TreeNode*> Solution::generateTrees(int A) {
return helper(1,A);
}
