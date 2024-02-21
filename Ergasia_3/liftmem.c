#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int m(int i,int j,int nrid,int *dests,int**mem);
int fw(int a,int b,int sumofpeople,int *destinations);
int max(int x,int *dests);


int solve(int nrid,int nst ,int *dests){
	int **mem;
    int mincost=INT_MAX,j,i,temp1,last_stop;
	int nfl=max(nrid,dests);
//the higher destination
    mem=malloc((nst+1)* sizeof(int*));
//array has got one more row (nst+1) becuase it is possible for elevator to make 0 stops.For instance, if nst=2 elevator may do 0,1, or 2 stops. 
    if (mem==NULL){
	   return -1;//message will be printed in main.
    }
    for (i=0;i<=nst;i++){
   	   mem[i]=malloc((nfl+1)*sizeof(int));
//array has got one more column (nfl+1) becuase it is possible for elevator to stop maximun at stop nfl(0--ground level is included ).For instance,
// if nst=3 elevator may stop at 0 1 2 or 3 floor  
	   if (mem[i]==NULL){
	      return -1;
	   }
	   for (j=0;j<=nfl;j++){
		  mem[i][j]=-1;
	   }
//initialize array mem with -1 because in function m we check if mem[i][j]==-1 so as not to re-compute its value.
//if array had been initialized with 0,re-compute may had been occured because m is able to take the value 0 ,and program would not understand that the value has been calculated  
    }
	for(j=0;j<=nfl;j++){
		temp1=m(nst,j,nrid,dests,mem);
		if (temp1<mincost){
			mincost=temp1;
			last_stop=j;
		}
	}
    for(j=0;j<=nst;j++){
	   free(mem[j]);
    }
    free(mem);
    if (nst==0){
	   printf("No lift stop\n");
    }
    else{
  	  printf("Last stop at floor %d\n",last_stop);
    }
    return mincost;		
}

int m(int i,int j,int nrid,int *dests,int ** mem){
    int k,temp;
    int minn=INT_MAX;
    if (mem[i][j]==-1){//mem [i][j] has not been calculated
        if (i==0){
        	minn=fw(0,INT_MAX,nrid,dests);
        	mem[i][j]=minn;
	    }
	    else{
  	       for (k=0;k<=j;k++){
              temp=(m(i-1,k,nrid,dests,mem)-fw(k,INT_MAX,nrid,dests)+fw(k,j,nrid,dests)+fw(j,INT_MAX,nrid,dests));
	          if (temp<minn){
	             minn=temp;
	  	       }  
	        }
	        mem[i][j]=minn;
        }   
    }
    return mem[i][j];
}


int fw(int a,int b,int sumofpeople,int *destinations){
//it returns the total of floors  that passengers have to walk(only for passengers that their destinations are between a and b)
	int i,x;
	int sumcost=0;
	for (i=0;i<sumofpeople;i++){
		x=destinations[i];
		if ((x > a) && (x <= b)){
			if (b - x <= x - a){
			    sumcost+= (b - x);//passenger would go up
		    }
		    else{
		    	sumcost+=(x - a);//passenger would descend
			}
             
		}	
 	}
 	return sumcost;
}

int max(int x,int *dests){
	int max1=0,i;
	for (i=0;i<x;i++){
		if (dests[i]>max1){
           max1=dests[i];		
		}
	}
	return max1;
}
