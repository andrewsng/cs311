// squarer_test.cpp
//
// SKELETON BY
// Glenn G. Chappell
// 2020-11-20
//
// TEST CASES BY
// Andrew S. Ng
// 2020-12-01
//
// For CS 311 Fall 2020
// Test program for class Squarer
// For Project 8, Exercise B
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, squarer.h

// Includes for code to be tested
#include "squarer.h"         // For class Squarer
#include "squarer.h"         // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT
                             // We write our own main
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
                             // Reduce compile time
#include "doctest.h"         // For doctest

// Includes for all test programs
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;

// Additional includes for this test program
// NONE

// Printable name for this test suite
const std::string test_suite_name =
    "class Squarer"
    " - CS 311 Proj 8, Ex B";


// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE("Squarer: non-negative ints")
{
    Squarer sq;
    SUBCASE("0 squared")
    {
        int arg = 0;
        int result = 0;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
    SUBCASE("1 squared")
    {
        int arg = 1;
        int result = 1;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
    SUBCASE("7 squared")
    {
        int arg = 7;
        int result = 49;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
    SUBCASE("12 squared")
    {
        int arg = 12;
        int result = 144;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
}
TEST_CASE("Squarer: negative ints")
{
    Squarer sq;
    SUBCASE("-1 squared")
    {
        int arg = -1;
        int result = 1;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
    SUBCASE("-6 squared")
    {
        int arg = -6;
        int result = 36;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
    SUBCASE("-11 squared")
    {
        int arg = -11;
        int result = 121;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
}
TEST_CASE("Const Squarer: ints")
{
    const Squarer sq;
    SUBCASE("0 squared")
    {
        int arg = 0;
        int result = 0;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
    SUBCASE("-5 squared")
    {
        int arg = -5;
        int result = 25;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
    SUBCASE("10 squared")
    {
        int arg = 10;
        int result = 100;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
}
TEST_CASE("Squarer: non-negative doubles")
{
    Squarer sq;
    SUBCASE("0.0 squared")
    {
        double arg = 0.0;
        double result = 0.0;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == doctest::Approx(result));
    }
    SUBCASE("1.0 squared")
    {
        double arg = 1.0;
        double result = 1.0;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == doctest::Approx(result));
    }
    SUBCASE("1.5 squared")
    {
        double arg = 1.5;
        double result = 2.25;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == doctest::Approx(result));
    }
    SUBCASE("16.35 squared")
    {
        double arg = 16.35;
        double result = 267.3225;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == doctest::Approx(result));
    }
}
TEST_CASE("Squarer: negative doubles")
{
    Squarer sq;
    SUBCASE("-1.0 squared")
    {
        double arg = -1.0;
        double result = 1.0;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == doctest::Approx(result));
    }
    SUBCASE("-5.76 squared")
    {
        double arg = -5.76;
        double result = 33.1776;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == doctest::Approx(result));
    }
    SUBCASE("-10.33 squared")
    {
        double arg = -10.33;
        double result = 106.7089;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == doctest::Approx(result));
    }
}
TEST_CASE("Const Squarer: doubles")
{
    const Squarer sq;
    SUBCASE("0.0 squared")
    {
        double arg = 0.0;
        double result = 0.0;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == doctest::Approx(result));
    }
    SUBCASE("-3.11 squared")
    {
        double arg = -3.11;
        double result = 9.6721;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == doctest::Approx(result));
    }
    SUBCASE("8.25 squared")
    {
        double arg = 8.25;
        double result = 68.0625;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == doctest::Approx(result));
    }
}


// *********************************************************************
// Main Program
// *********************************************************************


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc,
         char *argv[])
{
    doctest::Context dtcontext;
                             // Primary doctest object
    int dtresult;            // doctest return code; for return by main

    // Handle command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0;            // doctest flags no command-line errors
                             //  (strange but true)

    if (!dtresult)           // Continue only if no command-line error
    {
        // Run test suites
        cout << "BEGIN tests for " << test_suite_name << "\n" << endl;
        dtresult = dtcontext.run();
        cout << "END tests for " << test_suite_name << "\n" << endl;
    }

    // If we want to do something else here, then we need to check
    // context.shouldExit() first.

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();

    // Program return value is return code from doctest
    return dtresult;
}

