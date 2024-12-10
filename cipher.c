#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/conf.h>

void handleErrors(void)
{
ERR_print_errors_fp(stderr);
abort();
}
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
unsigned char *iv, unsigned char *ciphertext)
{
EVP_CIPHER_CTX *ctx;
int len;
int ciphertext_len;
/* Context */
if(!(ctx = EVP_CIPHER_CTX_new()))
handleErrors();
/*
* Initialise the encryption operation.
*/
if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
handleErrors();
/*
* Provide the message to be encrypted, and obtain encrypted output.
*/
if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
handleErrors();
ciphertext_len = len;
/*
* Finalise the encryption.
*/
if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
handleErrors();
ciphertext_len += len;
/* Clean up */
EVP_CIPHER_CTX_free(ctx);
return ciphertext_len;
}
void padString(unsigned char* buffer) {
int size = 16;
int diff = 16 - strlen(buffer);
if(diff == 0)
return;
memset(buffer + strlen(buffer), '#', diff);
}
int main (void)
{
/* A 128 bit IV */
unsigned char iv[] = { 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00, 0x99, 0x88,
0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11 };
unsigned char correct_ciphertext[32] = { 0x76, 0x4a, 0xa2, 0x6b, 0x55, 0xa4,
0xda, 0x65, 0x4d, 0xf6, 0xb1, 0x9e, 0x4b, 0xce, 0x00, 0xf4, 0xed, 0x05, 0xe0, 0x93,
0x46, 0xfb, 0x0e, 0x76, 0x25, 0x83, 0xcb, 0x7d, 0xa2, 0xac, 0x93, 0xa2 };
/* Message to be encrypted */
unsigned char *plaintext =
(unsigned char *)"This is a top secret.";
/*
* Buffer for ciphertext. Ensure the buffer is long enough for the
* ciphertext which may be longer than the plaintext, depending on the
* algorithm and mode.
*/
unsigned char ciphertext[128];
int ciphertext_len;
/* Encrypt the plaintext */
const size_t BUF_SIZE = 16;
unsigned char buffer[BUF_SIZE];
FILE* in;
in = fopen("words.txt", "r");
while(fgets(buffer, BUF_SIZE, in)) {
buffer[strcspn(buffer, "\n")] = 0;
padString(buffer);
ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), buffer, iv,
ciphertext);
if(strcmp(ciphertext, correct_ciphertext) == 0) {
memset(ciphertext, 0, sizeof(ciphertext));
printf("Found Key: %s\n", buffer);
}
}
fclose(in);
return 0;
}
