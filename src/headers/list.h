#ifndef LIST_H
#define LIST_H

#include "list_datatype.h"

typedef long int position;

typedef monomial elementtype;

typedef struct list_cell
{
    elementtype data;
    position    next;
} list_cell;

typedef struct List
{
    position first;
} List;

#define LIST_MAXN 100000
list_cell MemoryPool [LIST_MAXN];

#define GROUND (-1)


position LiEnd( List L );
position LiMakeNull( List *Lp );
void LiInsert( elementtype x , position p , List *Lp );
void LiDelete( position p , List *Lp );
position LiFirst( List L );
position LiNext( position p , List L );
position LiPrevious( position p , List L );
elementtype LiRetreive( position p , List L );

#endif // LIST_H