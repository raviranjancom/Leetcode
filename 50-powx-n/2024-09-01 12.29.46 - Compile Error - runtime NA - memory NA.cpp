double pow = 1;
while(n != 0){
	if((n & 1) != 0) // equivalent to if((n % 2) != 0) i.e. multiply only when the number is odd  
    	pow *= x;

        	x *= x;
            	n >>>= 1; // equivalent to n = n / 2; i.e. keep dividing the number by 2

                }


        

