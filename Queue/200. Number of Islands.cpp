
/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/queue-stack/kbcqv/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
private:
    void bfs(vector<vector<char>>& grid, int r, int c)
    {
        queue<pair<int,int>> que;
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c]=='1') que.push(make_pair(r-1,c));
        if (c - 1 >= 0 && grid[r][c-1]=='1') que.push(make_pair(r,c-1));
        if (r + 1 < nr && grid[r+1][c]=='1') que.push(make_pair(r+1,c));
        if (c + 1 < nc && grid[r][c+1]=='1') que.push(make_pair(r,c+1));
        if (que.size() != 0)
        {
            while(que.size() != 0)
            {
                auto q = que.front();
                que.pop();
                bfs(grid, q.first, q.second);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (nr == 0)
        {
            return 0;
        }
        int nc = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (grid[i][j] == '1')
                {
                    cnt++;
                    bfs(grid, i, j);
                }
            }
        }

        return cnt;
        
         
    }
};



/*
DFS

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num = 0;
        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (grid[i][j] == '1')
                {
                    num++;
                    dfs(i, j, grid);
                }
            }
        }
        return num;
        
    }

    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[x][y] = '0';

        if (x - 1 >= 0 && grid[x-1][y] == '1') dfs(x-1, y, grid);
        if (x + 1 < nr && grid[x+1][y] == '1') dfs(x+1, y, grid);
        if (y - 1 >= 0 && grid[x][y-1] == '1') dfs(x, y-1, grid);
        if (y + 1 < nc && grid[x][y+1] == '1') dfs(x, y+1, grid);
    }
};
*/