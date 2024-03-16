
#include<stdio.h>
#include<stdlib.h>
const int N = 1e1 + 6; //定义一个常量N
int n;
int st[N];//  记录每个位置当前的状态：0表示还没考虑，1表示选它，2表示不选它

void dfs(int u)  //枚举的第几个数字
{
    if (u > n) {
       // 终止条件，因为题目要求一个就n个数 所以只有 u > n 就输出枚举的方案
            for (int i = 1; i <= n; i++)
                if (st[i] == 1)
                    printf("%d ", i);
        puts("");
        return;
    }
    st[u] = 1;  // 选它的分支
        dfs(u + 1);
    st[u] = 0;  //  恢复现场，以便进行下一个分支


        st[u] = 2; //  不选它的分支
        dfs(u + 1);
     st[u] = 0;    // 恢复现场
}
int main(void)
{
    scanf_s("%d", &n);
    dfs(1);
    return 0;
}
