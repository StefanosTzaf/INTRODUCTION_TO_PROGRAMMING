#include <stdio.h>
#include <ctype.h>
#define mode 1
//mode 1 means that the conversions which will be executed, would be the standars 
//mode 2 means that a conversion of codification will be executed  

int whitespace(void){
	int x=getchar();
    while (isspace(x)){
    	putchar(x);
    	x=getchar();
   	}
	return x;
}
//it isn't be checked if it wasn't read none white space.This because ,every time this function is called,a white space has been read already, so as to end the previous loop.

int main(){
    int width,x,y,height,max,luminosity,red,green,blue,comments,grey;
    int magic_number_p;
    int magic_number;
  if (mode==1){
    magic_number_p=getchar();
    magic_number=getchar();
    if (magic_number_p !='P'){
	    printf("\ninput error :'Couldn't find magic number'");
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
     	   printf("\nInput error:NO PBM PICTURES");
           return -1;
		   break;
		case ('6'):
           putchar('5');
           break;
		case ('5'):
           putchar('4');
           break;
    	case ('4'):
     	   printf("\nInput error : NO PBM PICTURES PLEASE");
     	   return -1;
	       break;
    }
//conversion of magic number
	if (magic_number!='1' && magic_number!='2' &&  magic_number!='3' &&  magic_number!='4' &&  magic_number!='5' &&  magic_number!='6' ){
	  printf("\ninput error : 'Couldn't find magic number'");
	  return -1;
    }
    x=getchar();
    if (isspace(x)){
       while (isspace(x)){
    	   putchar(x);
      	   x=getchar();
//the last white space wasn't white so we keep it for the next computations.
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
    	y=x;//the next 'while' will not be executed so y will not have got a value(and y needs later)
	}
    while(comments == 1){
        if(x != '\n'){
        	x=getchar();
        }
        else{
		   if ((y=getchar())!='#'){//if the previous byte was 'new line' and the next one is not '#' the comments have been to an end.
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
            printf("\nInput error : 'Couldn't read width'");
            return -1;
	    }
    	y=getchar();
    }
    if (width==0){
    	printf("\nInput error : 'Couldn't read width'");
    	return -1;
	}
    printf("%d",width);
    putchar(y);//white space
    x=whitespace();
	height=0;
    while (isspace(x)==0){
		if (x >= '0' && x <= '9'){
            height=height*10+(x-'0');
        }
        else{
            printf("\nInput error : 'Couldn't read height'");
            return -1;
	    }
    	x=getchar();
    }
    if (height==0){
    	printf("\nInput error : 'Couldn't read height'");
    	return -1;
	}
    printf("%d",height);
    putchar(x);//print the white space which was read so as to end the loop
 	x=whitespace();	
    switch (magic_number){
      case '3':
         max=0;
		 while (isspace(x)==0){
			if (x >= '0' && x <= '9'){
               max=max*10+(x-'0');
        	}
        	else{
        	   printf("\nInput error : 'Couldn't read max'");
          	   return -1;
	   		}
    		x=getchar();
         }
         if (max==0 || max>255){
         	printf("Input error : 'Couldn't read max'");
         	return -1;
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
             	printf("\nInput error : Invalid Character");
                return -1;
	        }
	        if (red>255){
       	        printf("Input error : Higher value than expected");
       	        return -1;
            }
    	    x =getchar();
            }
	        x=whitespace();
		    green=0;
            while (isspace(x)==0){
		       if (x >= '0' && x <= '9'){
                  green=green*10+(x-'0');
               }
               else{
               	  printf("\nInput error : Invalid Character");
                  return -1;
	           }
    	       x =getchar();
            }
            if (green>255){
       	        printf("Input error : Higher value than expected");
            	return -1;
            }
	        x=whitespace();
		    blue=0;
            while (isspace(x)==0){
		       if (x >= '0' && x <= '9'){
                  blue=blue*10+(x-'0');
               }
               else{
               	  printf("\nInput error : Invalid Character");
                  return -1;
	           }         
    	       x =getchar();
            }
            if (blue>255){
       	       printf("Input error : Higher value than expected");
               return -1;
            }	              
            putchar(x);//the last byte was white space
	        x=whitespace();
            luminosity=((299*red +587*green+114*blue)/1000);
            if (luminosity>max){
          	   printf("\nInput error");
          	   return -1;
		    } 
	        printf("%d",luminosity);
	     }//the basic loop ends
		 break;
	  case '2':
         max=0;
	     while (isspace(x)==0){
		    if (x >= '0' && x <= '9'){
                max=max*10+(x-'0');
            }
            else{
         	   printf("Input error : 'Couldn't read max'");
         	   return -1;
	        }
    	    x=getchar();
         }
         if (max==0 || max>255){
         	printf("Input error : 'Couldn't read max'");
         	return -1;
		 }
//dont print max value for black and white ,while output-picture is p1
         putchar(x);
	     int i=(max+1)/2;//'i' would automatically become an integer since it is is declared as int(floor of type is automatically executed)
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
           if (grey>255){
       	       printf("Input error : Higher value than expected");
               return -1;
           }	  
           putchar(x);
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
             	printf("\nInput error : Couldn't read max'");
                return -1;
	         }
    	     x =getchar();
         }
        if (max==0 || max>255){
            printf("Input error : 'Couldn't read max'");
         	return -1;
		 }
         printf("%d",max);//only one white space character after max for binary coded pictures--so no whitespace function needed
         putchar(x);
	     red=getchar();
	     green=getchar();
	     blue=getchar();
	 	 while ((red!=EOF)&&(blue!=EOF)&&(green!=EOF)){ 
             luminosity=((299*red +587*green+114*blue)/1000);
//no conversion needed because every byte is a quantity of a colour.It is not read every digit of a number so as to create it with getinteger-like in ascii coded pictures.
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
               	printf("\nInput error : Couldn't read max'");
                return 1;
	        }
    	    x=getchar();
         }
