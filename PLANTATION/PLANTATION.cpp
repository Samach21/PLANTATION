#include<stdio.h> 
#include<math.h>

#define MAX_NSIZE (100000) 

int x[MAX_NSIZE], y[MAX_NSIZE];
int W_values, N_values[11], R_values[11], D_values[11], i, j;
float Dis, D_float, XY_float, R_float;
char status_[15];

int calculate();
int process();

int main()
{
    if (scanf_s("%d", &W_values) != 1) {
        printf("ERROR\n");
        return 1;
    }
    else if (W_values < 1 || W_values > 10) {
        printf("ERROR \n1 <= W <= 10\n");
        return 1;
    }

    for (i = 1; i <= W_values; i++) {
        if (scanf_s("%d", &N_values[i]) != 1) {
            printf("ERROR\n");
            return 1;
        }
        else if (N_values[i] < 2 || N_values[i] > MAX_NSIZE) {
            printf("ERROR \n1 <= N <= %d\n", MAX_NSIZE);
            return 1;
        }

        if (scanf_s("%d", &R_values[i]) != 1) {
            printf("ERROR\n");
            return 1;
        }
        else if (R_values[i] < 1 || R_values[i] > 1000) {
            printf("ERROR \n1 <= R <= 1000\n");
            return 1;
        }

        if (scanf_s("%d", &D_values[i]) != 1) {
            printf("ERROR\n");
            return 1;
        }
        else if (D_values[i] < 1 || D_values[i] > 1000) {
            printf("ERROR \n1 <= D <= 1000\n");
            return 1;
        }

        for (j = 1; j <= N_values[i]; j++) {
            if (scanf_s("%d", &x[j]) != 1) {
                printf("ERROR \n");
                return 1;
            }
            else if (x[j] < -10000000 || x[j] > 10000000) {
                printf("ERROR \n-10000000 <= x%d <= 10000000\n", j);
                return 1;
            }
            if (scanf_s("%d", &y[j]) != 1) {
                printf("ERROR \n");
                return 1;
            }
            else if (y[j] < -10000000 || y[j] > 10000000) {
                printf("ERROR \n-10000000 <= y%d <= 10000000\n", j);
                return 1;
            }
        }
        calculate();
    }

    process();

    return 0;
}

int process()
{
    for (int m = 1; m <= W_values; m++)
    {
        printf("\n%c", status_[m]);
    }
    return 0;
}

int calculate()
{
    for (long int k = 1; k <= N_values[i]; k++)
    {
        for (long int l = 1; l <= N_values[i] - 1; l++)
        {
            if (k != l)
            {
                D_float = D_values[i];
                R_float = R_values[i];
                XY_float = (x[k] - x[l]) * (x[k] - x[l]) + (y[k] - y[l]) * (y[k] - y[l]);
                Dis = sqrt(XY_float) - (2.0 * R_float);
                if (Dis < D_float)
                {
                    status_[i] = 'N';
                    k = N_values[i] + 1;
                    l = N_values[i];
                }
                else
                {
                    status_[i] = 'Y';
                }
            }
        }
    }
    return 0;
}