#include <string>
#include <iostream>
#include <cmath>
using namespace std;

// returns count of non-overlapping occurrences of 'sub' in 'str'
int countSubstring(const string& str, const string& sub)
{
	if (sub.length() == 0) return 0;
	int count = 0;
	for (int offset = str.find(sub); offset != string::npos; 
		offset = str.find(sub, offset + sub.length()))
	{
		++count;
	}
	return count;
}

int wordCount(const string& str)
{
	return countSubstring(str, " ");
}

int uniqueWords(const string& str){
  string allWords="";
  int count=0;
  for(int i=0;i<=str.length();i++){
    if(str[i]!='.'&&str[i]!=','){
      allWords=allWords+str[i];
    }
    if(str[i]==' '){
      if(str.substr(0,i-allWords.length()+1).find(allWords)==string::npos){
        count++;
      }
      allWords="";
    }
    
  }
  
  
  return count;
}

int numSentences(const string& str)
{
	return countSubstring(str, ".");
  
  //return wordCount(str)/countSubstring(str, ".");
}

double lexDensity(const string& str){
  int unique=uniqueWords(str);
  int count=wordCount(str);
  return round(((double)unique/(double)count)*100);
}

int main()
{


	//. . .;

   string source = ("I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo. I got the ramblin fever. Said goodbye to ma and pa. Crossed that ol red river and this is what I saw. I saw miles and miles of Texas 1000 stars up in the sky. I saw miles and miles of Texas gonna live here till I die.");


	cout << "substring count: " << countSubstring(source, "is")        << '\n';

  cout << "word count: " << wordCount(source)        << '\n';

  //cout << "sentence count: " << numSentences(source) << '\n';
	// . . .;

  cout<< "Unique word count: " << uniqueWords(source) << '\n';

  cout<< "Lexical density: " << lexDensity(source) << "%" << '\n';
	return 0;
}
