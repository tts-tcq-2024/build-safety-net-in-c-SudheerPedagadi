#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Mapping of characters to Soundex codes
char getSoundexCode(char c) {
    c = toupper(c);
    static const char soundexCodes[] = {
        /* A */ '0', /* B */ '1', /* C */ '2', /* D */ '3',
        /* E */ '0', /* F */ '1', /* G */ '2', /* H */ '0',
        /* I */ '0', /* J */ '2', /* K */ '2', /* L */ '4',
        /* M */ '5', /* N */ '5', /* O */ '0', /* P */ '1',
        /* Q */ '2', /* R */ '6', /* S */ '2', /* T */ '3',
        /* U */ '0', /* V */ '1', /* W */ '0', /* X */ '2',
        /* Y */ '0', /* Z */ '2'
    };
    return (c >= 'A' && c <= 'Z') ? soundexCodes[c - 'A'] : '0';
}

void initializeSoundex(char *soundex, const char *name) {
    if (!name || !soundex || strlen(name) == 0) {
        strcpy(soundex, "0000");
        return;
    }
    soundex[0] = toupper(name[0]);
    soundex[1] = soundex[2] = soundex[3] = '0';
    soundex[4] = '\0';
}

void appendSoundexCode(char *soundex, char code, int *index) {
    if (code != '0' && code != soundex[*index - 1] && *index < 4) {
        soundex[(*index)++] = code;
    }
}

void generateSoundex(const char *name, char *soundex) {
    initializeSoundex(soundex, name);
    if (!name || !soundex || strlen(name) == 0) return;

    int sIndex = 1;
    for (int i = 1; name[i] != '\0'; ++i) {
        char code = getSoundexCode(name[i]);
        appendSoundexCode(soundex, code, &sIndex);
    }
}

#endif // SOUNDEX_H
