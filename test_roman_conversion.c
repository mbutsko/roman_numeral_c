/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "test_roman_conversion.ts" instead.
 */

#include <check.h>

#line 1 "test_roman_conversion.ts"
#include <stdio.h>
#include "roman.h"

START_TEST(converts_zero_to_empty_string)
{
#line 5
        ck_assert_str_eq(toRoman(0), "");

}
END_TEST

START_TEST(converts_one_to_I)
{
#line 8
        ck_assert_str_eq(toRoman(1), "I");

}
END_TEST

START_TEST(negative_number_converts_to_empty_string)
{
#line 11
        ck_assert_str_eq(toRoman(-1), "");

}
END_TEST

START_TEST(converts_string_of_numerals_to_arabic)
{
#line 14
        ck_assert_str_eq(toRoman(3), "III");

}
END_TEST

START_TEST(converts_multiple_digit_numerals_to_arabic)
{
#line 17
        ck_assert_str_eq("IV", toRoman(4));

}
END_TEST

START_TEST(converts_five_to_V)
{
#line 20
        ck_assert_str_eq("V", toRoman(5));

}
END_TEST

START_TEST(converts_forty_four_to_XCIV)
{
#line 23
        ck_assert_str_eq("XLIV", toRoman(44));

}
END_TEST

START_TEST(converts_empty_to_zero)
{
#line 26
        ck_assert_int_eq(0, toArabic(""));

}
END_TEST

START_TEST(converts_I_to_one)
{
#line 29
        ck_assert_int_eq(1, toArabic("I"));

}
END_TEST

START_TEST(converts_two_of_same_numeral_in_a_row)
{
#line 32
        ck_assert_int_eq(2, toArabic("II"));

}
END_TEST

START_TEST(converts_single_term_roman_to_arabic)
{
#line 35
        ck_assert_int_eq(100, toArabic("C"));

}
END_TEST

START_TEST(converts_two_digit_single_term_roman_to_arabic)
{
#line 38
        ck_assert_int_eq(9, toArabic("IX"));

}
END_TEST

START_TEST(converts_multiple_two_digit_terms_roman_to_arabic)
{
#line 41
        ck_assert_int_eq(29, toArabic("XXIX"));

}
END_TEST

START_TEST(does_not_convert_invalid_numeral)
{
#line 44
        ck_assert_int_eq(5000, toArabic("XXIXX"));

}
END_TEST

START_TEST(does_not_convert_too_many_ones_to_numeral)
{
#line 47
        ck_assert_int_eq(5000, toArabic("IIII"));

}
END_TEST

START_TEST(does_not_convert_sequence_of_non_repeating_numerals)
{
#line 50
        ck_assert_int_eq(5000, toArabic("VV"));
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, converts_zero_to_empty_string);
    tcase_add_test(tc1_1, converts_one_to_I);
    tcase_add_test(tc1_1, negative_number_converts_to_empty_string);
    tcase_add_test(tc1_1, converts_string_of_numerals_to_arabic);
    tcase_add_test(tc1_1, converts_multiple_digit_numerals_to_arabic);
    tcase_add_test(tc1_1, converts_five_to_V);
    tcase_add_test(tc1_1, converts_forty_four_to_XCIV);
    tcase_add_test(tc1_1, converts_empty_to_zero);
    tcase_add_test(tc1_1, converts_I_to_one);
    tcase_add_test(tc1_1, converts_two_of_same_numeral_in_a_row);
    tcase_add_test(tc1_1, converts_single_term_roman_to_arabic);
    tcase_add_test(tc1_1, converts_two_digit_single_term_roman_to_arabic);
    tcase_add_test(tc1_1, converts_multiple_two_digit_terms_roman_to_arabic);
    tcase_add_test(tc1_1, does_not_convert_invalid_numeral);
    tcase_add_test(tc1_1, does_not_convert_too_many_ones_to_numeral);
    tcase_add_test(tc1_1, does_not_convert_sequence_of_non_repeating_numerals);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
