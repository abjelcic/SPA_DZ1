#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"

typedef List Polynomial;


void PolyMakeNull( Polynomial *Pp );
void PolyMakeNull( Polynomial *Pp )
{
    LiMakeNull(Pp);
}

void PolyInsert( monomial m , Polynomial *Pp );
void PolyInsert( monomial m , Polynomial *Pp )
{
    if( LiFirst(*Pp) == LiEnd(*Pp) )
        LiInsert( m , LiFirst(*Pp) , Pp );
    else
    {
        for( position q=LiFirst(*Pp) ; q!=LiEnd(*Pp) ; q=LiNext(q,*Pp) )
        {
            if( m.power > LiRetreive(q,*Pp).power )
            {
                LiInsert(m,q,Pp);
                return;
            }
            else if( m.power == LiRetreive(q,*Pp).power )
            {
                m.coefficient += LiRetreive(q,*Pp).coefficient;
                if( fabs(m.coefficient) > 1.e-12 )
                    LiInsert( m , q , Pp );
                LiDelete( q , Pp );
                return;
            }
        }

        LiInsert( m , LiEnd(*Pp) , Pp );

    }    
}

void PolyDerivative( Polynomial *Pp );
void PolyDerivative( Polynomial *Pp )
{
    Polynomial dP;
    LiMakeNull(&dP);

    for( position p = LiFirst(*Pp) ; p != LiEnd(*Pp) ; p = LiNext(p,*Pp) )
    {
        monomial m = LiRetreive(p,*Pp);
        
        monomial dm;
        if( m.power != 0 )
        {
            dm.power = m.power - 1;
            dm.coefficient = m.coefficient * m.power;
            LiInsert(dm,LiEnd(dP),&dP);
        }
    }

    while( LiFirst(*Pp) != LiEnd(*Pp) )
        LiDelete(LiFirst(*Pp),Pp);

    *Pp = dP;
    return;
}

void PolyDerivativeK( Polynomial *Pp , unsigned k );
void PolyDerivativeK( Polynomial *Pp , unsigned k )
{
    for(unsigned i=0; i<k; ++i)
        PolyDerivative(Pp);
    return;
}

void PolyPrint( Polynomial P );
void PolyPrint( Polynomial P )
{
    if( LiFirst(P) == LiEnd(P) )
        printf("0\n");
    else
    {
        printf( "%gx^%u ", LiRetreive(LiFirst(P),P).coefficient , LiRetreive(LiFirst(P),P).power );
        for(position p=LiNext(LiFirst(P),P) ; p!=LiEnd(P) ; p=LiNext(p,P) )
            printf( "+ %gx^%u ", LiRetreive(p,P).coefficient , LiRetreive(p,P).power );
        printf("\n");
    }
    
}



void test1();
void test1()
{
    monomial m;

    Polynomial P1;
    LiMakeNull(&P1);
    PolyPrint(P1);
    m.power = 0; m.coefficient = 1; PolyInsert( m , &P1 );
    m.power = 6; m.coefficient = 1; PolyInsert( m , &P1 );
    m.power = 2; m.coefficient = 1; PolyInsert( m , &P1 );
    m.power = 6; m.coefficient = 1; PolyInsert( m , &P1 );
    m.power = 1; m.coefficient = 1; PolyInsert( m , &P1 );
    PolyPrint(P1);

    Polynomial P2;
    LiMakeNull(&P2);
    PolyPrint(P2);
    m.power = 9; m.coefficient = 1; PolyInsert( m , &P2 );
    m.power = 0; m.coefficient = 1; PolyInsert( m , &P2 );
    m.power = 0; m.coefficient = 1; PolyInsert( m , &P2 );
    m.power = 9; m.coefficient = 1; PolyInsert( m , &P2 );
    m.power = 0; m.coefficient = 1; PolyInsert( m , &P2 );
    m.power = 0; m.coefficient = 1; PolyInsert( m , &P2 );
    m.power = 0; m.coefficient = 1; PolyInsert( m , &P2 );
    m.power = 0; m.coefficient = 1; PolyInsert( m , &P2 );
    m.power = 9; m.coefficient = 1; PolyInsert( m , &P2 );
    m.power = 1; m.coefficient = 1; PolyInsert( m , &P2 );
    PolyPrint(P2);

    Polynomial P3;
    LiMakeNull(&P3);
    PolyPrint(P3);
    m.power = 9; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 8; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 7; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 6; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 5; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 4; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 3; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 2; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 1; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 0; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 1; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 2; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 3; m.coefficient = 1; PolyInsert( m , &P3 );
    m.power = 4; m.coefficient = 1; PolyInsert( m , &P3 );
    PolyPrint(P3);
    m.power = 4; m.coefficient = -1; PolyInsert( m , &P3 );
    PolyPrint(P3);
    m.power = 4; m.coefficient = -1; PolyInsert( m , &P3 );
    PolyPrint(P3);

    return;
}

void test2();
void test2()
{
    monomial m;

    Polynomial P1;
    LiMakeNull(&P1);
    PolyPrint(P1);
    m.power = 0; m.coefficient = 1; PolyInsert( m , &P1 );
    m.power = 1; m.coefficient = 4; PolyInsert( m , &P1 );
    m.power = 2; m.coefficient = 4; PolyInsert( m , &P1 );
    m.power = 3; m.coefficient = 4; PolyInsert( m , &P1 );
    m.power = 4; m.coefficient = 4; PolyInsert( m , &P1 );
    PolyPrint(P1);
    PolyDerivative(&P1);
    PolyPrint(P1);
    PolyDerivative(&P1);
    PolyPrint(P1);
    PolyDerivative(&P1);
    PolyPrint(P1);
    PolyDerivative(&P1);
    PolyPrint(P1);
    PolyDerivative(&P1);
    PolyPrint(P1);
    PolyDerivative(&P1);
    PolyPrint(P1);


}




int main(int argc, char *argv[])
{
    //test1();
    //test2();
    //return 0;


    Polynomial P;
    PolyMakeNull(&P);

    size_t n,k;
    printf("Unesi broj monoma: ");
    if( scanf(" %lu", &n) != 1 )
    {
        printf("Data reading error.\n");
        exit(102);
    }
    printf("Unosi redom monome:\n");
    for(unsigned i=0; i<n; ++i)
    {
        double   coefficient;
        unsigned power;
        if( scanf("%lf %u", &coefficient, &power) != 2 )
        {
            printf("Data reading error.\n");
            exit(102);
        }

        monomial m;
        m.power = power;
        m.coefficient = coefficient;
        PolyInsert( m , &P );
    }

    printf("Unesi red derivacije: ");
    if( scanf(" %lu", &k) != 1 )
    {
        printf("Data reading error.\n");
        exit(102);
    }
    
    printf("Uneseni polinom je:\n");
    printf("p(x) = ");
    PolyPrint(P);
    PolyDerivativeK( &P , k );
    printf("%lu. derivacija od p(x) je: q(x) = ", k);
    PolyPrint(P);

    return 0;
}