#include <stdio.h>
#include "sqlist.h"
#include<stdlib.h>


int main()
{
    sqlist *list1,*list2;
    int err = 0;
    datatype arr1[]={12,23,34,45,56};
    datatype arr2[]={12,23,78,89,10};
    //list1 = sqlist_create();
    sqlist_create1(&list1);
    list2 = sqlist_create();
    if (list1 == NULL){
        fprintf(stderr, "sqlist_create() failed!\n");
        exit(1);

    }
    for(int i =0 ; i < sizeof(arr1)/sizeof(*arr1);i++)
    {
        if((err = sqlist_insert(list1,0,&arr1[i])) != 0)
        {
            if(err == -1)
                fprintf(stderr, "%s\n","The arr is full.\n");
            else if (err == -2)
                fprintf(stderr, "%s\n","The pos you want to insert is wrong! \n" );
            else
                fprintf(stderr, "%s\n","Error!\n" );
            exit(1);
        }
    }
    err = 0;
    if (list2 == NULL){
        fprintf(stderr, "sqlist_create() failed!\n");
        exit(1);

    }
    for(int i =0 ; i < sizeof(arr2)/sizeof(*arr2);i++)
    {
        if((err = sqlist_insert(list2,0,&arr2[i])) != 0)
        {
            if(err == -1)
                fprintf(stderr, "%s\n","The arr is full.\n");
            else if (err == -2)
                fprintf(stderr, "%s\n","The pos you want to insert is wrong! \n" );
            else
                fprintf(stderr, "%s\n","Error!\n" );
            exit(1);
        }
    }
    sqlist_display(list1);
    sqlist_display(list2);
    sqlist_union(list1,list2);
    sqlist_display(list1);

    sqlist_destroy(list1);
    sqlist_destroy(list2);



    exit(0);
}