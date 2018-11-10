#include <iostream>

using namespace std;

unsigned long djbhash(char *str, int len) {
  unsigned long hash = 5381;
  
  for(int i=0;i<len;i++, str++)
  {
    hash = ((hash << 5) + hash) + (*str);
  }
  
  return hash;
}

void main()
{
}
