#include "affine/affine.h"

int main(void)
{
	char msg[] = "Hello, my name is Geoff.";
	affine_str(msg, 5, 13, ALPHABET, true);
	puts(msg);
	return 0;
}
