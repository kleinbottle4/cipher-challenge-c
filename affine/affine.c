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
#include "affine.h"

int main(int argc, const char **argv)
{
    int msg_len, kw_len;
    int a, b;
    
    printf("Message length: ");
    scanf("%d", &msg_len);
    char msg[msg_len];
    printf("Message: ");
    fgets(msg, msg_len, stdin);

    printf("Keyword length: ");
    scanf("%d", &kw_len);
    char kw[kw_len];
    printf("Keyword: ");
    fgets(kw, kw_len, stdin);

    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    affine_str(msg, a, b, ALPHABET, true);
    puts(msg);

    return 0;
}
