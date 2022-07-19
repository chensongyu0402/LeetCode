#include<stdio.h>
#include<stdlib.h>
static int compare(const void *a, const void *b)
{
    int *n1 = (int *)a;
    int *n2 = (int *)b;
    return ((n1[0] == n2[0]) ? (n1[1] - n2[1]) : (n1[0] - n2[0]));
}

int eraseOverlapIntervals(int intervals[][2], int intervalsSize, int* intervalsColSize)
{
    qsort(intervals, intervalsSize, sizeof(int *), compare);
    int count = 0;
    int curIdx = 0;
    for(int i = 1; i < intervalsSize; i++) {
        if(intervals[i][0] < intervals[curIdx][1]) {
            count ++;
            curIdx = ((intervals[i][1] < intervals[curIdx][1]) ? i : curIdx);
        }
        else {
            curIdx = i;
        }
    }
    return count;
}

int main()
{
    int intervalsSize;
    int intervalsColSize;
    printf("intervalsSize and intervalsColSize:");
    scanf("%d %d", &intervalsSize, &intervalsColSize);
    int intervals[intervalsSize][2];
    printf("intervals:");
    for(int i = 0; i < intervalsSize; i++)
        for(int j = 0; j < intervalsColSize; j++)
            scanf("%d", &intervals[i][j]);
    int min = eraseOverlapIntervals(intervals, intervalsSize, &intervalsColSize);
    printf("min = %d\n",min);
    return 0;
}