#include <stdio.h>
#include<stdlib.h>
int
gcd (int v1, int v2)
{
  int l = v1 < v2 ? v1 : v2;
  int h = v1 + v2 - l;
  while (h > l)
    {
      h -= l;
      if (h < l)
	{
	  int tmp = l;
	  l = h;
	  h = tmp;
	}
    }
  return h;
}

int
main (int argc, char *argv[])
{
  int v1 = atol (argv[1]);
  int v2 = atol (argv[2]);
  printf ("gcd(%d, %d) = %d\n", v1, v2, gcd (v1, v2));
  return 0;
}

