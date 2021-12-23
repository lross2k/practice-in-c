#include <stdio.h>
#include <stdlib.h>

typedef struct totally_a_class vec3;

typedef struct totally_a_class {
    int x,y,z;
    void (*mul)(vec3*,int);
} vec3;

void mul(vec3* self, int fact)
{
    self->x *= fact; 
    self->y *= fact; 
    self->z *= fact; 
}

vec3* vec3_cons(int x, int y, int z)
{
    vec3 *temp = (vec3*) malloc(sizeof(vec3));
    if (!temp)
    {
        free(temp);
        printf("Uh, how can I explain this to you..?\n");
        return NULL;
    }
    (*temp).x = x;
    (*temp).y = y;
    (*temp).z = z;
    (*temp).mul = &mul;
    return(temp);
}

int main(void)
{
    vec3 *ptr1 = vec3_cons(2,5,6);

    printf("We had %i %i %i\n", ptr1->x, ptr1->y, ptr1->z);
    
    ptr1->mul(ptr1,2); 

    printf("We have %i %i %i\n", ptr1->x, ptr1->y, ptr1->z);

    free(ptr1);
    ptr1 = NULL;
    return(0);
}

