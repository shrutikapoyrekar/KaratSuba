#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
#include "scaffold32.h"

/* You are suppose to change the routine Product32 here to your own routine 
 * The mpz calls in the scaffolded Product32 below are the normal GMP function
 * calls and should be neglected. By casting the void pointers as normal unsigned
 * integers, you should be able to access the data values as normal 4 bytes words.
 */

/* wa is word length of a, ba is bit length of a */
void Product32(void *a, void *b, void *c, unsigned int wa,
        unsigned int ba, unsigned int wb, unsigned int bb, unsigned int
        *wc, unsigned int *bc)
{

    mpz_t x,y,z;
    mpz_init(x);
    mpz_init(y);
    mpz_init(z); 

    /* Cast a and b into short integers of size 32 bits */
    unsigned int *int_a = (unsigned int *) a;
    unsigned int *int_b = (unsigned int *) b;

    /* Now int_a can be view as an array of words of size 32
     * bits */
    /* Similarly for int_b */
    //printf("%lu %lu \n", int_a[0], int_a[*sa - 1]);
    //printf("%lu %lu \n", int_b[0], int_b[*sb - 1]);

    mpz_import(x, wa, ORDER, WORDBYTES, ENDIAN, NAILS, a);
    mpz_import(y, wb, ORDER, WORDBYTES, ENDIAN, NAILS, b);
    mpz_mul(z,x,y);

    c = mpz_export(c, wc, ORDER, WORDBYTES, ENDIAN, NAILS, z);
}

