#include "railcipher.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define error(code,message) do{fprintf(stderr, "%s\n", message);return code;}while(0)

char* encrypt(char* plaintext, int m, const int key[]) {
    char *ciphertext = (char *)malloc(100 * sizeof(char));
    int length;
    int n;

    length = strlen(plaintext);
    char cleanStr[length]; // Parsed plaintext storage

    // Store letters in new string and convert to lower case
    int temp = 0;
    for (int i = 0; i < length; i++) {

        if (isalpha(plaintext[i]) != 0) {
            char c = tolower(plaintext[i]);
            cleanStr[temp] = c;
            temp++;
        }
    }

    length = strlen(cleanStr);
    n = ceil((length * 1.0) / m);

    char matrix[n][m];

    temp = 0;
    int numCharToFill = (n * m) - length;
    char beginningChar = 122 - numCharToFill;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp < length-1) {
                matrix[i][j] = cleanStr[temp];
                temp++;
            }
            else {
                if (beginningChar <= 123) {
                    matrix[i][j] = beginningChar;
                    beginningChar++;
                }
                else {
                    continue;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int index = 0; index < m; index++) {
            if (i == key[index]) {
                // Add column values to string
                for (int row = 0; row < n; row++) {
                    strncat(ciphertext, &matrix[row][index], 1);
                }
            }
        }
    }
    return ciphertext;
}
