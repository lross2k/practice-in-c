#include <stdio.h>
#include "AD.h"

#define WIDTH 10
#define HEIGTH 3

int main(void)
{
    /* Testing out the custom library before actually 
     making the sierpinski gasket */
    ad_frm_t *frm = ad_create(WIDTH, HEIGTH, ' ');

    ad_print(frm);    
    printf("\n");

    ad_fill(frm, '>');
    ad_tile(frm, 4, 2);

    ad_print(frm);    
    printf("\n");

    ad_fill(frm, 'o');
    ad_rect(frm, 0, 0, 2, 2);

    ad_print(frm);    
    printf("\n");

    ad_free(frm);
    return(0);
}
