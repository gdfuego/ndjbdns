/*
* alloc_re.c: This file is part of the `djbdns' project, originally written
* by Dr. D J Bernstein and later released under public-domain since late
* December 2007 (http://cr.yp.to/distributors.html).
*
* Copyright (C) 2009 - 2012 Prasad J Pandit
*
* This program is a free software; you can redistribute it and/or modify
* it under the terms of GNU General Public License as published by Free
* Software Foundation; either version 2 of the license or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* of FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to Free Software Foundation, Inc., 51
* Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include "byte.h"
#include "alloc.h"

int
alloc_re(char **x, unsigned int m, unsigned int n)
{
      char *y = (char *)0;

      y = alloc(n);
      if (!y)
          return 0;

      byte_copy(y, m, *x);
      alloc_free(*x);
      *x = y;

      return 1;
}