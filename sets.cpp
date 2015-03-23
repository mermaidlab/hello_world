// working with sets and maps.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <set> /* <-- new stuff. */
using std::set;
#include <string>
using std::string;
#include <cstdio>
#include<vector>
using std::vector;
void setTest() {
	/* set is a template, just like the vector: */
	set<int> s;
	/* add stuff to set: */
	for (size_t i = 0; i < 10; i++) {
		/* insert stuff into a set: */
		s.insert(i*i*i);
	}
	/* now check for membership in s: */
	int x;
	while (cin >> x) {
		// if (s.find(x) != s.end()) {
		if (s.find(x) != s.end()) {
			cout << x << " is a cube less than 1000.\n";
		} else {
			cout << x << " is not a cube less than 1000.\n";
		}
	}
}

set<int> intersect(set<int> s1, set<int> s2) {
	set<int> I;
	if(s1.size()<=s2.size()){
	for(set<int>::iterator x = s1.begin(); x != s1.end(); x++) {
		/* NOTE: *x is the element of the set.  Will explain later... */
		/* so, we search for *x in s2: */
		if (s2.find(*x) != s2.end()) {
			I.insert(*x);
		}
	}
	}else{
	
		for(set<int>::iterator x = s2.begin(); x != s2.end(); x++) {
			/* NOTE: *x is the element of the set.  Will explain later... */
			/* so, we search for *x in s2: */
			if (s1.find(*x) != s1.end()) {
				I.insert(*x);
			}
		}
	}
	return I;
	/* TODO: assuming that the size() function of the set takes
	 * a (small) constant amount of time, make this go faster
	 * by iterating through the contents of the smaller set, rather
	 * than always going through s1.
	 * ##DONE
	 * TODO: also do the math to see why this would be faster, and
	 * note that in the corresponding problem for vectors, it
	 * wouldn't make any difference. */
}

/* TODO: write a function that returns the union of two sets */
//##DONE
vector<int> union(const set<int>& s1,const set<int>& s2){
	set<int>s3;
	//enter the first set
	for(set<int>::iterator x = s1.begin(); x != s1.end(); x++) {
			if (s1.find(*x) != s1.end()) {
				s3.insert(*x);
			}
	}
	//enter the second set
	for(set<int>::iterator x = s2.begin(); x != s2.end(); x++) {
			if (s2.find(*x) != s2.end()) {
				s3.insert(*x);
			}
	}

	return s3;
}
/* TODO: emulate the insert function for the set, but for a vector.
 * That is, write a function that takes a vector (say of integers)
 * and a single integer x, and adds x to the vector *only if it was
 * not already present*. You can return a boolean indicating whether
 * or not x insertion took place. */
//#DONE
bool insert(vector<int>& v,int x){
	bool inserted = false;
	bool found = false;
	for(int i =0 ; i < v.size();i++){
		if(v[i]==x){
			found = true;
			break;
		}
	}
	if(!found){
		v.push_back(x);
		inserted = true;
	}
	return inserted;
}
/* TODO: write a function that removes a value from a vector if it
 * is present.  It should take a vector and a value x, and remove
 * x if it is in the vector. NOTE: you don't have to preserve the
 * order of the other elements. */
//##DONE
bool remove(vector<int> v , int x){
	bool found  = false;
	for(int i =0 ; i < v.size();i++){
		if(v[i]==x){
			found = true;
			v.erase(i);
			break;
		}
	}
	return found;
}

int main(void)
{
	setTest();
	/* TODO: write test code for the other exercises. */
	return 0;
}
