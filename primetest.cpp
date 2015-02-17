/*
 * CSc103 Project 2: prime numbers.
 * Author: Ariel German agerman000@citymail.cuny.edu
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 * Googled the sqrt hint and it led me to this forum.
 * http://stackoverflow.com/questions/5811151/why-do-we-check-upto-the-square-root-of-a-prime-number-to-determine-if-it-is-pri
 */

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;


/* Accepts input from user and if primes returns 1. If even returns 0.*/
int main()
{
	unsigned long x = 0; // Entry
	

	while(cin >> x){
		int factors = 0; // Number of factors
		//Base cases
		if(x == 1){
			cout << 0 << endl;
		}
		else if(x == 2){
			cout << 1 << endl;
		}
		// Return 0 if even
		else if(x %2 == 0){
			cout  << 0 << endl;
		}
		// Check if prime
		else{
			/* Iterates through the numbers up to the sqrt(x) since
			 * if there is anything that devides x , it should be found
			 * before reaching sqrt(x)
			 */
			double s = sqrt(x);
			for(int i = 1; i <= s ; i+=2 ){
				if(x % i == 0){
					++factors; // Should only go up to 2
					if (factors >2){
						break;
					}
				}
			}
			/* Because it doesn't count up to X there should be only one factor*/
			if(factors == 1){ 
				cout << 1 << endl;
			}else{
				cout << 0 << endl;
			}
		}
	}
	return 0;
}
