#include <stdio.h>
#include <limits.h>

int m(int i,int j,int nrid,int *dests);
int fw(int a,int b,int sumofpeople,int *destinations);
int max(int x,int *dests);


int solve(int nrid,int nst ,int *dests){
    int mincost=INT_MAX,j,temp1,last_stop;
	int nfl=max(nrid,dests);
//find the higher destination
	for(j=0;j<=nfl;j++){
		temp1=m(nst,j,nrid,dests);
		if (temp1<mincost){
			mincost=temp1;
			last_stop=j;
		}
	}
    if (nst==0){
	   printf("No lift stop\n");
    }
    else{
   	   printf("Last stop at floor %d\n",last_stop);
    }
    return mincost;		
}

int m(int i,int j,int nrid,int *dests){
    int k,temp;
    int minn=INT_MAX;
    if (i==0){
    	minn=fw(0,INT_MAX,nrid,dests);
	}
	else{
	   for (k=0;k<=j;k++){
          temp=(m(i-1,k,nrid,dests)-fw(k,INT_MAX,nrid,dests)+fw(k,j,nrid,dests)+fw(j,INT_MAX,nrid,dests));
	      if (temp<minn){
		      minn=temp;
	  	  } 
	   }
    }
    return minn;
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
	int max1=-1,i;
	for (i=0;i<x;i++){
		if (dests[i]>max1){
           max1=dests[i];		
		}
	}
	return max1;
}
