int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
vector<vector<bool>>visited;

bool is_valid(int i, int j, int x, int y)
{
    if(i<0 or j<0 or i >x or j>y) return false;
    return true;
}

bool is_inside_any_circle(int x1,int y1,int num_circles,int radius, vector<int> &x_centers, vector<int> &y_centers)
{
    for(int i=0;i<num_circles;i++)
    {
        //(x-xc)^2 + (y-yc)^2 <=r^2
        if(pow((x1-x_centers[i]), 2)+pow((y1-y_centers[i]),2)<=pow(radius,2))
        {
            return true;
        }
    }
    return false;
}

void dfs(int i,int j,int x,int y,int num_circles,int radius, vector<int> &x_centers, vector<int> &y_centers)
{
 visited[i][j]=true;
 
 for(int k=0;k<8;k++)
 {
     int next_i=i+dx[k];
     int next_j=j+dy[k];
     
     if(is_valid(next_i,next_j,x,y) and !visited[next_i][next_j] and not is_inside_any_circle(next_i,next_j,num_circles,radius,x_centers,y_centers))
        {
            dfs(next_i,next_j,x,y,num_circles,radius,x_centers,y_centers);
        }
 }
 
    
}

string Solution::solve(int x, int y, int num_circles, int radius, vector<int> &x_centers, vector<int> &y_centers){
 
     visited.assign(x+1,vector<bool>(y+1,false));
     if(is_inside_any_circle(0,0,num_circles,radius,x_centers,y_centers))
     {
         return "NO";
     }
     
     dfs(0,0,x,y,num_circles,radius,x_centers,y_centers);
     if(visited[x][y])
     {
         return "YES";
     }
     return "NO";
 }
