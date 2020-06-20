#include <stdio.h>
#include <float.h>

using namespace std;

int N[100];
int L[100];
int fee[100][1000];
int sum[1000];
double min[100];

int main()
{
    int C;

    scanf("%d ", &C); // TEST CASE 입력

    for (int i = 0; i < C; i++)
    {
        min[i] = DBL_MAX;

        scanf("%d %d", &N[i], &L[i]); // N, L 입력

        for (int j = 0; j < N[i]; j++)
        {
            scanf("%d", &fee[i][j]); // fee 입력
        }

        // interval sum 계산
        for (int j = 0; j < N[i]; j++)
        {
            sum[j] = fee[i][j];

            for (int k = j + 1; k < N[i]; k++)
            {
                sum[k] = sum[k - 1] + fee[i][k];
            }

            for (int k = j + L[i] - 1; k < N[i]; k++)
            {
                if (min[i] > ((double)sum[k]) / (k - j + 1))
                {
                    min[i] = ((double)sum[k]) / (k - j + 1);
                }
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < C; i++)
    {
        printf("%lf\n", min[i]);
    }
     
    
    return 0;
}