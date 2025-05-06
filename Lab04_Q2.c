// Leetcode Problem 200: Number of Islands
/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally
or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

void dfs(char **grid, int row, int col, int rows, int cols)
{
    // Check bounds and stop if it's water or already visited
    if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == '0')
        return;

    // Mark the land as visited
    grid[row][col] = '0';

    // Recursively explore all 4 adjacent directions
    dfs(grid, row - 1, col, rows, cols); // up
    dfs(grid, row + 1, col, rows, cols); // down
    dfs(grid, row, col - 1, rows, cols); // left
    dfs(grid, row, col + 1, rows, cols); // right
}

int numIslands(char **grid, int gridSize, int *gridColSize)
{
    // Empty grid = 0 islands
    if (grid == NULL || gridSize == 0 || gridColSize == NULL)
        return 0;

    // Initialize a counter to track number of islands
    int count = 0;
    // Iterate over every cell in the grid
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[i]; j++)
        {
            // If find a land cell ('1'), it's a new island
            if (grid[i][j] == '1')
            {
                // add to island counter
                count++;
                // mark that whole island as visited
                dfs(grid, i, j, gridSize, gridColSize[i]);
            }
        }
    }
    return count;
}