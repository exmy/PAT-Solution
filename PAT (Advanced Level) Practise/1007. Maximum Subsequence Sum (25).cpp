# include <stdio.h>

int main()
{
    //freopen("data.in", "r", stdin);
    int a[10001], n, thisSum, maxSum;
    int i, j, cnt;

    while(scanf("%d", &n) != EOF)
    {
        int start, end;
        thisSum = maxSum = 0;
        cnt = 0;
        for(i = j = 1; i <= n; i++)
        {
            scanf("%d", a + i);
            if(a[i] < 0) cnt++;
            thisSum += a[i];

            if(thisSum > maxSum){
                maxSum = thisSum;
                end = i;
                start = j;
            }
            if(thisSum < 0){
                thisSum = 0;
                j = i + 1;
            }
        }
       if(cnt == n){
            start = 1;
            end = n;
       }
        printf("%d %d %d\n", maxSum, a[start], a[end]);
    }
    return 0;
}
