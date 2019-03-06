#include <stdio.h>
#include <stdint.h>

void rdrand(uint64_t *rand)
{
    asm volatile (
        "rdrand %0"
        : "=A" (*rand)
    );
}

int main(void)
{
    uint64_t rand;
    char lts[4][10] = {"palloc", "uplus", "shunk031", "hayao"};

    rdrand(&rand);
    printf("%s\n", lts[rand & 0b11]);

    return 0;
}

