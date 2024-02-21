#include <stdio.h>
#include <ctype.h>

int getinteger(int x1){
    int result=0; 
    while (isspace(x1)==0){
    if (x1 >= '0' && x1 <= '9'){
         result=result*10+(x1-'0');
    }
    else{
         return -1;
    }
    x1=getchar();
    }
    printf("%d",result);
    putchar(x1);//the last x1 was an white space char
	//getinteger is a function which reads numbers with getchar until is read ''white space'' and it returns the decimal number of the sequence of numbers 
} 
int whitespace(void){
	int x=getchar();
    while (isspace(x)){
    	putchar(x);
    	x=getchar();
   	}
	return x;
}
//it isn't be checked if it wasn't read none white space.This because ,every time this function is called,a white space has been read so as to end the previous loop;

int main(void){
    int width,x,y,height,max,luminosity,red,green,blue,comments,grey;
    int magic_number_p=getchar();
    int magic_number=getchar();
    if (magic_number_p !='P'){
	    printf("\ninput error 'Couldn't find magic number'");
		return -1;
    }
    putchar(magic_number_p);
    switch (magic_number){
        case ('3'):
           putchar('2');
           break;
        case ('2'):
           putchar('1');
           break;
    	case('1'):
     	   printf("\nInput error (NO PBM PICTURES)");
           return -1;
		   break;
		case ('6'):
           putchar('5');
           break;
		case ('5'):
           putchar('4');
           break;
    	case ('4'):
     	   printf("\nInput error (NO PBM PICTURES PLEASE)");
     	   return -1;
	       break;
    }
	if (magic_number!='1' && magic_number!='2' &&  magic_number!='3' &&  magic_number!='4' &&  magic_number!='5' &&  magic_number!='6' ){
	  printf("\ninput error 'Couldn't find magic number'");
	  return -1;
    }
    x=getchar();
    if (isspace(x)){
       while (isspace(x)){
    	   putchar(x);
      	   x=getchar();
//the last white space wasnt white so we keep it for the next computations
	   }
    }
	else{
		printf("\nInput error");
		return -1;
	}	
    if (x =='#'){
        comments=1;
    }
    else{
    	comments=0;
    	y=x;//the next while will not be executed so y will not have value
	}
    while(comments == 1){
        if(x != '\n'){
        	x=getchar();
        }
        else{
		   if ((y=getchar())!='#'){
		   	   comments=0;
		   	   putchar('\n');
		   } 
		   else {
		       x=getchar();
		   }
		}
    }
    width=0;
    while (isspace(y)==0){
		if (y >= '0' && y <= '9'){
            width=width*10+(y-'0');
        }
        else{
            printf("\nInput error  'Couldn't read width'");
            return -1;
	    }
    	y=getchar();
    }
    printf("%d",width);
    putchar(y);
    x=whitespace();
	height=0;
    while (isspace(x)==0){
		if (x >= '0' && x <= '9'){
            height=height*10+(x-'0');
        }
        else{
            printf("\nInput error  'Couldn't read height'");
            return -1;
	    }
    	x=getchar();
    }
    printf("%d",height);
    putchar(x);//white space that was read so as to end the loop
 	x=whitespace();	
    switch (magic_number){
      case '3':
         max=0;
		 while (isspace(x)==0){
			if (x >= '0' && x <= '9'){
               max=max*10+(x-'0');
        	}
        	else{
        	   printf("\nInput error 'Couldn't read max'");
          	   return -1;
	   		}
    		x=getchar();
         }
         printf("%d",max);
    	 putchar(x);
    	 x=whitespace();
         while(x!=EOF){
            red=0;
            while (isspace(x)==0){
	        if (x >= '0' && x <= '9'){
                red=red*10+(x-'0');
            }
            else{
             	printf("\nInput error");
                return -1;
	        }
    	    x =getchar();
            }
            putchar(x);//the las byte was white space
	        x=whitespace();
		    green=0;
            while (isspace(x)==0){
		       if (x >= '0' && x <= '9'){
                  green=green*10+(x-'0');
               }
               else{
               	  printf("\nInput error");
                  return -1;
	           }
    	       x =getchar();
            }
            putchar(x);//the las byte was white space
	        x=whitespace();
		    blue=0;
            while (isspace(x)==0){
		       if (x >= '0' && x <= '9'){
                  blue=blue*10+(x-'0');
               }
               else{
               	  printf("\nInput error");
                  return -1;
	           }
    	       x =getchar();
            }
            putchar(x);//the las byte was white space
	        x=whitespace();
            luminosity=((299*red +587*green+114*blue)/1000);
            if (luminosity>max){
          	   printf("\nInput error");
          	   return -1;
		    } 
	        printf("%d",luminosity);
	        }//(the basic while)
		    break;
	  case '2':
         max=0;
	     while (isspace(x)==0){
		    if (x >= '0' && x <= '9'){
                max=max*10+(x-'0');
            }
            else{
                printf("\nInput error");
                return -1;
	        }
    	    x=getchar();
         }
//dont print max value for black and white
         putchar(x);
	     int i=(max+1)/2;//i would become an integer since it is unsigned int
         x=whitespace();
         while(x!=EOF){
            grey=0;
            while (isspace(x)==0){
		       if (x >= '0' && x <= '9'){
                  grey=grey*10+(x-'0');
               }
               else{
               	  printf("\nInput error");
                  return -1;
	           }
    	       x =getchar();
           }
           putchar(x);//the las byte was white space
	       x=whitespace();
           if (grey>i){
			   putchar('0');
	       }
		   else{
			   putchar('1');
		   }
	     }
    	 break;
	  case '6':
	     max=0;
	 	 while (isspace(x)==0){
		     if (x >= '0' && x <= '9'){
                max=max*10+(x-'0');
               }
             else{
             	printf("\nInput error");
                return -1;
	         }
    	     x =getchar();
         }
         printf("%d",max);//omly one white space character for binary
         putchar(x);
	     red=getchar();
	     green=getchar();
	     blue=getchar();
	 	 while ((red!=EOF)&&(blue!=EOF)&&(green!=EOF)){ 		
             luminosity=((299*red +587*green+114*blue)/1000);
      		 putchar(luminosity);
	         red=getchar();
	      	 green=getchar();
	     	 blue=getchar(); 
		 }		  
         break;
      case '5':
         max=0;
         int black_and_white_byte=0;
	     while (isspace(x)==0){
		    if (x >= '0' && x <= '9'){
                 max=max*10+(x-'0');
            }
            else{
               	printf("\nInput error");
                return 1;
	        }
    	    x=getchar();
         }
    //dont print max value for black and white
         x=getchar();
         int pl=0,k,temp;
         while (x!=EOF){
            pl++;
            if(x<=(int)((max+1)/2)){//1
            	 black_and_white_byte<<=1;
            	 black_and_white_byte|=1;
			}
		    else if ((x>(int)((max+1)/2))){
		        black_and_white_byte<<=1;//pixel 0
			}
		    else{
		    	printf("input error");
			}
			if (pl%8==0){
				putchar(black_and_white_byte);
				black_and_white_byte=0;
			}
			if((width%8!=0) && (pl&width==0)){           //width % 8 means that columns are not multiple of 8|pl & width means that the we are in the end of a line 
				temp=(pl % 8);
				for (k=0;k<(8-temp);k++){
				    black_and_white_byte<<=1;
			      	black_and_white_byte|=1;
				}
				putchar(black_and_white_byte);
				black_and_white_byte=0;
		    }
            x=getchar();
			}			
            break;
      default :
     	    break;
    }
}
