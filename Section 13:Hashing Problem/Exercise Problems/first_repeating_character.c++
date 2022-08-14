#include<bits/stdc++.h>
using namespace std;


char firstRepeatChar(string input){
  unordered_set<char> ust;
  //Iterate the whole string
  int length = input.size();
  for(int i=0;i<length;i++)
  {
      if(ust.find(input[i]) != ust.end())
      {
          return input[i];
      }
      ust.insert(input[i]);
  }  
  return '\0';
    
    
}