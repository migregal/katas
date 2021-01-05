#include "../inc/main.h"

int main(void)
{
    double values[9] = {0};

    for (int i = 0; i < N * N; i++)
        scanf("%lf", values + i);

    if (make_magic_square(values))
    {
        printf("There is no magic\n");
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                printf("%lf\t", values[i * N + j]);
            printf("\n");
        }
    }

    return 0;
}
