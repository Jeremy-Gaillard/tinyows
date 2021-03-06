/*
  Copyright (c) <2007-2012> <Barbara Philippot - Olivier Courtin>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
  IN THE SOFTWARE.
*/


#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <assert.h>

#include "../ows/ows.h"


/*
 * Check if a string match a pattern
 */
bool check_regexp(const char *str_request, const char *str_regex)
{
  int err;
  int match;
  regex_t preg;

  assert(str_request);
  assert(str_regex);

  err = regcomp(&preg, str_regex, REG_NOSUB | REG_EXTENDED);

  if (err == 0) {

    match = regexec(&preg, str_request, 0, NULL, 0);
    regfree(&preg);

    if (match == 0) return true;
    else if (match == REG_NOMATCH) return false;
    else return false;
  }

  return false;
}


/*
 * vim: expandtab sw=4 ts=4
 */
