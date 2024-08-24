// Safe C Library
// 
// Copyright (C) 2012, 2013 Cisco Systems
// Copyright (C) 2017 Reini Urban
// All rights reserved.
// 
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#include <string.h>
size_t strerrorlen_s(errno_t errnum)
{
#ifndef ESNULLP
#define ESNULLP         ( 400 )       /* null ptr                    */
#endif

#ifndef ESLEWRNG
#define ESLEWRNG        ( 410 )       /* wrong size                */
#endif

#ifndef ESLAST
#define ESLAST ESLEWRNG
#endif

    static const int len_errmsgs_s[] = {
      sizeof "null ptr",               /* ESNULLP */
      sizeof "length is zero",         /* ESZEROL */
      sizeof "length is below min",    /* ESLEMIN */
      sizeof "length exceeds RSIZE_MAX",/* ESLEMAX */
      sizeof "overlap undefined",      /* ESOVRLP */
      sizeof "empty string",           /* ESEMPTY */
      sizeof "not enough space",       /* ESNOSPC */
      sizeof "unterminated string",    /* ESUNTERM */
      sizeof "no difference",          /* ESNODIFF */
      sizeof "not found",              /* ESNOTFND */
      sizeof "wrong size",             /* ESLEWRNG */
    };

    if (errnum >= ESNULLP && errnum <= ESLAST)
    {
        return len_errmsgs_s[errnum - ESNULLP] - 1;
    }
    else
    {
        const char* buf = strerror_s(errnum);
        return buf ? strlen(buf) : 0;
    }
}