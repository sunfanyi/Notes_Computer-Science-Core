#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 100

typedef int Status;
typedef int ElemType;


typedef struct 
{
    ElemType elem[MAXSIZE];  // 静态分配
    int length;
} SqList;


Status InitList(SqList *L)
{
    assert(L);
    for (int i=0; i<MAXSIZE; i++) {
        L->elem[i] = 0;
    }
    // if (L->elem == NULL) {
    //     printf("Memory allocation failed\n");
    //     return 0;
    // }  // unnecessary: static array will never be null
    L->length = 0;
    // (*L).length = 0;  // Alternative
    return 1;
}


Status testRnValues(SqList *L)
{
    L->elem[0] = 5;
    L->elem[1] = 10;
    L->elem[2] = 2;
    L->elem[3] = 8;
    L->length = 4;
    return 1;
}


void DestroyList(SqList *L)
{
    printf("Memory allocated statically does not need to be freed explicitly.\n");
}


void ClearList(SqList *L)
{
    L->length = 0;
}


int GetLength(SqList L)  // pass the struct
{
    return(L.length);
}


int IsEmpty(SqList L)
{
    return(L.length==0);
}


Status GetElem(SqList L, int i, ElemType *e)
{
    if (i<0 || i>L.length) 
    {
        printf("invalid position\n");
        return 0;
    }
    *e = L.elem[i];
    return 1;
}


ElemType LocateElem(SqList L, ElemType e)
{
    for (int i=0; i<L.length; i++)
    {
        if (L.elem[i]==e) {return i;}
    }
    return -1;
}


Status InsertList(SqList *L, int i, ElemType e)
{
    if (i<0 || i>L->length) 
    {
        printf("invalid position\n");
        return 0;
    }
    for (int j=L->length; j>=i; j--)
    {
        L->elem[j+1] = L->elem[j]; 
    }
    L->elem[i] = e; 
    L->length++;
    return 1;
}


Status DeleteListElem(SqList *L, int i)
{
    if (i<0 || i>L->length) 
    {
        printf("invalid position\n");
        return 0;
    }
    for (int j=i; j<L->length; j++)
    {
        L->elem[j] = L->elem[j+1]; 
    }
    L->length--;
    return 1;
}


int main()
{
    SqList L;

    InitList(&L);  // passing the address
    if (L.elem[0]==0 & IsEmpty(L)) {printf("Init Success\n");}

    testRnValues(&L);  // [5, 10, 2, 8]
    int e;
    GetElem(L, 1, &e);
    if (e==10) {printf("GetElem Success\n");}

    if (LocateElem(L, 2) == 2) {printf("LocateElem Success\n");}
    
    InsertList(&L, 1, 6);  // [5, 6, 10, 2, 8]
    int e2;
    GetElem(L, 1, &e2);
    if (e2 == 6) {printf("InsertList Success\n");}

    DeleteListElem(&L, 1);
    int e3;
    GetElem(L, 1, &e3);
    if (e3==10) {printf("DeleteListElem Success\n");}

    return 0;
}
