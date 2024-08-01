#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Mapping of characters to Soundex codes
static const char soundexCodes[] = 
{
    /* A */ '0', /* B */ '1', /* C */ '2', /* D */ '3',
    /* E */ '0', /* F */ '1', /* G */ '2', /* H */ '0',
    /* I */ '0', /* J */ '2', /* K */ '2', /* L */ '4',
    /* M */ '5', /* N */ '5', /* O */ '0', /* P */ '1',
    /* Q */ '2', /* R */ '6', /* S */ '2', /* T */ '3',
    /* U */ '0', /* V */ '1', /* W */ '0', /* X */ '2',
    /* Y */ '0', /* Z */ '2'
};

char getSoundexCode(char c)
{
    c = toupper(c);
    // Check if the character is within the range of letters
    if (c >= 'A' && c <= 'Z') 
    {
        return soundexCodes[c - 'A'];
    }
    return '0'; // Default case for non-alphabetic characters
}

void generateSoundex(const char *name, char *soundex) 
{
    if (!name || !soundex || strlen(name) == 0)
    {
        strcpy(soundex, "0000");
        return;
    }
    
    soundex[0] = toupper(name[0]);
    char previousCode = getSoundexCode(name[0]);
    int sIndex = 1;
    
    for (int i = 1; name[i] != '\0' && sIndex < 4; ++i)
    {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != previousCode)
        {
            soundex[sIndex++] = code;
        }
        previousCode = code;
    }
    
    // Pad with '0' until the length is 4
    while (sIndex < 4) 
    {
        soundex[sIndex++] = '0';
    }
    
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
