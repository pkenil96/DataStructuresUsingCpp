#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct DisjointSet{
    int n;
    int* parent;
};

typedef struct DisjointSet* DS;

DS createDisjointSet(int n){
    int i;
    DS newSet = (DS) malloc(sizeof(struct DisjointSet));
    newSet->n=n;
    newSet->parent=(int*) malloc (sizeof(int) * n);

    for(i=0;i<n;i++){
        newSet->parent[i]=i;
    }
    return newSet;
}

void MergeSet(DS ds, int x ,int y){
    int i,temp,swap;
    if(FindSet(ds,x)==FindSet(ds,y))
        return;
    if(x>y){
        //swap
        swap=x;
        x=y;
        y=swap;
    }
    temp = ds->parent[x];
    ds->parent[x]=y;


    for(i=0;i<ds->n;i++){
        if(ds->parent[i]==temp)
            ds->parent[i]=y;
    }
}

int FindSet(DS ds, int k){
    return ds->parent[k];
}

bool AreFriends(DS ds, int x, int y){
    return FindSet(ds,x)==FindSet(ds,y);
}

void displayDisjointSet(DS ds){
    /*this approach takes O(n^2) time and is not suitable for large n*/
    int i,j,n,hold,setnum=1;
    n=ds->n;
    int* displayed = (int*) malloc(sizeof(int)*n);
    
    for(i=0;i<n;i++){
        displayed[i]=0;
    }
   
    for(i=0;i<n;i++){
        displayed[i] = ds->parent[i];

        if(displayed[i]==1)
            continue;

        printf("Set %d : {",setnum++);
        for(j=i;j<n;j++){
            if((ds->parent[j]==displayed[i]) && (ds->parent[j]!=1)){
                printf("%d,",j);
                displayed[j]=1;
            }
        }
        printf("\b}\n");
    }
}

int main(int argc, char* argv[]){

    DS ds = createDisjointSet(8);
    MergeSet(ds,0,3);
    MergeSet(ds,1,4);
    MergeSet(ds,0,4);
    MergeSet(ds,3,5);
    MergeSet(ds,7,2);
    displayDisjointSet(ds);
    printf("\n");
    
    printf("Are friends %d and %d? %d\n",1,5,AreFriends(ds,1,5));
    printf("Are friends %d and %d? %d\n",2,5,AreFriends(ds,2,5));

    
    return 0;
}