/*
 * CSc103 Project 3: wordcount++
 * Author: Ariel German agerman000@citymail.cuny.edu
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 * http://www.cplusplus.com/reference/set/set/
 * http://www.cplusplus.com/reference/cctype/isspace/
 *
 * Finally, please indicate approlineimately how many hours you spent on this:
 * #hours: 3hr
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <set>
using std::set;
using std :: iterator;

// write this function to help you out with the computation.
unsigned long countWords(const string& s, set<string>& wl);
//Helps print the set out for debugging
int printSet(set<string>& words);


int main()
{	
	//Set up what I need to store for later
	string currentLine;
	set<string> uniqueLinesSet; 
	set<string> uniqueWordSet;
	long lineCount = 0;
	long wordCount = 0;
	long charCount = 0;
	long uniqueLineCount = 0;
	

	while(getline(cin ,currentLine)){
		charCount++;// account for new line char
		lineCount++;// account for new line received
		wordCount += countWords(currentLine, uniqueWordSet);//track words
		charCount += currentLine.size();//track characters
		uniqueLinesSet.insert(currentLine);//track unique lines
	}
	
	//Print out the formated count
	cout<< "\t" << lineCount << "\t"<< wordCount<< "\t"
		<< charCount<< "\t"<< uniqueLinesSet.size()
			<< "\t"<< uniqueWordSet.size()<< endl;

	return 0;
}

unsigned long countWords(const string& s, set<string>& wl){
	string temp = "";
	int count = 0;
	//Check each character
	for (int i = 0; i < s.size(); ++i)
	{
		if(isspace(s[i]))//if you find space
		{
			if(temp!="")//and temp has a word
			{
				wl.insert(temp);//add the word
				count++;
				temp = "";//reset the word
			}	
		}else
		{
			temp += s[i];//else continue adding to word
		}
	}
	//If we have something left in temp just add it
	if(temp != "")
	{
		wl.insert(temp);
		temp = "";
		count++;
	}
	return count;// returns words counted
}

int printSet(set<string>& words)
{
	for (set<string>::iterator i = words.begin(); i!=words.end(); i++) 
	{
    	cout << *i << endl;
	}
	cout << "Size: " << words.size() << endl;
	return 0;
}







