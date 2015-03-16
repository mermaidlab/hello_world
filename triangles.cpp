/*
 * CSc103 Project 4: Triangles
 * Author: Ariel Gemran agerman000@citymail.cuny.edu
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 * http://en.wikipedia.org/wiki/Special_right_triangles
 * http://www.cplusplus.com/reference/algorithm/sort/
 * http://www.cplusplus.com/reference/vector/vector/vector/
 * http://www.cplusplus.com/articles/NhA0RXSz/
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 5
 */

#include "triangles.h" // import the prototypes for our triangle class.
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

// note the "triangle::" part.  We need to specify the function's
// FULL name to avoid confusion.  Else, the compiler will think we
// are just defining a new function called "perimeter"
unsigned long triangle::perimeter() {
	return s1+s2+s3;
}

unsigned long triangle::area() {
	const int triSize = 3;
	int t1Sides[triSize]= {s1,s2,s3};
	sort(t1Sides,t1Sides+triSize);
	
	
	return (t1Sides[0]*t1Sides[1])/2;
}

void triangle::print() {
	cout << "[" << s1 << "," << s2 << "," << s3 << "]";
}

bool congruent(triangle t1, triangle t2) {
	bool isCongruent = false;
	const int triSize = 3;
	int t1Sides[triSize]= {t1.s1,t1.s2,t1.s3};
	int t2Sides[triSize]= {t2.s1,t2.s2,t2.s3};
	sort(t1Sides,t1Sides+triSize);
	sort(t2Sides,t2Sides+triSize);

	//SSS
	if (t1Sides[0]==t2Sides[0] &&t1Sides[1]==t2Sides[1] &&t1Sides[2]==t2Sides[2])
		isCongruent = true;
	

	return isCongruent;
}

bool similar(triangle t1, triangle t2) {
	bool isSimilar =  false;
	const int triSize = 3;
	int t1Sides[triSize]= {t1.s1,t1.s2,t1.s3};
	int t2Sides[triSize]= {t2.s1,t2.s2,t2.s3};
	sort(t1Sides,t1Sides+triSize);
	sort(t2Sides,t2Sides+triSize);

	if((double)t1Sides[0]/t2Sides[0]==(double)t1Sides[1]/t2Sides[1]
		&&(double)t1Sides[0]/t2Sides[0]==(double)t1Sides[2]/t2Sides[2])
	{
		isSimilar=true;
	}
	
	return isSimilar;
}


vector<triangle> findRightTriangles(unsigned long l, unsigned long h) {
	// TODO: find all the right triangles with integer sides,
	// subject to the perimeter bigger than l and less than h
	vector<triangle> retval; // storage for return value.

	int perimeters;
	
	for (int a = 1; a <= h; ++a)
	{
		for (int b = 1; b <= h; ++b)
		{
			for (int c = 1; c <= h; ++c)
			{
				perimeters= a+b+c;
				if(perimeters>=l &&perimeters<=h){
					int hyp = (a*a)+(b*b);
					if((c*c)==hyp){
						triangle t(a,b,c);
						bool found = false;
						for (int i = 0; i < retval.size(); ++i)
						{
							if(congruent(retval[i],t)){
								found = true;

							}
						}
						if(!found){
							retval.push_back(t);
						}
						
					}
				}
					
			}
		}
		
	}
	
	return retval;
}

