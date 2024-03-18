//Normal Method to check Prime
bool checkPrime(int n) {  
    int cnt = 0;  
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            cnt++;
        }
    }
    return cnt == 2;
}
//Optimise one
bool checkPrime(int n) {
    int cnt = 0;
	for(int i = 1; i * i <= n; i++) {
    //for(int i = 1; i <= sqrt(n); i++) { // to calculate sqrt take some time so to avoid we can write "i * i < = n".
        if(n % i == 0) {
            cnt++;
			// to avoid 6 * 6 == 36 came only one time: n = 36,i = 6, (36 / 6 = 6) != 6
            if((n / i) != i) {
                cnt++;
            }   
        }
    }
    return cnt == 2;
}
bool isPrime(int n) {
	if(n < 2) {
		return false;
	}
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}
bool isComposite(int n) {
    if(n == 1) {
        return false;
    }
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return true;
        }
    }
    return false;
}

/*
let understand for n=36 we can write all factor
1 * 36 = 36
2 * 18 = 36
3 * 12 = 36
4 * 09 = 36 
6 * 06 = 36 // after then we repeat the same things, this one is middle one(here we count only one time)
9 * 04 = 36 
12 * 3 = 36
18 * 2 = 36
36 * 1 = 36
*/