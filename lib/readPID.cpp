#include <iostream>
#include <fstream>
#include <string>
#define KXVER 3
#include "k.h"
extern "C"

// Can't use "using namespace std" for the dll to q/kdb+
// Read PI IO function
K readPidFile(K pid, K file)
{
    K k,v; 
    J i, ival;
    std::string line; 

    if((file->t!=-KS) || (pid->t!=-KI)) {return krr((S) "type");};
    k = ktn(KS, 0); 
    v = ktn(KJ, 0);
    std::ifstream reader("/proc/" + std::to_string(pid -> i) + "/" + std::string(file -> s));
    if(!reader) {return krr((S) "Error opening file for output");}
    for (i=0; !reader.eof(); i++)
    {
        getline(reader,line,':');
        if(line.length()){js(&k, ss((S) line.c_str()));} 
        getline(reader,line,'\n'); 
        if(line.length()){ival = std::stoi(line); ja(&v, &ival);}
    };
    reader.close();

    return xD(k,v);
};  


