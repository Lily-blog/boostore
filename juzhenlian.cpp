#include <cstdio>
#include <climits>
 
using namespace std;
#define MAX 2010
 
int ans[MAX][MAX] = {0}; // 保存矩阵链 A[i..j]的最小代价
int divide[MAX][MAX] = {0};   // 记录最小代价ans[i,j]对应的分割点
 
/* 计算n元矩阵链p的最优代价
 * 动态规划的每一步结果储存在 ans与 divide中 */
void MatrixChainOrder(int p[], int n) {
    /* 矩阵链长度为2到n */
    for (int l = 2; l <= n; l++) {
        /* 讨论长度为l的矩阵链A[i..j] */
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            ans[i][j] = INT_MAX;
            /* 依次讨论每一个分割点d:将矩阵链A[i..j]分成A[i..d]和 A[d+1..j] */
            for (int temp, d = i; d < j; d++) {
                temp = ans[i][d] + ans[d + 1][j] + p[i - 1] * p[d] * p[j];
                /* 记录下矩阵链A[i..j]最小的情况 */
                if (temp < ans[i][j]) {
                    ans[i][j] = temp;
                    divide[i][j] = d;
                }
            }
        }
    }
}
 
/* 根据divide数组，输出A[i..j]的最优情况 */
void PrintDivide(int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        int d = divide[i][j];  //找到分界点
        printf("(");
        PrintDivide(i, d);
        PrintDivide(d + 1, j);
        printf(")");
    }
}
 
int main() {
    int n;
    scanf("%d", &n);
    int p[MAX];
    for (int temp, i = 0; i <= n; i++)
        scanf("%d", &p[i]);
 
    MatrixChainOrder(p, n);
    printf("%d\n", ans[1][n]);
    if (n == 1)
        printf("(A1)");
    else
        PrintDivide(1, n);
    printf("\n");
}
 
