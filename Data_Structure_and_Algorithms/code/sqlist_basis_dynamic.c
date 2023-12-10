#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 100

typedef int Status;
typedef int ElemType;


typedef struct 
{
    ElemType* elem;  // 动态分配
    int length;
} SqList;


Status InitList(SqList *L)
{
    assert(L);
    // L->elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);  // non-zero
    L->elem = (ElemType*)calloc(MAXSIZE, sizeof(ElemType));  // zeros
    if (L->elem == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }
    L->length = 0;
    // (*L).length = 0;  // Alternative
    return 1;
}


void DestroyList(SqList *L)
{
    if (L->elem) {
        free(L->elem);
        L->elem = NULL;  // Set the pointer to NULL after freeing the memory
        L->length = 0;
    }
}


int main()
{
    SqList L;

    if (InitList(&L) == 1)
    {
        printf("%d\n", L.elem[0]);
        printf("%d\n", L.length);
        printf("Init Success\n");
    }

    DestroyList(&L);
    if (L.elem == NULL && L.length == 0)
    {
        printf("Destroy Success\n");
        // printf("%d\n", L.elem[0]);  // now this will fail
    }

    return 0;
}
