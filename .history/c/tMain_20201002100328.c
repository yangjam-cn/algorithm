#include <stdio.h>
#include <stdlib.h>


static void before(void) __attribute__ ((constructor));
static void after(void) __attribute__ ((destructor));