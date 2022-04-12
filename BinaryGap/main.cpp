#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

int solution(int N)
{
  string binaryConversion;
  vector<int> counters;
  binaryConversion = std::bitset<16>(N).to_string();
  int counterOne{0};
  int counterZero{0};
  for (size_t i=0; i<binaryConversion.size(); i++)
  {
    if (binaryConversion[i]=='1')
    {
      counterOne++;
      do
      {
        i++;
        if(binaryConversion[i]=='0') counterZero++;
        else if (binaryConversion[i]=='1') counterOne++;
        if ((counterOne==2) && (counterZero!=0))
        {
          counterOne = 0;
          counters.push_back(counterZero);
          counterZero = 0;
          break;
        }
      }while( (counterOne<2) && (i<binaryConversion.size()) );
      i--;
      counterOne = 0;
    }
  }
  auto const maxElementIterator = max_element(counters.begin(), counters.end());
  if ( maxElementIterator != counters.end() )
    return *maxElementIterator;
  else return 0;
}

int main()
{
  int result{0};
  result = solution(9);
  cout << result << endl;
  return 0;
}