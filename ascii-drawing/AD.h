#ifndef ASCII_DRAWING_H
#define ASCII_DRAWING_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ad_frm_t {
    char **frame;
    int size_x, size_y;
    char fill;
} ad_frm_t;

ad_frm_t * ad_create(int x, int y, char fill);
void ad_print(ad_frm_t *frame);
void ad_free(ad_frm_t *tmp);
void ad_tile(ad_frm_t *frm, int x, int y);
void ad_rect(ad_frm_t *frm, int upc_x, int upc_y, int w, int h);
void ad_fill(ad_frm_t *frm, char fill);

#endif /*ASCII_DRAWING_H*/
