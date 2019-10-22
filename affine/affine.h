/*
 *  affine.c's principle component is the Affine shifter
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

#include "../common/common.h"
#include <stdbool.h>

char affine_char(char c, int a, int b)
{
    if (char_find(c, PUNCTUATION) != -1) {
        return c;
    } else {
        c = char_lc(c);
        int i = char_find(c, ALPHABET);
        if (i == -1) {
            return '\0';
        } else {
            i += 1;
            int s_i = ((a * i + b) % 26) - 1;
            if (s_i < 0)
	            s_i += 26;
	        return ALPHABET[s_i];
        }
    }
}

void affine_str(char *s, int a, int b, const char *alph, bool debug)
{
    str_lc(s);
    char *c = s;
    char n;
    while (*c != '\0') {
        if (char_find(*c, PUNCTUATION) == -1) {
            n = affine_char(*c, a, b);
            if (n != '\0') {
                *c = n;
            } else if (debug) {
                printf("# error: %c not in alphabet\n", *c);
		*c = '_';
            }
        }
	c++;
    }
}
