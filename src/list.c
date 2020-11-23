#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int FirstCall = 1;
position FreeSpace = 0;

position LiMakeNull( List *Lp )
{
    if( FirstCall )
    {
        FirstCall = 0;
        for(position i=0; i<LIST_MAXN-1; ++i)
            MemoryPool[i].next = i+1;
        MemoryPool[LIST_MAXN-1].next = GROUND;
    }
    Lp->first = GROUND;
    return LiEnd(*Lp);
}

position LiEnd( List L )
{
    if( FreeSpace == GROUND )
    {
        fprintf( stderr , "Memory overflow!\n" );
        exit(101);
    }
    else
        return FreeSpace;
}

void LiInsert( elementtype x , position p , List *Lp )
{
    if( p == LiEnd(*Lp) )
    {
        position freespace = FreeSpace;
        FreeSpace = MemoryPool[ FreeSpace ].next;

        MemoryPool[ freespace ].data = x;

        if( Lp->first == GROUND )
        {
            Lp->first = freespace;
            MemoryPool[ freespace ].next = GROUND;
        }
        else
        {
            position q;
            for( q = LiFirst(*Lp) ; LiNext(q,*Lp)!=LiEnd(*Lp) ; q = LiNext(q,*Lp) );
            
            MemoryPool[ q ].next = freespace;
            MemoryPool[ freespace ].next = GROUND;
        }
    }
    else
    {
        position freespace = FreeSpace;
        FreeSpace = MemoryPool[ FreeSpace ].next;
        
        MemoryPool[ freespace ].data = x;

        if( Lp->first == GROUND )
        {
            Lp->first = freespace;
            MemoryPool[ freespace ].next = GROUND;
        }
        else
        {
            position q;
            if( LiFirst(*Lp) == p )
            {
                MemoryPool[ freespace ].next = Lp->first;
                Lp->first = freespace;
            }
            else
            {
                for( q = LiFirst(*Lp) ; LiNext(q,*Lp)!=p ; q = LiNext(q,*Lp) );
                MemoryPool[ freespace ].next = p;
                MemoryPool[ q ].next = freespace;               
            }
        }
    }
    
}

void LiDelete( position p , List *Lp )
{
    if( p == LiFirst(*Lp) )
    {
        Lp->first = MemoryPool[p].next;
        MemoryPool[p].next = FreeSpace;
        FreeSpace = p;
    }
    else
    {
        position q;
        for( q = LiFirst(*Lp) ; LiNext(q,*Lp)!=p ; q=LiNext(q,*Lp) );
        MemoryPool[q].next = MemoryPool[p].next;
        MemoryPool[p].next = FreeSpace;
        FreeSpace = p;
    }
}

position LiFirst( List L )
{
    if( L.first == GROUND )
        return LiEnd(L);
    else
        return L.first;
}

position LiNext( position p , List L )
{
    if( MemoryPool[p].next == GROUND )
        return LiEnd(L);
    else
        return MemoryPool[p].next;
}

position LiPrevious( position p , List L )
{
    position q;
    for( q = LiFirst(L) ; LiNext(q,L)!=p ; q=LiNext(q,L) );
    return q;
}

elementtype LiRetreive( position p , List L )
{
    return MemoryPool[p].data;    
}