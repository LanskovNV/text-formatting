#pragma once
#ifndef TEXT_AL_H
#define TEXT_AL_H
/* leins, 13.03.2018 */
#include <string>
#include <vector>

using namespace std;

/* functions */
vector<string> Alignment(int strLen, string fileName);
void Output(string fileName, vector<string> strings, int strLen);
#endif // TEXT_AL_H
