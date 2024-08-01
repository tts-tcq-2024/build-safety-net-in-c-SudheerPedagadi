#include <gtest/gtest.h>
#include "Soundex.h"

//Append 3 zeros if result contains less than 3 digits
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_1) {
//AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_STREQ(soundex,"A200");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_2) {
//AAA
  char soundex[5];
  generateSoundex("A1CDFe", soundex);
  ASSERT_STREQ(soundex,"A231");
}

//Test case to ckeck special character
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_3) {
//AAA
  char soundex[5];
  generateSoundex("A[", soundex);
  ASSERT_STREQ(soundex,"A000");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_4) {
 //AAA
  char soundex[5];
  generateSoundex("ACGJ", soundex);
 ASSERT_STREQ(soundex,"A200");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_5) {
 //AAA
  char soundex[5];
  generateSoundex("@@BBCCDD", soundex);
 ASSERT_STREQ(soundex,"@123");
}

//Replace all adjacent same digits with one digit
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_6) {
//AAA
  char soundex[5];
  generateSoundex("Abfp", soundex);
  ASSERT_STREQ(soundex,"A100");
}

//two letters with the same number separated by 'h', 'w' or 'y' are coded as a single number
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_7) {
//AAA
  char soundex[5];
  generateSoundex("BShZ", soundex);
  ASSERT_STREQ(soundex,"B200");
}
