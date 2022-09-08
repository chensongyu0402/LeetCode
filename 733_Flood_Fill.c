void DFS(int** image, int sr, int sc, int row_size, int col_size, int old_color, int new_color)
{
    if(image[sr][sc] == old_color) {
        image[sr][sc] = new_color;
        if(sr > 0)
            DFS(image, sr - 1, sc, row_size, col_size, old_color, new_color);
        if(sr < row_size - 1)
            DFS(image, sr + 1, sc, row_size, col_size, old_color, new_color);
        if(sc > 0)
            DFS(image, sr, sc - 1, row_size, col_size, old_color, new_color);
        if(sc < col_size - 1)
            DFS(image, sr, sc + 1, row_size, col_size, old_color, new_color);
    }
}
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes)
{
    int col_size = *imageColSize;
    int row_size = imageSize;
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    if(image[sr][sc] == color)
        return image;
    DFS(image, sr, sc, row_size, col_size, image[sr][sc], color);
    return image;
}