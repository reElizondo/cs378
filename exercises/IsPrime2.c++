// ------------
// IsPrime2.c++
// ------------

// https://en.wikipedia.org/wiki/Primality_test

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

#include "IsPrime2.h"

TEST (IsPrimeFixture, test_1) {
    ASSERT_FALSE(is_prime( 1));}

TEST (IsPrimeFixture, test_2) {
    ASSERT_TRUE(is_prime( 2));}

TEST (IsPrimeFixture, test_3) {
    ASSERT_TRUE(is_prime( 3));}

TEST (IsPrimeFixture, test_4) {
    ASSERT_FALSE(is_prime( 4));}

TEST (IsPrimeFixture, test_5) {
    ASSERT_TRUE(is_prime( 5));}

TEST (IsPrimeFixture, test_7) {
    ASSERT_TRUE(is_prime( 7));}

TEST (IsPrimeFixture, test_9) {
    ASSERT_FALSE(is_prime( 9));}

TEST (IsPrimeFixture, test_27) {
    ASSERT_FALSE(is_prime(27));}

TEST (IsPrimeFixture, test_29) {
    ASSERT_TRUE(is_prime(29));}
