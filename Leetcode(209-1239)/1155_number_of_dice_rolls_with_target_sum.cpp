class Solution {
public:
    void print(vector<int>&vec)
    {
        cout<<endl;
        for(int i=0;i<vec.size();i++)
        {
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    
    //Recursive definiton
    /*Sum(6, 3, 8) = Sum(6, 2, 7) + Sum(6, 2, 6) + Sum(6, 2, 5) + 
               Sum(6, 2, 4) + Sum(6, 2, 3) + Sum(6, 2, 2)

To evaluate Sum(6, 3, 8), we need to evaluate Sum(6, 2, 7) which can 
recursively written as following:
Sum(6, 2, 7) = Sum(6, 1, 6) + Sum(6, 1, 5) + Sum(6, 1, 4) + 
               Sum(6, 1, 3) + Sum(6, 1, 2) + Sum(6, 1, 1)

We also need to evaluate Sum(6, 2, 6) which can recursively written
as following:
Sum(6, 2, 6) = Sum(6, 1, 5) + Sum(6, 1, 4) + Sum(6, 1, 3) +
               Sum(6, 1, 2) + Sum(6, 1, 1)
..............................................
..............................................
Sum(6, 2, 2) = Sum(6, 1, 1)*/
    
    //dp for the same
    int numRollsToTarget(int num_dice, int num_faces, int target) {
        vector<vector<int>>num_ways(num_dice+1,vector<int>(target+1,0));
        
        for(int sum_possible=1;sum_possible<=num_faces and sum_possible<=target;sum_possible++)
        {
            num_ways[1][sum_possible]=1;
        }
        for(int i=2;i<=num_dice;i++)
        {
            for(int j=1;j<=target;j++)
            {
                for(int k=1;k<=num_faces and k<j;k++)
                {
                    num_ways[i][j]=num_ways[i][j]+num_ways[i-1][j-k];
                     if(num_ways[i][j]>=(1e9+7))
                        {
                            num_ways[i][j]-=(1e9+7);
                        }
                }
            }
                
            }
        
        
        return num_ways[num_dice][target];
       }
};