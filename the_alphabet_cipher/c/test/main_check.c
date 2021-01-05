#define _GNU_SOURCE

#include <string.h>
#include <stdlib.h>

#include <check.h>

#include "alphabet.h"

START_TEST(test_encode_1)
{
    char *test = "hmkbxebpxpmyllyrxiiqtoltfgzzv";

    char msg[] = "meetmeontuesdayeveningatseven";

    char *result = encode("vigilance", msg);

    int res = strcmp(result, test);
    free(result);

    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_encode_2)
{
    char *test = "egsgqwtahuiljgs";

    char msg[] = "meetmebythetree";

    char *result = encode("scones", msg);

    int res = strcmp(result, test);
    free(result);

    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_decode_1)
{
    char *test = "meetmeontuesdayeveningatseven";

    char msg[] = "hmkbxebpxpmyllyrxiiqtoltfgzzv";

    char *result = decode("vigilance", msg);

    int res = strcmp(result, test);
    free(result);

    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_decode_2)
{
    char *test = "meetmebythetree";

    char msg[] = "egsgqwtahuiljgs";

    char *result = decode("scones", msg);

    int res = strcmp(result, test);
    free(result);

    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_dechiper_1)
{
    char *test = "vigilance";

    char msg[] = "opkyfipmfmwcvqoklyhxywgeecpvhelzg";

    char *result = dechiper("thequickbrownfoxjumpsoveralazydog", msg);

    int res = strcmp(result, test);
    free(result);

    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_dechiper_2)
{
    char *test = "scones";

    char msg[] = "hcqxqqtqljmlzhwiivgbsapaiwcenmyu";

    char *result = dechiper("packmyboxwithfivedozenliquorjugs", msg);

    int res = strcmp(result, test);
    free(result);

    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_dechiper_3)
{
    char *test = "abcabcx";

    char msg[] = "hfnlphoontutufa";

    char *result = dechiper("hellofromrussia", msg);

    int res = strcmp(result, test);
    free(result);

    ck_assert_int_eq(res, 0);
}
END_TEST

Suite *alphabet_suite(void)
{
    Suite *s;
    TCase *tc_encode;
    TCase *tc_decode;
    TCase *tc_dechiper;

    s = suite_create("list");

    tc_encode = tcase_create("encode");
    tcase_add_test(tc_encode, test_encode_1);
    tcase_add_test(tc_encode, test_encode_2);
    suite_add_tcase(s, tc_encode);

    tc_decode = tcase_create("decode");
    tcase_add_test(tc_encode, test_decode_1);
    tcase_add_test(tc_encode, test_decode_2);
    suite_add_tcase(s, tc_decode);

    tc_dechiper = tcase_create("dechiper");
    tcase_add_test(tc_dechiper, test_dechiper_1);
    tcase_add_test(tc_dechiper, test_dechiper_2);
    tcase_add_test(tc_dechiper, test_dechiper_3);
    suite_add_tcase(s, tc_dechiper);

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *suite;
    SRunner *runner;

    suite = alphabet_suite();

    runner = srunner_create(suite);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
