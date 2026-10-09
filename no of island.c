#include <stdio.h>

void dfs(char grid[3][4], int i, int j)
{
    if (i < 0 || i >= 3 || j < 0 || j >= 4)
        return;

    if (grid[i][j] == '0')
        return;

    grid[i][j] = '0';

    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
}

int numIslands(char grid[3][4])
{
    int i, j, count = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;
}

int main()
{
    char grid[3][4] = {
        {'1', '1', '0', '0'},
        {'1', '0', '0', '1'},
        {'0', '0', '1', '1'}
    };

    printf("Number of islands = %d\n", numIslands(grid));

    return 0;
}