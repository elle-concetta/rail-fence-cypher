#include "railcipher.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define error(code,message) do{fprintf(stderr, "%s\n", message);return code;}while(0)

// Checks if string is a positive integer
int check_integer(char* str) {
    if(strlen(str) == 0)
        return 0;
    if(str[0] == '-' || str[0] == '+')
        str++;
    while(*str) {
        if(!isdigit(*(str++)))
            return 0;
    }
    return 1;
}

int isPermutation(const int arr[], int n) {
    // Check elements in the array
    for(int i=1; i<=n; i++) {
        int found = 0;
        for(int j=0; j<n; j++) {
            if(arr[j] == i) {
                found = 1;
                break;
            }
        }
        if(!found) {
            return 0;
        }
    }
    return 1;
}
// Main function
int main(int argc, char* argv[]) {
    if(argc < 3) {
        fprintf(stderr, "railcipher: Fatal error! Insufficient arguments.\n");
        return 1;
    }
    // Check if first argument is positive
    if(!check_integer(argv[1]))
    {
        error(2, "railcipher: Fatal error! First CLA must be a valid integer.");
    } else if (atoi(argv[1]) > 26) {
        error(3, "railcipher: Fatal error! The encryption key length cannot exceed 26.\n");
    }
    // Allocate memory for the integer array
    int *key = (int *)malloc(100 * sizeof(int));

    if (key == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    int m = atoi(argv[1]);

    // Convert CLA to integers and store in the array
    for (int i = 2; i < argc; i++) {
        key[i - 2] = atoi(argv[i]);
    }

    if(!isPermutation(key, m))
    {
        error(4, "railcipher: Fatal error! The encryption key passed as CLAs is not valid.");
    }

    int bufferSize = 100;
    char *userInput = (char *)malloc(bufferSize * sizeof(char));

    if (userInput == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    while(1) {

        printf("Enter 'encrypt', 'decrypt' or 'quit': ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break; // Exit loop and end the program
        }
        else if (strcmp(command, "encrypt") == 0) {
            printf("Enter a string: ");

            // Read a line of input from user
            fflush (stdin);
            fgets(userInput, bufferSize, stdin);

            size_t len = strlen(userInput);
            if (len > 0 && userInput[len - 1] == '\n') {
                userInput[len - 1] = '\0';
            }

            printf("You entered: %s\n", userInput);

            char* s = encrypt(userInput, m, key);
            printf("Encrypted string:");
            printf("%s\n", s);
        }

        else if (strcmp(command, "decrypt") == 0) {
            printf("Enter a string: ");
            fflush (stdin);
            fgets(userInput, bufferSize, stdin);

            size_t len = strlen(userInput);
            if (len > 0 && userInput[len - 1] == '\n') {
                userInput[len - 1] = '\0';
            }

            printf("You entered: %s\n", userInput);

            char* d = decrypt(userInput, m, key);
            printf("Decrypted string:");
            printf("%s\n", d);
        }
        else {
            break;
        }

    }
    return 0;
}
