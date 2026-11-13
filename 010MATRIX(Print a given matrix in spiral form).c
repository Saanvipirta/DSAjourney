//You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.
#include <stdio.h>

void spirallyTraverse(int m, int n, int mat[m][n], int res[])
{
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int k = 0; // index for result array

    while (top <= bottom && left <= right)
    {
        // store top row
        for (int i = left; i <= right; i++)
        {
            res[k++] = mat[top][i];
        }
        top++;

        // store right column
        for (int i = top; i <= bottom; i++)
        {
            res[k++] = mat[i][right];
        }
        right--;

        // store bottom row if exists
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                res[k++] = mat[bottom][i];
            }
            bottom--;
        }

        // store left column if exists
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                res[k++] = mat[i][left];
            }
            left++;
        }
    }
}

int main()
{
    int mat[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    int m = 4, n = 4;
    int res[m * n];

    spirallyTraverse(m, n, mat, res);

    for (int i = 0; i < m * n; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
