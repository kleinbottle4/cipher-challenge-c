/*
 *  affine.h's principle component is the Affine shifter
 *
 *  Copyright (C) 2019 syed343
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "affine.h"

#define ALPHABET_LEN 26
#define KW_LEN ALPHABET_LEN + 1

int main(int argc, const char **argv)
{
	int msg_len;
	if (argc >= 2)
		msg_len = atoi(argv[1]);
	else
		msg_len = 500;
	
	char msg[msg_len + 1], kw[KW_LEN];
	int a, b;
	
	printf("# Messages are a maximum of %d characters long.\n", msg_len);
	puts("# Keywords are a maximum of 26 characters long.");
	puts("# Strings longer than their maximum length are truncated.");
    putchar('\n');

	while (true) {
		printf("# Message:\n");
		fgets(msg, msg_len, stdin);	

		printf("# Keyword:\n");
		fgets(kw, KW_LEN, stdin);

		printf("# a: ");
		scanf("%d", &a);
		printf("# b: ");
		scanf("%d", &b);

		affine_str(msg, a, b, ALPHABET, true);
		puts(msg);
		
		getchar();
	}
	
    return 0;
}
