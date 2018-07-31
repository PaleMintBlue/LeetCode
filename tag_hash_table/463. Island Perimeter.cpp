class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int neighbour = 0;
        int island = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0;j < grid[i].size(); j++)
            {
                if(grid[i][j])
                {
                    island++;
                    if(i<grid.size()-1&&grid[i+1][j])
                        neighbour++;
                    if(j<grid[i].size()-1&&grid[i][j+1])
                        neighbour++;
                }
            }
        }
        return island*4-neighbour*2;
    }
};