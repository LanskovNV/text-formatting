/* leins, 27.02.2018 */
#include <iostream>
#include <string>
#include "text_al.h"

using namespace std;

int main()
{
  int length;
  string fileName = "input.txt";
 
  // user interface
  cout << "input string length (not less than 1):" << endl;
  cin >> length;

  // align text and output
  if (length > 0)
    Output("output.txt", Alignment(length, fileName), length);
  else
    cout << "length should be > 0" << endl;

  //system("pause");
  return 0;
} /* end of main */
