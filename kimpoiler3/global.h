#ifndef GLOBAL_H
#define GLOBAL_H

extern bool errorFlag = false;
extern int banyakKalimat = 0;
extern std::string kalimat[999];
extern int kolomKalimat[999];
extern int kalimatLength = (sizeof(kalimat)/sizeof(*kalimat));
extern bool debugMode = false;

//Contoh : a:=5+3;b:=(print(a,a-1),10*a);print(b);
extern std::string inputLine = "a:=5+3;b:=(print(a,5-1),10*3);print(b)";
#endif // GLOBAL_H

#include <string>
