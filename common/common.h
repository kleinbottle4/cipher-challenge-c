/*  common.c's principle component is the character shifter
 *
 *  Copyright (C) 2019  syed343
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
#include <string.h>

#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define U_ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define PUNCTUATION ".,'?!-: ()\n"

int char_find(char c, const char *s)
{
	int i = 0;
	const char *p = s;
	while (*p != '\0') {
		if (c == *p) {
			return i;
		} else {
			p++;
			i++;
		}
	}
	return -1;
}	

char char_shift(char c, int i, const char *alph)
{
	if (char_find(c, PUNCTUATION) != -1) {
		return c;
	} else {
		int x = char_find(c, alph);
		if (x == -1) {
			return '\0';
		} else {
			x += i;
			x = x % strlen(alph);
			return alph[x];
		}
	}
}

char char_lc(char c)
{
	if (c < 'a') {
	/* c is upper case*/
		c = 'a' + (c - 'A');
	}
	return c;
}

void str_lc(char *s)
{
	char *c = s;
	while (*c != '\0') {
		if (char_find(*c, U_ALPHABET) != -1) {
			*c = char_lc(*c);
		}
		c++;
	}
	putchar('\n');
}
