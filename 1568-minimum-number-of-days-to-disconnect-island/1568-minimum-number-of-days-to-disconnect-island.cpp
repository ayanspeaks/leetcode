class Solution {
public:
    int get_index(int x,int y,int n)
    {
        return (x * n) + y;
    }
    int solve_grid(vector<vector<int>>&grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int max_index = m * n;
        vector<pair<int,int>>list;
        vector<bool>visited(max_index,false);
        int icount = 0;
        for(int i = 0;i<m;i++)
        {   
            for(int j = 0;j<n;j++)
            {

                if((visited[get_index(i,j,n)] == false) && (grid[i][j] == 1) )
                {
                    // cout<<"i "<<i<<" j "<<j<<endl;
                    icount++;
                    visited[get_index(i,j,n)] = true;
                    list.push_back({i,j});
                    for(int k = 0;k<list.size();k++)
                    {
                        int currx = list[k].first;
                        int curry = list[k].second;
                        if(currx > 0)
                        {
                            if((visited[get_index(currx-1,curry,n)] == false) && (grid[currx-1][curry] == 1))
                            {
                                visited[get_index(currx-1,curry,n)] = true;
                                list.push_back({currx-1,curry});
                            }
                        }
                        if(currx < m-1)
                        {
                            if((visited[get_index(currx+1,curry,n)] == false) && (grid[currx+1][curry] == 1))
                            {
                                visited[get_index(currx+1,curry,n)] = true;
                                list.push_back({currx+1,curry});
                            }
                        }
                        if(curry > 0)
                        {
                            if((visited[get_index(currx,curry-1,n)] == false) && (grid[currx][curry-1] == 1))
                            {
                                visited[get_index(currx,curry-1,n)] = true;
                                list.push_back({currx,curry-1});
                            }
                        }
                        if(curry < n-1)
                        {
                            if((visited[get_index(currx,curry+1,n)] == false) && (grid[currx][curry+1] == 1))
                            {
                                visited[get_index(currx,curry+1,n)] = true;
                                list.push_back({currx,curry+1});
                            }
                        }
                    }
                }
            }
        }
        // icount = 100;
        // cout<<"icount "<<icount<<endl;
        // cout<<"returning from i count"<<endl;
        return icount;
    }
    int minDays(vector<vector<int>>& grid) {
        // cout<<"solve grid"<<solve_grid(grid)<<endl;
        // cout<<"start"<<endl;
        int curriland = solve_grid(grid);
        // cout<<"iland "<<curriland<<endl;
        if(curriland != 1)
        {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {    
                    grid[i][j] = 0;
                    int iland = solve_grid(grid);
                    if(iland != 1)
                    {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
