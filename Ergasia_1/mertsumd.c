#include <stdio.h>
#define MAXEXP 8


int main()
{
    int i,y,factor,mobius,x1,i1,n,term;
    int zeropoints = 0;
    int x = 1;
    int count = 0;
    for (i=1;i<=MAXEXP;i++){
/*calculating x^MAXEXP*/
       x = x * 10;
    }
    int  mertens = 0;
    for(y = 1;y <= x+9; y++ ){
             if (y % 4 == 0 ||y % 9 == 0){
/*multiples of 4 and 9 do not have to be checked later for if they are EP numbers ,while (4=2^2)or (9=3^2) divide them*/
                /* mobius=0;
                mertens=mertens+ mobius;*/
/*mertens remains the same with the previous one while mobius is zero*/
                x1 = 1;
                count++;
                for (i1 = 1; i1 <= MAXEXP; i1++ ){
/*duo to [continue] we have to check if mertens value has to be printed now*/
                    x1 = x1 * 10;
                    if((count >= x1 - 9)&&(count <= x1 + 9)){
                        printf("M(%d) = %d \n",count,mertens);
                    }
                    if((count == x1 - 10)&&(count >= 90)){
                        printf(".......... \n");
                    }
                }
                if (mertens == 0){
                   zeropoints++;
                }
                continue;
//continue with the next value of y, since this value has got a divisor which is perfect square(mobius=0)
             }
             int temp=y;
             int primefactors=0;
             if (temp % 2 == 0){
/*since y isn't divided with 2 or 3 two times(because if this had happened the loop wouldn't have been continued duo to [continue]�command) we can divide our number with 2 or/and 3*/
                temp /= 2;
                primefactors++;
             }
             if (temp % 3 == 0){
                temp /= 3;
                primefactors++;
             }
             factor = 5;
             int ep = 0;
             while(factor * factor <= temp){
/*checking for factors until number's root */
                if (temp % factor == 0){
                   temp /= factor;
                   primefactors++;
                   if (temp % factor == 0){
                       ep = 1;
/*if the same prime factor divides our number two times ,the number is not EP*/
                       break;
                   }
                }
                if(factor % 6 == 5){
/*increasing possible factor's value based on a motive => If possible factor divided by 6 gives remainder 5, factor should be increased by 2 */
                   factor += 2;
                }
                else{
/*otherwise factor should be increased by 4 */
                   factor += 4;
                }
             }
            if(temp != 1){
              primefactors++;
/*if our number is not 1 we have to add the last prime factor*/
            }
            if ((ep == 0 )&&( primefactors % 2 == 0)){
               mobius = 1;
               mertens = mertens + mobius;
            }
            else if((ep == 0) && (primefactors % 2 == 1)){
               mobius = -1;
               mertens = mertens + mobius;
            }
            count ++;
            x1 = 1;
            for (i1 = 1 ;i1 <= MAXEXP; i1++ ){
               x1*=10;
               if((count >= x1 - 9) && (count <= x1 + 9)){
/*printing mertens value if it is involved in [10^x-9,10^x+9] for every x in [1, MAXEXP]*/
                   printf("M(%d) = %d \n",count,mertens);
               }
/*if mertens value is just the previous from the first printing value every time,print[.....](exept for first time*/
               if((count == x1 - 10)&&(count >= 90)){
                    printf(".......... \n");
               }
           }
           if (mertens == 0){
               zeropoints++;
           }
    }
    printf("\n");
    printf("Found %d zero points of the Mertens function\n",zeropoints);
    printf("\n");
    printf("Checking numbers in the range [2,%d]\n",1000*zeropoints);
    printf("\n");
    int countdef = 0;
    int countabu = 0;
    for(n = 2;n <= 1000 * zeropoints;n ++){
       int sum = 1;
       int temp = n;
       factor = 2;
       while(factor * factor <= temp){
           term = 1;
           while (temp % factor == 0){
              term = factor * term + 1;
              temp/=factor;
           }
/*the sum of all divisor of a number,including itself (n=temp) equals to [(1 + p1 + p1^2 + ... + p1^e1)*(1 + p2 + p2^2 + ... + p2^e2 )*(1 + pk + pk^2 + ... + pk^k2 )] where p1,p2..pk are
the  prime factors of our number and e1,e2,ek is the exponents of prime factors e.g for number 12 p1 is 2 with exponent e1=2 and p2=3 with e2=1 (2^2*3=12).So the previous type becomes
[(1+2+2^2) *(1+3)]=7*43=28.
This equals to the sum of ALL divisors of 12,including itself (1+2+3+4+6+12=28)
So rather than calculating the sum of every divisor we can use the previous type, decreasing dramatically the execution time*/
           sum*=term;
           if (factor == 2){
              factor = 3;
           }
           else if(factor == 3){
/*the next possible prime factor is 5*/
              factor = 5;
           }
           else if(factor % 6 == 5){
              factor += 2;
           }
           else{
              factor += 4;
/*the same with the upper motive*/
           }
       }
       if(temp != 1){
          sum *= (1 + temp);
       }
       if(sum == 2 * n){
/*into sum is included the number n so we multiply n by 2 so as to exclude n from sum (sum = 2 *n)<=>(sum -n = n)*/
          printf("Found perfect number: %d\n",n);
       }
       else if(sum < 2 * n){
          countdef++;
       }
       else{
          countabu++;
       }
    }
    printf("\n");
    printf("Found %d deficient numbers\n",countdef);
    printf("Found %d abundant numbers\n",countabu);
    return 0;
}
