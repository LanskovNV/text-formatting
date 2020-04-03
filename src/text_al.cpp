/* leins, 13.03.2018 */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "text_al.h"

using namespace std;

string AddSpaces(string s, int size)
{
  int strLen = s.size();
  int numOfSpaces = size - strLen;

  if (numOfSpaces != -1)
  {
    if (numOfSpaces % 2 == 0 && numOfSpaces != 0)
      numOfSpaces -= 1;
    if (numOfSpaces != 0)
    {
      numOfSpaces /= 2;
      s.insert(s.begin(), numOfSpaces + 1, ' ');
      s.insert(s.end(), numOfSpaces, ' ');
    }
  }
  if (numOfSpaces == -1)
    s.pop_back();
  return s;
} // end of function

void Output(string fileName, vector<string> strings, int strLen)
{
  fstream f;

  f.open(fileName, ios::out | ios::trunc);
  if (!f.is_open())
  {
    cout << "cannot open output file" << endl;
  }
  else
  {
    vector<string>::iterator iter;
    for (iter = strings.begin(); iter != strings.end(); iter++)
        f << AddSpaces(*iter, strLen) << endl;
    f.close();
  }

} // end of function

vector<string> Alignment(int strLen, string fileName)
{
  fstream f;
  string buffer, sToOut;
  vector<string> strings;

  f.open(fileName);
  if (!f.is_open())
  {
    cout << "cannot open input file" << endl;
  }
  else
  {
    while (!f.eof())
    {
	  int strSize = sToOut.size();
	  int bufSize = buffer.size();

	  if (bufSize == 0)
	  {
		f >> buffer;
		bufSize = buffer.size();
	  }

	  if (bufSize + strSize > strLen)
	  {
		if (strSize == 0)
		{
		  sToOut += buffer.substr(0, strLen - strSize);
		  buffer = buffer.substr(strLen - strSize);
		}
		strings.push_back(sToOut);
		sToOut = "";
	  }
	  else if (bufSize + strSize == strLen)
	  {
		sToOut += buffer;
		buffer = "";
		strings.push_back(sToOut);
		sToOut = "";
	  }
	  else 
	  {
		sToOut += buffer;
		sToOut += " ";
		buffer = "";
	  }
    }
    if (sToOut.size() != 0)
      strings.push_back(AddSpaces(sToOut, strLen));
    f.close();
  }
  return strings;
} // end of function
