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
    uint64_t rand, num;
    char members[9][15] = {"khwarizmi", "haruki", "ichiiiix", "Li_Rei", "morita", "noderu", "jyozi", "tatsuya", "yoshiooyama"};

top:
    rdrand(&rand);
		num = rand & 0b1111;
		if (num > 8)
			goto top;

    printf("%s\n", members[num]);
//		printf("%d\n", rand & 8);
    return 0;
}

