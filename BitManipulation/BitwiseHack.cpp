/*
	XOR Table(^ - symbol) 
	(A)  (B)  (A ^ B)
	 0	  0      0   
	 0	  1      1
	 1    0      1
	 1    0      0
	Xor Properties
	1.) x ^ x = 0
	2.) a ^ 0 = a
	3.) a ^ b = b ^ a
	4>) a ^ b = c then a ^ c = b
	5.) a ^ (b ^ c) = (a ^ b) ^ c = (a ^ c) ^ b 
	
	AND Properties
	1.) if x & y = z,then x & z = z and y & z = z
	
	
	Bitwise leftShift Operator - "<<"
	Bitwise rightShift Operator - ">>"
	
	LeftShift:-> (a << n) = a * (2 ^ n) // adding n bit last side
	a = 5,n = 2 :-> 00000101 apply 2 leftShift (5 << 2) 
	5 << 2 :->  00010100  equal to 20 
	
	RightShift:-> (a >> n) = (a / (2 ^ n))  // removing n bit from back
	a = 5,n = 2 :-> 00000101 apply 2 rightShift 
	5 << 2 :-> 00000001 equal to 1 
	
	Bitwise Not:-> a = 5 = 00101 :-> ~(a) = -6
	if we present in 32 bit format:->
	a = 5;
	5 = 00000000 00000000 00000000 00000101
	~5= 11111111 11111111 11111111 11111010
	here our first digit is 1 then number is negative,to get the answer we have to conver in 2's complement
	Step-1> convert number into 1's complement
	x = 11111111 11111111 11111111 11111010
	after 1's complement
	x = 00000000 00000000 00000000 00000101
	Step-2) for converting 2's complement we add 1 in last
	x = 00000000 00000000 00000000 00000101
								   		 +1
	x =	00000000 00000000 00000000 00000110
	after conerting x into decimal we get 6
	we convert it int 2 complement the we have to add '-' sine
	x = -6 
	Note :-> in computer first bit represetn postive or negative number if: 0 = posotive,1 = negative and
	and computer stored negative number in 2's complement
	
	
	//n = 13 = 1101(1-3,1-2,0-1,1-0 : index right to left)
	
	Q.1) removing last set bit,n = 13 = 1101 after removing  n = 1100 = 12
	Ans - n & (n - 1)
			13 :  1101
		    12 :  1100
	   13 & 12 :  1100
	
	
	Q.2) to extract ith bit of n.  
	Ans -  13 =  1101    // creating the mask:  (1 << i)   //for the ith bit  
		         0100       (1 << 2 = 0100) (1 == 00001 apply leftshift for 2 = 0100)
		(AND)&	 0100   // after performing bitwise AMD operator
	
	
	Q.3) change(0 to 1 not 1 to 0) the ith bit of n.change 1 bit (13 = 1101 -> 1111)
	Ans -	13 = 1101   // creating the maks:  (1 << i)   //for the ith bit
	   (OR)|     0010   // change 1 first (1 == 00001 then 0010)
		         1111  //after performing bitwise OR operator	
	
	
	Q.4) clearning(1 to 0 not 0 to 1) the ith bit clear 2 bit (13 = 1101 -> 1001)
	Ans - 	13 = 1101  // creating the mask:  ~(1 << i)   //for the ith bit
				 1011  // clear 2nd bit (1 == 00001 then (1 << 2) then 0100 then ''~' then 1011)
		(AND)&   1001
	
	
*/
	
/*
//binary to deicmal
ll conversion(ll num){
	ll val = 1,ans = 0;
	while(num) {
        ll last = num % 10;
        num = num / 10;
        ans += last * val;
        val = val * 2;
	}
	return ans;
}	
*/


/*
Binary        Decimal          Binary         Decimal
00001           1              110011            51
00010           2              110100            52
00011           3              110101            53
00100           4              110110            54
00101           5              110111            55
00110           6              111000            56
00111           7              111001            57
01000           8              111010            58
01001           9              111011            59
01010           10             111100            60
01011           11             111101            61
01100           12             111110            62
01101           13             111111            63
01110           14             1000000           64
01111           15             1000001           65
10000           16             1000010           66
10001           17             1000011           67
10010           18             1000100           68
10011           19             1000101           69
10100           20             1000110           70
10101           21             1000111           71
10110           22             1001000           72
10111           23             1001001           73
11000           24             1001010           74
11001           25             1001011           75
11010           26             1001100           76
11011           27             1001101           77
11100           28             1001110           78
11101           29             1001111           79
11110           30             1010000           80
11111           31             1010001           81
100000          32             1010010           82
100001          33             1010011           83
100010          34             1010100           84
100011          35             1010101           85
100100          36             1010110           86
100101          37             1010111           87
100110          38             1011000           88
100111          39             1011001           89
101000          40             1011010           90
101001          41             1011011           91
101010          42             1011100           92
101011          43             1011101           93
101100          44             1011110           94
101101          45             1011111           95
101110          46             1100000           96
101111          47             1100001           97
110000          48             1100010           98
110001          49             1100011           99
110010          50             1100100           100
*/