//max is not printed because picture is conversed to p4
         if (max==0 || max>255){
         	printf("Input error : 'Couldn't read max'");
         	return -1;
		 }
         x=getchar();
         int count=0,k,temp;
         while (x!=EOF){
            count++;
            if(x<=(int)((max+1)/2)){
//if the quantity of gray is smaller or equal than (max+1)/2, the current pixel of result-picture is black(bit 1).
//To succeed this ,we do a shift left on the byte which will include 8 pixels and a 'bitwise or' with LSB.  
            	 black_and_white_byte<<=1;
            	 black_and_white_byte|=1;
			}
		    else if ((x>(int)((max+1)/2))){
		        black_and_white_byte<<=1;
//if the quantity of gray is larger than (max+1)/2, the current pixel of result-picture is white(bit 0).
//To succeed this ,we do ONLY a shift left on the byte which will include 8 pixels.
			}
		    else{
		    	printf("input error");
			}
			if (count%8==0){
				putchar(black_and_white_byte);
				black_and_white_byte=0;
//If a byte is completed (8 pixels ) print it.
			}
			if((width%8!=0) && (count%width==0)){           //width % 8 means that columns are not multiple of 8|count % width means that the we are in the end of a line.
//so under these two conditions we complete the byte with black pixels 
				temp=(count % 8);
				for (k=0;k<(8-temp);k++){
				    black_and_white_byte<<=1;
			      	black_and_white_byte|=1;
				}
				putchar(black_and_white_byte);
				black_and_white_byte=0;
				count=0;
		    }
            x=getchar();
		}			
        break;
      default :
     	break;
    }
  }
  else if (mode==2){//Conversions between codification(bonus)
     magic_number_p=getchar();
     magic_number=getchar();
     if (magic_number_p !='P'){
	    printf("\ninput error :'Couldn't find magic number'");
		return -1;
    }
    putchar(magic_number_p);
    switch (magic_number){
        case ('3'):
           putchar('6');
           break;
        case ('2'):
           putchar('5');
           break;
    	case('1'):
     	   putchar('4');
		   break;
		case ('6'):
           putchar('3');
           break;
		case ('5'):
           putchar('2');
           break;
    	case ('4'):
     	   putchar('1');
	       break;
    }
   	if (magic_number!='1' && magic_number!='2' &&  magic_number!='3' &&  magic_number!='4' &&  magic_number!='5' &&  magic_number!='6' ){
        printf("\ninput error : 'Couldn't find magic number'");
	    return -1;
    }
    x=getchar();
    if (isspace(x)){
       while (isspace(x)){
    	   putchar(x);
      	   x=getchar();
	   }
    }
	else{
		printf("\nInput error");
		return -1;
	}	
//at least one whitespace has to be read
    if (x =='#'){
        comments=1;
    }
    else{
    	comments=0;
    	y=x;
	}
    while(comments == 1){
        if(x != '\n'){
        	putchar(x);
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
            printf("\nInput error : 'Couldn't read width'");
            return -1;
	    }
    	y=getchar();
    }
    if (width==0){
    	printf("\nInput error : 'Couldn't read width'");
    	return -1;
	}
    printf("%d",width);
    putchar(y);//white space
    x=whitespace();
	height=0;
    while (isspace(x)==0){
		if (x >= '0' && x <= '9'){
            height=height*10+(x-'0');
        }
        else{
            printf("\nInput error : 'Couldn't read height'");
            return -1;
	    }
    	x=getchar();
    }
    if (height==0){
    	printf("\nInput error : 'Couldn't read height'");
    	return -1;
	}
    printf("%d",height);
    putchar(x);//white space that was read
 	x=whitespace();
 	switch (magic_number){
 	  case '3':
         max=0;
		 while (isspace(x)==0){
			if (x >= '0' && x <= '9'){
               max=max*10+(x-'0');
        	}
        	else{
        	   printf("\nInput error : 'Couldn't read max'");
          	   return -1;
	   		}
    		x=getchar();
         }
         if (max==0 || max>255){
         	printf("Input error : 'Couldn't read max'");
         	return -1;
		 }
//magic number , comments,width,height,max are printed with their ascii-coded form in every case.  
         printf("%d",max);
    	 putchar(x);
         x=getchar();
         while (isspace(x)){ 
        	x=getchar();
      	}
         while(x!=EOF){
		  red=0;
          while (isspace(x)==0){
	        if (x >= '0' && x <= '9'){
                red=red*10+(x-'0');
            }
            else{
             	printf("\nInput error : Invalid Character");
                return -1;
	        }
	        if (red>255){
       	        printf("Input error : Higher value than expected");
       	        return -1;
            }
    	    x =getchar();
          }
          putchar(red);
	      x=getchar();
          while (isspace(x)){
           	x=getchar();//no spaces required in binary codification
          }
		  green=0;
          while (isspace(x)==0){
		     if (x >= '0' && x <= '9'){
                green=green*10+(x-'0');
             }
             else{
           	    printf("\nInput error : Invalid Character");
                return -1;
	         }
    	     x =getchar();
         }
         if (green>255){
             printf("Input error : Higher value than expected");
             return -1;
         }
         putchar(green);
	     x=getchar();
         while (isspace(x)){
          	x=getchar();
         }
		 blue=0;
         while (isspace(x)==0){
		    if (x >= '0' && x <= '9'){
                blue=blue*10+(x-'0');
            }
            else{
                printf("\nInput error : Invalid Character");
                return -1;
	        }         
            x =getchar();
        }
        if (blue>255){
            printf("Input error : Higher value than expected");
            return -1;
        }	              
		putchar(blue);         	
        x=getchar();
        while (isspace(x)){
    	    x=getchar();
      	}
       }
       break;
      case '2':
      	 max=0;
		 while (isspace(x)==0){
			if (x >= '0' && x <= '9'){
               max=max*10+(x-'0');
        	}
        	else{
        	   printf("\nInput error : 'Couldn't read max'");
          	   return -1;
	   		}
    		x=getchar();
         }
         if (max==0 || max>255){
         	printf("Input error : 'Couldn't read max'");
         	return -1;
		 }
         printf("%d",max);
    	 putchar(x);
         x=getchar();
         while (isspace(x)){ 
        	x=getchar();
      	}
        while(x!=EOF){
	      grey=0;
          while (isspace(x)==0){
	         if (x >= '0' && x <= '9'){
                grey=grey*10+(x-'0');
             }
             else{
             	printf("\nInput error : Invalid Character");
                return -1;
	         }
	         if (grey>255){
       	        printf("Input error : Higher value than expected");
       	        return -1;
             }
    	     x =getchar();
          }
          putchar(grey);
	      x=getchar();
          while (isspace(x)){
          	x=getchar();
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
             	printf("\nInput error : Couldn't read max'");
                return -1;
	         }
    	     x =getchar();
        }
        if (max==0 || max>255){
            printf("Input error : 'Couldn't read max'");
         	return -1;
		}
        printf("%d",max);//only one white space character after max for binary coded pictures--so no whitespace function needed
        putchar(x);
        red=getchar();
        green=getchar();
	    blue=getchar();
	    while ((red!=EOF)){ //every time ,3 bytes are read, so the one that would contain EOF will be the first one ->red
             printf("%d",red);putchar(' '); printf("%d",green); putchar(' ');printf("%d",blue);putchar(' ');
             red=getchar(); green=getchar();blue=getchar();
	    }
	    break;
	case '5':
		 max=0;
	 	 while (isspace(x)==0){
		     if (x >= '0' && x <= '9'){
                max=max*10+(x-'0');
             }
             else{
             	printf("\nInput error : Couldn't read max'");
                return -1;
	         }
    	     x =getchar();
         }
         if (max==0 || max>255){
            printf("Input error : 'Couldn't read max'");
         	return -1;
		 }
         printf("%d",max);
         putchar(x);
         grey=getchar();
		 while (grey!=EOF){ 
                printf("%d",grey);
				putchar(' ');
                grey=getchar();  
	     }
	             break;
                   
   }
 }
}
