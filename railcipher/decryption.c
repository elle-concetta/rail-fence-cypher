/* COP 4338: Programming Assignment 2
   Name: Elizabeth Fassler */

#include "railcipher.h"
#include <string.h>
#include <stdlib.h>

#define error(code,message) do{fprintf(stderr, "%s\n", message);return code;}while(0)

char* decrypt(char* ciphertext, int m, int key[]) {
    int length = strlen(ciphertext);

    int n = length/m;

    // 2D array with ciphertext
    char matrix[n][m];

    int cipherCount = 0;
    for (int i = 1; i <= m; i++) {
        // Search key for index
        for (int index = 0; index < m; index++) {
            if (i == key[index]) {
                // Add column values to destination string
                for (int row = 0; row < n; row++) {
                    matrix[row][index] = ciphertext[cipherCount];
                    cipherCount++;
                }
            }
        }
    }
    char *decryptedText = (char *)malloc(100 * sizeof(char));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            strncat(decryptedText, &matrix[i][j], 1);
        }
    }

    return decryptedText;

}