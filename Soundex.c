#include "Soundex.h"
#include <ctype.h>
#include <string.h>
#include "SoundexHelper.h"

// Main function to generate the Soundex code
void generateSoundex(const char *name, char *soundex) {
    if (!name || strlen(name) == 0) {
        strcpy(soundex, "0000");
        return;
    }

    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; name[i] != '\0'; ++i) {
        appendSoundexCode(soundex, getSoundexCode(name[i]), &sIndex);
    }
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
    soundex[4] = '\0';
}

