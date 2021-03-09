class Solution {
public:
    int minKnightMoves(int x, int y)
    {
     if(x==0 && y==0)
         return 0;
     if(x==1 && y==1)
         return 2;
     queue<pair<int,int>>q;
     q.push({0,0}); 
     int path=0;   
    vector<vector<int>>direction={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},             {-1,-2}};  
        
    unordered_map<int,unordered_map<int,bool>>mp;
    mp[0][0]=true;
        
        while(!q.empty())
        {
            path++;
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int>p;
                p=q.front();
                q.pop();
                for(const auto &itr:direction)
                {
                    
                    int n_x=itr[0]+p.first;
                    int n_y=itr[1]+p.second;
                    if(n_x==x && n_y==y){
                        return path;
                        break;
                        
                    }
                    if(mp[n_x][n_y]==false && n_x*x>=-1 && n_y*y>=-1){
                        mp[n_x][n_y]=true;
                        q.push({n_x,n_y});
                    }
                }
            }
        }
        return -1;
        
    }
};