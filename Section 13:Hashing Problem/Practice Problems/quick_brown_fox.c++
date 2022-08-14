#include <bits/stdc++.h>
using namespace std;
// Helper Function:
int brownFox(string &str, string words[], int i, int j, unordered_multiset<string> &us, int length)
{
  if (i >= j) 
  {
    return 0;
  }
  else if(us.empty() == 1)
  {
    return 1000000;
  }
  int a = 5000000;
  for (auto z : us)
  {
    // string str1 = words[k];
    string str1 = z;
    int size = str1.length();
    cout<<size<<endl;
    
    string str2 = str.substr(i, i + size);
    
    if ((i+size <= j) and (str2 == str1) )
    {
      cout<<str1<<endl;
      cout<<str2<<endl;
      us.erase(str1);
      a = min(a, brownFox(str, words, i + size, j, us, length));
      us.insert(str1);
    }
  }
  return 1+a;
}
int main(int argc, char const *argv[])
{
  string str = "thequickbrownfoxjumpsoverthehighbridge";
  string words[] = {"the", "fox", "thequickbrownfox", "jumps", "lazy", "lazyfox", "highbridge", "the",
                    "over", "bridge", "high", "tall", "quick", "brown"};
  unordered_multiset<string> us;
  int length = sizeof(words) / sizeof(string);
  cout << length << endl;
  int size = str.size();
  // Iterate string array:
  for (auto x : words)
  {
    us.insert(x);
  }
  // Call;
   cout<<brownFox(str , words , 0,size,us,length)<<endl;
  return 0;
}
