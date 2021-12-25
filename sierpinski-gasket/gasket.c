#include <stdio.h>

#include "AD.h"

#define MIN_SIZE 1

void draw_gasket(ad_frm_t *frm, int x, int y, int square_size);
void sierpinski_gasket(int frame_size);

int main(int argc, char **argv)
{
    int it;
    if (argc <= 1)
    {
        sierpinski_gasket(40);
        return(0);
    }

    for (it = 1; it < argc; it++)
        sierpinski_gasket(strtol(argv[it], NULL, 10));

    return(0);
}

void draw_gasket(ad_frm_t *frm, int x, int y, int square_size)
{
    int half_square = 0;
    if (square_size <= MIN_SIZE)
    {
        ad_rect(frm, x, y, square_size, square_size);
    }
    else
    {
        half_square = square_size/2;
        draw_gasket(frm, x, y, half_square);
        draw_gasket(frm, x+half_square, y, half_square);
        draw_gasket(frm, x+half_square, y+half_square, half_square);
    }
}

void sierpinski_gasket(int frame_size)
{
    /* Testing out the custom library before actually 
     making the sierpinski gasket */
    ad_frm_t *frm = ad_create(frame_size, frame_size, ' ');
    ad_fill(frm, 'x');
    draw_gasket(frm, 0, 0, frame_size);
    ad_print(frm);    
    printf("\n");
    ad_free(frm);
}
