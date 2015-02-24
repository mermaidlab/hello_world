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
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 1hr
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <set>
using std::set;
using std::basic_string;
// write this function to help you out with the computation.
unsigned long countWords(const string& s, set<string>& wl);

int main()
{
	string x;
	set<string> s;
	long words = 0;
	while(cin>>x)
	{
	getline(cin,x);
	words += countWords(x,s);

	}

	cout << "Count is : " << words << endl;
	return 0;
}

unsigned long countWords(const string s, set<string>& wl){
	string word="";
	basic_string<char> line = s;
	for(int i = 0;i < s.size();i++){
		if(line[i] != " " || line[i] != "\n"|| line[i]!= "."){
			word += line[i];
		}else{
			word =  "";
		}
	}
	wl.insert(x);
	return wl.size();
}

