#include <cstdio>
#include <climits>
 
using namespace std;
#define MAX 2010
 
int ans[MAX][MAX] = {0}; // ��������� A[i..j]����С����
int divide[MAX][MAX] = {0};   // ��¼��С����ans[i,j]��Ӧ�ķָ��
 
/* ����nԪ������p�����Ŵ���
 * ��̬�滮��ÿһ����������� ans�� divide�� */
void MatrixChainOrder(int p[], int n) {
    /* ����������Ϊ2��n */
    for (int l = 2; l <= n; l++) {
        /* ���۳���Ϊl�ľ�����A[i..j] */
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            ans[i][j] = INT_MAX;
            /* ��������ÿһ���ָ��d:��������A[i..j]�ֳ�A[i..d]�� A[d+1..j] */
            for (int temp, d = i; d < j; d++) {
                temp = ans[i][d] + ans[d + 1][j] + p[i - 1] * p[d] * p[j];
                /* ��¼�¾�����A[i..j]��С����� */
                if (temp < ans[i][j]) {
                    ans[i][j] = temp;
                    divide[i][j] = d;
                }
            }
        }
    }
}
 
/* ����divide���飬���A[i..j]��������� */
void PrintDivide(int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        int d = divide[i][j];  //�ҵ��ֽ��
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
 
