/*
 * CSc103 Project 5: Syntax highlighting, part one.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 
 */

#include "fsm.h"
using namespace cppfsm;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// make sure this function returns the old state.  See the header
// file for details.
int cppfsm::updateState(int& state, char c) {
	//Implement a switch for handling each state that is passed in
	// then depending on that state i will take the neccesary action
	const int prevState =  state;//this will save the previous state

	//there are 8 cases
	switch(state){
		case start:
			if(INSET(c,iddelim)){
				state = start;
				break;
			}else if(c=='"'){
				state = strlit;
				break;
			}else if(INSET(c,ident_st)){
				state = 1;
				break;
			}else if(INSET(c,num)){
				state = scannum;
				break;
			}
		case scanid:
			if(INSET(c,iddelim)){
				state = start;
				break;
			}else if(INSET(c,ident)){
				state = scanid;
				break;
			}else if(c=='/'){
				state  = readfs;
				break;
			}
		case comment:
			state = comment;//state does not change?
			break;
		case strlit:
			if(c=='\"'){
				state = start;
				break;
			}else if(c=='\\'){
				state = readesc;
				break;
			
			}else{
				state  = strlit;
				break;
			}
		case readfs:
			if(INSET(c,ident_st)){
				state = scanid;
				break;
			}else if(c=='\"'){
				state = strlit;
				break;
			}else if(c=='/'){
				state = comment;
				break;
			}else if(INSET(c,num)){
				state = scannum;
				break;
			}
		case readesc:
			if(INSET(c,escseq)){
				state =  strlit;
				break;
			}else{
				state = error;
				break;
			}
		case scannum:
			if(c=='/'){
				state = readfs;
				break;
			}else if(INSET(c,iddelim)){
				state =  start;
				break;
			}else if(INSET(c,num)){
				state =  scannum;
				break;
			}
		case error:
			state = error;
			break;
	}

	return prevState;//return the previous state;
}

