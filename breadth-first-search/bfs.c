/* Welcome to HARDCODING FEST 2021 */
/* Most comments point this problem out, but honestly I already 
   had implemented linked lists and queues for this, also doing 
   lists of lists and dynamic arrays was a bit out of my reach 
   for today, feel free to improve on this
*/

#include <stdio.h>
/* For custom queue functionality */
#include "AllDS.h"

struct node_info {
    int distance, predecessor;
};


struct node_info * bfs_alg(int graph[][3], int length, int source)
{
    /* I'm too tired to implement dynamic arrays rn */
    struct node_info *info_arr = (struct node_info *) malloc(sizeof(struct node_info)*7);
    struct queue_by_list *queue = new_queue();
    int it, u, v, j;

    /* Initializes the entry values to -1, as NULL == 0 and could fail */
    for (it = 0; it < length; it++)
    {
	    info_arr[it].distance = -1;
	    info_arr[it].predecessor= -1;
    }

    /* Set the distance of the source to 0 and add to queue */
    info_arr[source].distance = 0;
    enqueue(queue, source);

    while(!queue_is_empty(queue))
    {
        u = dequeue(queue);

        for (j = 0; j < 3; j++)
        {
            v = graph[u][j];
            if (info_arr[v].distance == -1)
            {
                info_arr[v].distance = info_arr[u].distance + 1;
                info_arr[v].predecessor = u;
                enqueue(queue, v);
            }
        }
    }
    return info_arr;
}

int main(void)
{
    /* I'd have to implement lists of lists of ints otherwise*/
    int adjacent_list[][3] = {{1,-1,-1},{0, 4, 5},{3, 4, 5},{2, 6, -1},{1, 2, -1},{1, 2, 6},{3, 5, -1},{-1, -1, -1}};
    int it;
    /* I'm too tired to implement dynamic arrays rn */
    struct node_info *info;
    
    info = bfs_alg(adjacent_list, 8, 3);
    for (it = 0; it < 8; it++)
        printf("%i distance: %i predecessor: %i\n",it, info[it].distance, info[it].predecessor);

    /* missing the free() and I'm completely aware, treat em as 'singletons' */

    return(0);
}

/*
Expected
0 distance: 4   predecessor: 1
1 distance: 3   predecessor: 4
2 distance: 1   predecessor: 3
3 distance: 0   predecessor: -1
4 distance: 2   predecessor: 2
5 distance: 2   predecessor: 2
6 distance: 1   predecessor: 3
7 distance: -1  predecessor: -1
*/
