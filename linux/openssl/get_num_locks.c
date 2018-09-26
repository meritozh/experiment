#include <openssl/crypto.h>
#include <stdio.h>

int main() {
  int nums = CRYPTO_num_locks();

  fprintf(stdout, "openssl crypto use %d locks.\n", nums);

  return 0;
}
