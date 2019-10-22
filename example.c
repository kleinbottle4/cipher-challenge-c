#include "common/common.h"

int main(void)
{
	char x = shift_char('x', 5, "abcdefghijklmnopqrstuvwxyz", ".");
	printf("%c\n", x);
	return 0;
}
