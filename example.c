#include "common/common.h"

int main(void)
{
	printf("%c\n", char_lc('Z'));
	char buff[] = "Hello, My Name Is Geoff.";
	puts(buff);
	str_lc(buff);
	puts(buff);
	return 0;
}
