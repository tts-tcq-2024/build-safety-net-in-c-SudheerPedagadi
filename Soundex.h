#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

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

void initializeSoundex(char *soundex, const char *name) {
    if (!name || strlen(name) == 0) {
        strcpy(soundex, "0000");
        return;
    }
    soundex[0] = toupper(name[0]);
    soundex[1] = soundex[2] = soundex[3] = '0';
    soundex[4] = '\0';
}

void appendSoundexCode(char *soundex, char code, int *index) {
    if (*index < 4 && code != '0' && code != soundex[*index - 1]) {
        soundex[(*index)++] = code;
    }
}

void generateSoundex(const char *name, char *soundex) {
    initializeSoundex(soundex, name);
    if (!name || strlen(name) == 0) return;

    int sIndex = 1;
    for (int i = 1; name[i] != '\0'; ++i) {
        appendSoundexCode(soundex, getSoundexCode(name[i]), &sIndex);
    }
}

#endif // SOUNDEX_H
