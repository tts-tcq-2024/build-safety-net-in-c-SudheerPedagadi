#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Function to get the soundex code for a given character
char getSoundexCode(char c) {
    static const char soundexCodes[] = {
        /* A */ '0', /* B */ '1', /* C */ '2', /* D */ '3',
        /* E */ '0', /* F */ '1', /* G */ '2', /* H */ '0',
        /* I */ '0', /* J */ '2', /* K */ '2', /* L */ '4',
        /* M */ '5', /* N */ '5', /* O */ '0', /* P */ '1',
        /* Q */ '2', /* R */ '6', /* S */ '2', /* T */ '3',
        /* U */ '0', /* V */ '1', /* W */ '0', /* X */ '2',
        /* Y */ '0', /* Z */ '2'
    };

    c = toupper(c);
    return (c >= 'A' && c <= 'Z') ? soundexCodes[c - 'A'] : '0';
}

// Function to initialize the soundex array
void initializeSoundex(char *soundex, const char *name) {
    if (name == NULL || strlen(name) == 0) {
        strcpy(soundex, "0000");
        return;
    }
    soundex[0] = toupper(name[0]);
    soundex[1] = soundex[2] = soundex[3] = '0';
    soundex[4] = '\0';
}

// Function to set the next soundex code in the array
void setSoundexCode(char *soundex, char code, int *index) {
    if (code != '0' && (*index == 1 || code != soundex[*index - 1]) && *index < 4) {
        soundex[(*index)++] = code;
    }
}

// Function to process each character and update soundex
void processCharacter(char c, char *soundex, int *index) {
    char code = getSoundexCode(c);
    setSoundexCode(soundex, code, index);
}

// Function to generate the soundex code for a given name
void generateSoundex(const char *name, char *soundex) {
    initializeSoundex(soundex, name);
    if (name == NULL || strlen(name) == 0) return;

    int sIndex = 1;
    for (int i = 1; name[i] != '\0'; ++i) {
        processCharacter(name[i], soundex, &sIndex);
    }
    soundex[4] = '\0'; // Ensure the soundex string is null-terminated
}

#endif // SOUNDEX_H
