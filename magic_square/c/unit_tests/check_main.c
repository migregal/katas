#include "../inc/check_main.h"

double horizontal_sum(double values[N * N], int j)
{
    double sum = 0;

    for (int i = 0; i < N; i++)
        sum += values[i + j * N];

    return sum;
}

double vertical_sum(double values[N * N], int i)
{
    double sum = 0;

    for (int j = 0; j < N; j++)
        sum += values[i + j * N];

    return sum;
}

double primary_diagonal_sum(double values[N*N])
{
    double sum = 0;

    for (int i = 0; i < N; i++)
        sum += values[i + i * N];

    return sum;
}

double secondary_diagonal_sum(double values[N*N])
{
    double sum = 0;

    for (int i = 0; i < N; i++)
        sum += values[N - 1 - i + i * N];

    return sum;
}

void is_magic(double values[N * N])
{
    ck_assert_double_eq(horizontal_sum(values, 0), horizontal_sum(values, 1));
    ck_assert_double_eq(horizontal_sum(values, 0), horizontal_sum(values, 2));
    ck_assert_double_eq(horizontal_sum(values, 0), vertical_sum(values, 0));
    ck_assert_double_eq(horizontal_sum(values, 0), vertical_sum(values, 1));
    ck_assert_double_eq(horizontal_sum(values, 0), vertical_sum(values, 2));
    ck_assert_double_eq(horizontal_sum(values, 0), primary_diagonal_sum(values));
    ck_assert_double_eq(horizontal_sum(values, 0), secondary_diagonal_sum(values));

}

START_TEST(zeros)
{
    double values[N * N] = { 0 };
    ck_assert_int_eq(make_magic_square(values), 0);
}
END_TEST

START_TEST(pass_null)
{
    ck_assert_int_ne(make_magic_square(NULL), 0);
}
END_TEST

START_TEST(base_square)
{
    double values[N * N] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    ck_assert_int_eq(make_magic_square(values), 0);
    is_magic(values);
}
END_TEST

START_TEST(one_hundred_random_magic_squares)
{
    srand48(202101051154LL);

    double values[N * N] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < N * N; j++)
            values[j] = floor((double) rand() / RAND_MAX * 10);

        if (!make_magic_square(values))
            is_magic(values);
    }
}
END_TEST

Suite *magic_suit(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("magic");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, pass_null);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, zeros);
    tcase_add_test(tc_pos, base_square);
    tcase_add_test(tc_pos, one_hundred_random_magic_squares);
    suite_add_tcase(s, tc_pos);

    return s;
}

int main()
{
    int no_failed = 0;
    SRunner *runner;

    runner = srunner_create(magic_suit());

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
