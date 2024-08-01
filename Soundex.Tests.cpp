#include <gtest/gtest.h>
#include "Soundex.h"

// Array of input-output pairs for testing the Soundex algorithm
const char* inputs[] = {
    "Robert", "R163",
    "R", "R000",
    "Ax", "A200",
    "Bfpv", "B111",
    "Cgjkqsxz", "C222",
    "Dt", "D300",
    "L", "L000",
    "Mn", "M500",
    "R", "R000",
    "Aeiouyhwrb", "A161",
    "Bb", "B000",
    "Cc", "C000",
    "Dd", "D000",
    "Ashcraft", "A261",
    "Tymczak", "T522",
    "Pfister", "P236",
    "robert", "R163",
    "ROBERT", "R163",
    "Tait", "T300",
    "", "0000",
    NULL, "0000"
};

// Utility function to get the number of test cases
int getNumberOfTestCases() {
    return sizeof(inputs) / (2 * sizeof(inputs[0]));
}

// Utility function to get expected Soundex code for given input
const char* getExpectedSoundex(int index) {
    return inputs[2 * index + 1];
}

// Utility function to get input string for given index
const char* getInputString(int index) {
    return inputs[2 * index];
}

// Function to generate and validate Soundex code
void validateSoundexCode(const char* input, const char* expected) {
    char soundex[5];
    generateSoundex(input, soundex);
    ASSERT_STREQ(soundex, expected);
}

// Function to run all Soundex tests
void runSoundexTests() {
    int numCases = getNumberOfTestCases();
    for (int i = 0; i < numCases; ++i) {
        const char* input = getInputString(i);
        const char* expected = getExpectedSoundex(i);
        validateSoundexCode(input, expected);
    }
}

// Google Test Suite for Soundex
TEST(SoundexTestSuite, GenericSoundexTests) {
    runSoundexTests();
}
