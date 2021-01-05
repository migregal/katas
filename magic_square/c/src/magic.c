#include "../inc/magic.h"
#include <math.h>

#define EQ(_x_, _y_) \
    EPS > fabs(_x_ - _y_)

static double horizontal_sum(double values[N * N], int j)
{
    double sum = 0;

    for (int i = 0; i < N; i++)
        sum += values[i + j * N];

    return sum;
}

static double vertical_sum(double values[N * N], int i)
{
    double sum = 0;

    for (int j = 0; j < N; j++)
        sum += values[i + j * N];

    return sum;
}

static double primary_diagonal_sum(double values[N * N])
{
    double sum = 0;

    for (int i = 0; i < N; i++)
        sum += values[i + i * N];

    return sum;
}

static double secondary_diagonal_sum(double values[N * N])
{
    double sum = 0;

    for (int i = 0; i < N; i++)
        sum += values[N - 1 - i + i * N];

    return sum;
}

static int is_magic(double values[N * N])
{
    double res = horizontal_sum(values, 0);
    return !(EQ(res, horizontal_sum(values, 1)) &&
             EQ(res, horizontal_sum(values, 2)) &&
             EQ(res, vertical_sum(values, 0)) &&
             EQ(res, vertical_sum(values, 1)) &&
             EQ(res, vertical_sum(values, 2)) &&
             EQ(res, primary_diagonal_sum(values)) &&
             EQ(res, secondary_diagonal_sum(values)));
}

void swap(double *a, double *b)
{
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

static int permutation(double *arr, int start, int end)
{
    if (start == end)
        return is_magic(arr);

    for (size_t i = start; i <= end; i++)
    {
        swap((arr + i), (arr + start));

        if (!permutation(arr, start + 1, end))
            return 0;

        swap((arr + i), (arr + start));
    }

    return 1;
}

int make_magic_square(double values[N * N])
{
    return !values ? 1 : permutation(values, 0, N * N - 1);
}
