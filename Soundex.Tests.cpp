#include <gtest/gtest.h>
#include "Soundex.h"

// Array of input-output pairs for testing the Soundex algorithm
const char* inputs[] = {
    // Typical cases
    "Robert", "R163",
    "R", "R000",
    "Ax", "A200",
    "Bfpv", "B111",
    "Cgjkqsxz", "C222",
    "Dt", "D300",
    "L", "L000",
    "Mn", "M500",
    "Ashcraft", "A261",
    "Tymczak", "T522",
    "Pfister", "P236",
    "Tait", "T300",
    "Bb", "B000",
    "Cc", "C000",
    "Dd", "D000",
    "", "0000",            // Empty string
    "Aeiouyhwrb", "A161", // Vowels and specific letters ignored
    "ROBERT", "R163",     // Uppercase name
    "robert", "R163",     // Lowercase name
    NULL, "0000",         // NULL input
    "J3x", "J020",        // Includes numbers (non-alphabetic characters)
    "M-P", "M510",        // Includes special characters
    "@B", "B000",         // Includes special characters
    "J", "J000",          // Single character
    "Johny", "J050",      // Short name with varying letters
    "Elizabeth", "E431",  // Longer name
    "O'Reilly", "O640",   // Name with special characters
    "Smyth", "S530",      // Name with common sound-alike letters
    "Schmidt", "S532"     // Name with different consonants and vowels
};

// Test function for running Soundex tests
void runSoundexTests() {
    int numCases = sizeof(inputs) / (2 * sizeof(inputs[0]));
    for (int i = 0; i < numCases; ++i) {
        const char* input = inputs[2 * i];
        const char* expected = inputs[2 * i + 1];
        char soundex[5];
        generateSoundex(input, soundex);
        ASSERT_STREQ(soundex, expected);
    }
}

TEST(SoundexTestSuite, GenericSoundexTests) {
    runSoundexTests();
}
