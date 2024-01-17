class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
if(isWater[i][j] == 1){
    ans[i][j] = 0;
    q.push({i,j});
}
            }
        }
while(!q.empty()){
    auto node = q.front();
         q.pop();

int row = node.first;
int col = node.second;

int val = ans[row][col];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
for(int i=0;i<4;i++){
   int x = dx[i] + row;
   int y = dy[i] + col;

if(x >= 0 && x<n && y>=0 && y<m)
{
    if(ans[x][y] == -1)
    {
        ans[x][y] = val+1;
        q.push({x,y});
    }
}
}
}
return ans;
    }
};
