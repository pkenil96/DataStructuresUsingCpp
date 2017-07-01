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

    /*
	Initially all the elements are independent; so the element itself is its parent
    */
    for(i=0;i<n;i++){
        newSet->parent[i]=i;
    }
    return newSet;
}

void MergeSet(DS ds, int x ,int y){
    int i,temp,swap;
	/*in case the elements already belongs to the same set; return*/
    if(FindSet(ds,x)==FindSet(ds,y))
        return;
    
    if(x>y){
        swap=x;
        x=y;
        y=swap;
    }
    temp = ds->parent[x];
   //setting the parent of x to 
    ds->parent[x]=ds->parent[y];

   
    for(i=0;i<ds->n;i++){
        if(ds->parent[i]==temp)
            ds->parent[i]=ds->parent[y];
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
        //displayed[i] = ds->parent[i];
        hold = ds->parent[i];
        if(displayed[i]==1)
            continue;

        printf("Set %d : {",setnum++);
        for(j=i;j<n;j++){
            if((ds->parent[j]==hold) && (displayed[j]!=1)){
                printf("%d,",j);
                displayed[j]=1;
            }
        }
        printf("\b}\n");
    }
}
