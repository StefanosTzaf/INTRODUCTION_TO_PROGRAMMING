#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int m(int i,int j,int nrid,int *dests,int**mem);
int fw(int a,int b,int sumofpeople,int *destinations);
int max(int x,int *dests);

int solve(int nrid,int nst ,int *dests){
	int **dynamic ,**stops;
    int mincost=INT_MAX;
	int k,j,i,temp,minn,position_min,last_stop;
	int nfl=max(nrid,dests);
    dynamic=malloc((nst+1) * sizeof(int*));//array to save all values of function M(i,j),0<=i<=nst,0<=j<=nfl.
    stops=malloc((nst+1) * sizeof(int*));
	if ((dynamic==NULL)||(stops==NULL)){
	   return -1;
    }
    for (i=0;i<=nst;i++){
   	   dynamic[i]=malloc((nfl+1)*sizeof(int)); //allocate memory for values of M (calculated forward)
   	   stops[i]=malloc((nfl+1)*sizeof(int));   //allocate memory to save every K for which value of dynamic[i][k] was minimun
	   if ((dynamic[i]==NULL)||(stops[i]==NULL)){
	      return -1;
	   }
    }
	for (i=0;i<=nst;i++){
 	   for(j=0;j<=nfl;j++){
          if(i==0){
            dynamic[i][j]=fw(0,INT_MAX,nrid,dests);
            stops[i][j]=0;
		  }
		  else{
		  	minn=INT_MAX;
		    for (k=0;k<=j;k++){
		       temp=(dynamic[i-1][k]-fw(k,INT_MAX,nrid,dests)+fw(k,j,nrid,dests)+fw(j,INT_MAX,nrid,dests));
	              if (temp<minn){
	                 minn=temp;
	                 position_min=k;
	  	          }  
	        }
//for every i,j save value of k for which M(i,j) is minimun
	        stops[i][j]=position_min;
	        dynamic[i][j]=minn;
	      }
        }
    }
    mincost=INT_MAX;
	for(j=0;j<=nfl;j++){
		temp=dynamic[nst][j];
		if (temp<mincost){
			mincost=temp;
			last_stop=j;
		}
	}
//find laststop just like in memorization method
	for(i=0;i<=nst;i++){
		for(j=0;j<=nfl;j++){
			printf("%3d ",dynamic[i][j]);
		}
		printf("\n");
	}		
	if (nst==0){
	   printf("No lift stops\n");
    }
    else{
       int *a;
       a=malloc((nst)*sizeof(int));
//allocate memory to save stops of elevator so as to print them in the rigth order
       a[nst-1]=last_stop;
       for (i=nst;i>1;i--){
		     a[i-2]=stops[i][last_stop];
		     last_stop=stops[i][last_stop];
//if we observe array stops,last_stop is the position(stops[i][last_stop]) for the previous stop and so on.	
	    }
	    printf("Lift stops are:");
	    for(i=0;i<nst;i++){
	    	if(a[i]!=0){
			  printf("% d",a[i]);   
            }
        }
        printf("\n");
  	    free(a);
    }     
    for(j=0;j<=nst;j++){
	   free(dynamic[j]);
	   free (stops[j]);
    }
    free(dynamic);
    free(stops);
    return mincost;		
}
//function m is unnecessary while values of M are computed by previous values of M that have been saved to array dynamic
int fw(int a,int b,int sumofpeople,int *destinations){
//returns the total of floors  that passengers have to walk(only for passengers that their destinations are between a and b)
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
