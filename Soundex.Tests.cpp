#include <gtest/gtest.h>
#include "Soundex.h"

// Array of input-output pairs for testing the Soundex algorithm
const char* inputs[] = {
    "Robert", "R163",       // Standard name with expected encoding
    "R", "R000",            // Single character name, should pad with zeros
    "Ax", "A200",           // Name with a vowel followed by a consonant
    "Bfpv", "B111",         // Name with consonants mapping to the same digit
    "Cgjkqsxz", "C222",     // Name with different consonants mapping to the same digit
    "Dt", "D300",           // Name with consonants mapping to '3'
    "L", "L000",            // Single consonant name, should pad with zeros
    "Mn", "M500",           // Name with consonants mapping to '5'
    "R", "R000",            // Repeated test case for consistency
    "Aeiouyhwrb", "A161",   // Name with vowels and specific letters ignored
    "Bb", "B000",           // Name with repeated consonants
    "Cc", "C000",           // Another name with repeated consonants
    "Dd", "D000",           // Another repeated consonant name
    "Ashcraft", "A261",     // Name with 'h' and 'w' in between consonants
    "Tymczak", "T522",      // Complex name with different consonants and 'h' or 'w'
    "Pfister", "P236",      // Name with more than three encoded digits
    "robert", "R163",       // Lowercase name, should be case insensitive
    "ROBERT", "R163",       // Uppercase name for case insensitivity test
    "Tait", "T300",         // Name with same letters separated by a vowel
    "", "0000",             // Empty string, should return "0000"
    NULL, "0000"            // NULL input, should handle gracefully and return "0000"
};

// Test function for running Soundex tests
void runSoundexTests() 
{ 
  // Calculate the number of test cases based on the size of the inputs array
  int numCases = sizeof(inputs) / (2 * sizeof(inputs[0]));
  // Iterate through each test case
  for (int i = 0; i < numCases; ++i) 
  {
    // Get the input and expected output for the current test case
    const char* input = inputs[2 * i];
    const char* expected = inputs[2 * i + 1];
    // Buffer to hold the generated Soundex code
    char soundex[5];
    // Generate the Soundex code for the given input
    generateSoundex(input, soundex);
    // Assert that the generated Soundex code matches the expected output
    ASSERT_STREQ(soundex, expected);
  }
}

TEST(SoundexTestSuite, GenericSoundexTests)
{
  runSoundexTests();
}

