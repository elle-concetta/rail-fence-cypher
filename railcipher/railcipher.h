#ifndef RAILCIPHER_H
#define RAILCIPHER_H

char* decrypt(char* ciphertext, int m, int key[]);
char* encrypt(char* plaintext, int m, const int key[]);
int main(int argc, char* argv[]);
int check_integer(char* str);
int isPermutation(const int arr[], int n);

#endif // RAILCIPHER_H