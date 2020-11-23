#include <stdio.h>
#include "list.h"

void printList( List L );

void printList( List L )
{
    printf("[");
    for(position p=LiFirst(L) ; p!=LiEnd(L) ; p=LiNext(p,L) )
        printf("%d, ",LiRetreive(p,L).power);
    printf("]\n");
}



int main(int argc, char *argv[])
{
    monomial m;
    
    List L;
    LiMakeNull(&L);
    
    printList(L);
    m.power = 1; LiInsert( m , LiFirst(L) , &L );
    m.power = 2; LiInsert( m , LiFirst(L) , &L );
    m.power = 3; LiInsert( m , LiFirst(L) , &L );
    m.power = 4; LiInsert( m , LiFirst(L) , &L );
    m.power = 5; LiInsert( m , LiFirst(L) , &L );
    m.power = 6; LiInsert( m , LiFirst(L) , &L );
    m.power = 7; LiInsert( m , LiFirst(L) , &L );
    m.power = 8; LiInsert( m , LiFirst(L) , &L );
    m.power = 9; LiInsert( m , LiFirst(L) , &L );
    printList(L);

    m.power = 10; LiInsert( m , LiNext( LiFirst(L) , L ) , &L );
    printList(L);
    m.power = 11; LiInsert( m , LiNext(LiNext(LiNext(LiFirst(L),L),L),L) , &L );
    printList(L);
    LiDelete( LiNext(LiNext(LiNext(LiNext(LiFirst(L),L),L),L),L) , &L );
    printList(L);
    LiDelete( LiFirst(L) , &L );
    printList(L);
    m.power = 12; LiInsert( m , LiFirst(L) , &L );
    printList(L);

    m.power = 13; LiInsert( m , LiNext(LiNext(LiNext(LiNext(LiFirst(L),L),L),L),L) , &L );
    m.power = 14; LiInsert( m , LiNext(LiNext(LiNext(LiNext(LiFirst(L),L),L),L),L) , &L );
    m.power = 15; LiInsert( m , LiNext(LiNext(LiNext(LiNext(LiFirst(L),L),L),L),L) , &L );
    m.power = 16; LiInsert( m , LiNext(LiNext(LiNext(LiNext(LiFirst(L),L),L),L),L) , &L );
    printList(L);

    LiDelete( LiNext(LiNext(LiNext(LiNext(LiFirst(L),L),L),L),L) , &L );
    LiDelete( LiNext(LiNext(LiNext(LiNext(LiFirst(L),L),L),L),L) , &L );
    LiDelete( LiNext(LiNext(LiNext(LiNext(LiFirst(L),L),L),L),L) , &L );
    printList(L);
    LiDelete( LiFirst(L) , &L );
    printList(L);
    printf("\n\n\n");
    
    List L2;
    LiMakeNull(&L2);
    
    printList(L2);
    m.power = 91; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 92; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 93; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 94; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 95; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 96; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 97; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 98; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 99; LiInsert( m , LiFirst(L2) , &L2 );
    printList(L2);
    LiDelete( LiNext(LiNext(LiNext(LiNext(LiFirst(L2),L2),L2),L2),L2) , &L2 );
    LiDelete( LiNext(LiFirst(L2),L2) , &L2 );
    printList(L2);
    LiDelete( LiFirst(L2) , &L2 );
    LiDelete( LiFirst(L2) , &L2 );
    LiDelete( LiFirst(L2) , &L2 );
    LiDelete( LiFirst(L2) , &L2 );
    LiDelete( LiFirst(L2) , &L2 );
    LiDelete( LiFirst(L2) , &L2 );
    LiDelete( LiFirst(L2) , &L2 );
    printList(L2);
    printList(L);
    printf("\n");
    m.power = 91; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 92; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 93; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 94; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 95; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 96; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 97; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 98; LiInsert( m , LiFirst(L2) , &L2 );
    m.power = 99; LiInsert( m , LiFirst(L2) , &L2 );
    printList(L2);
    printList(L);

    m.power = 1000; LiInsert( m , LiEnd(L) , &L );
    printList(L);
    printf("\n\n\n");

    List L3;
    LiMakeNull(&L3);
    printList(L3);
    m.power = 101; LiInsert( m , LiEnd(L3) , &L3 );
    printList(L3);
    m.power = 102; LiInsert( m , LiEnd(L3) , &L3 );
    m.power = 103; LiInsert( m , LiEnd(L3) , &L3 );
    m.power = 104; LiInsert( m , LiEnd(L3) , &L3 );
    m.power = 105; LiInsert( m , LiEnd(L3) , &L3 );
    printList(L3);


    return 0;
}