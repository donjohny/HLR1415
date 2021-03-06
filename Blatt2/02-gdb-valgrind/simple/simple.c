/*
** simple err-demonstration to demonstrate power of valgrind
** Julian M. Kunkel - 17.04.2008
*/

#include <stdio.h>
#include <stdlib.h>

int *
mistake1 ()
{
  static int buf[] = { 1, 1, 2, 3, 4, 5 };
  return buf;
}

int *
mistake2 ()
{
  int *buf = malloc (sizeof (int) * 4);
  buf[1] = 2;
  return buf;
}

int *
mistake3 ()
{
  int *buf = (int *) malloc (sizeof (int));
  *buf = 3;
  return buf;
}

int *
mistake4 ()
{
  int *buf = malloc (sizeof (char) * 4);
  buf[0] = 4;
//  free (buf);
  return buf;
}

int
main (void)
{
  /* Modifizieren Sie die folgenden Zeilen nicht */
  int *p[4] = { &mistake1 ()[1], &mistake2 ()[1], mistake3 (), mistake4 () };

  printf ("1 %d\n", *p[0]);
  printf ("2 %d\n", *p[1]);
  printf ("3 %d\n", *p[2]);
  printf ("4 %d\n", *p[3]);

  /* mhh muss hier noch etwas gefreed werden? */
  /* Fügen sie hier die korrekten aufrufe von free() ein */
  free (p[1] - 1);			/* welcher Pointer war das doch gleich?, TODO: Der Pointer auf das zweite Feld von buf :-) */
  free (p[2]);
  free (p[3]);

  return 0;
}
