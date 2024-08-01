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
    if (c >= 'A' && c <= 'Z') {
        return soundexCodes[c - 'A'];
    }
    return '0'; // Non-alphabetic characters are ignored
}

// Function to initialize the soundex array
void initializeSoundex(char *soundex, const char *name) {
    if (name == NULL || strlen(name) == 0) {
        strcpy(soundex, "0000");
        return;
    }
    soundex[0] = toupper(name[0]);
    soundex[1] = soundex[2] = soundex[3] = '0';
}

// Function to append a character to the soundex array
void appendSoundex(char *soundex, char code, int *index) {
    if (*index < 4 && code != '0' && (code != soundex[*index - 1] || *index == 1)) {
        soundex[(*index)++] = code;
    }
}

// Function to process each character
void processCharacter(char c, char *soundex, int *index) {
    char code = getSoundexCode(c);
    appendSoundex(soundex, code, index);
}

// Function to finalize the soundex array
void finalizeSoundex(char *soundex) {
    soundex[4] = '\0'; // Ensure the soundex string is null-terminated
}

// Function to generate the soundex code for a given name
void generateSoundex(const char *name, char *soundex) {
    initializeSoundex(soundex, name);
    if (name == NULL || strlen(name) == 0) return;

    int sIndex = 1;
    for (int i = 1; name[i] != '\0'; ++i) {
        processCharacter(name[i], soundex, &sIndex);
    }
    finalizeSoundex(soundex); // Ensure the soundex string is properly null-terminated
}

#endif // SOUNDEX_H
