#include "AD.h"

/* Creates a two dimensional char array which represents the 
 * tiles of a 'screen' or could also be called a fram, buffer 
 * whaterver you wanna call it.                            */
ad_frm_t * ad_create(int x, int y, char fill)
{
    int ix, iy;
    /* Allocate memory for the structure */
    ad_frm_t *tmp = (ad_frm_t *) malloc(sizeof(ad_frm_t));
    tmp->size_x = x;
    tmp->size_y = y;
    tmp->fill = fill;
    /* Allocate 1 byte for all the tiles */
    (tmp->frame) = (char **) malloc(y*x);
    for (iy = 0; iy < y; iy++)
    {
        /* Allocate 1 byte for all the columns */
        (tmp->frame)[iy] = malloc(x);
        for (ix = 0; ix < x; ix++)
        {
            /* Initialize with given value */
            (tmp->frame)[iy][ix] = fill;
        }
    }
    return(tmp);
}

/* Prints a given frame to the terminal, useful to 
 * update the image created at a certain time   */
void ad_print(ad_frm_t *frame)
{
    int ix, iy;
    for (iy = 0; iy < frame->size_y; iy++)
    {
        for (ix = 0; ix < frame->size_x; ix++)
        {
            printf("%c",frame->frame[iy][ix]);
        }
        printf("\n");
    }
}

/* Frees the memory allocated for a given frame, 
 * must be called every time a frame won't be 
 * used anymore to avoid wasting memory       */
void ad_free(ad_frm_t *tmp)
{
    int iy;
    for (iy = 0; iy < tmp->size_y; iy++)
    {
        tmp->frame[iy] = NULL;
        free(tmp->frame[iy]);
    }
    free(tmp);
    tmp = NULL;
}

/* Changes a tile from the frame, think of it as changing 
 * a pixel in a drawing or painting a dot in the given 
 * coordinates                                         */
void ad_tile(ad_frm_t *frm, int x, int y)
{
    if (!(x >= 0 && x < frm->size_x) || !(y >= 0 && y < frm->size_y))
        return;

    frm->frame[y][x] = frm->fill;
}

/* Draws a rectangle of the current tile tipe, to the given 
 * coordinates
 * upc_x : uper left corner x
 * upc_y : uper left corner y 
 * w : width of the rect
 * h : height of the rect                                */
void ad_rect(ad_frm_t *frm, int upc_x, int upc_y, int w, int h)
{
    int ix, iy;
    if (!(upc_x >= 0 && upc_x+w < frm->size_x) && !(upc_y >= 0 && upc_y+h < frm->size_y))
        return;

    for (iy = upc_y; iy < upc_y+h; iy++)
    {
        for (ix = upc_x; ix < upc_x+w; ix++)
        {
            frm->frame[iy][ix] = frm->fill;
        }
    }
}

/* Changed the current fill character for the given frame 
 * this fill is used for any drawing function          */
void ad_fill(ad_frm_t *frm, char fill)
{
    frm->fill = fill;
}
