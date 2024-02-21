#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int main(void) {
   int nrid,nst,*dests,i,mincost;
   scanf("%d%d",&nrid,&nst);
//read sum of people and max lift stops
   dests=malloc(nrid*sizeof(int));
   if (dests==NULL) {
   	 printf("Cannot allocate memory");
   	 return -1;
   }
   for (i=0;i<nrid;i++){
   	   scanf("%d",&dests[i]);
//destination of every passenger
   } 
   mincost=solve(nrid,nst,dests);
   printf("Cost is: %d\n",mincost);
   free(dests);
   return 0;
}
