#include <iostream>
#include <fstream>
#include <string>
#define KXVER 3
#include "k.h"
extern "C"

// Read PI IO function
K readPidFile(K pid, K file, K kLines)
{
    K k,v; 
    J i, lines, ival;
    std::string line; 

    if((file->t!=-KS) || (pid->t!=-KJ) || (kLines->t!=-KJ)) {return krr((S) "type");};
    lines = kLines -> j;
    k = ktn(KS, 0); 
    v = ktn(KJ, 0);
    std::ifstream reader("/proc/" + std::to_string(pid -> j) + "/" + std::string(file -> s));
    if(!reader) {return krr((S) "Error opening file for output");}
    for (i=0; (i < lines) && !reader.eof(); i++)
    {
        getline(reader,line,':');
        if(line.length()){js(&k, ss((S) line.c_str()));} 
        getline(reader,line,'\n'); 
        if(line.length()){ival = std::stoi(line); ja(&v, &ival);}
    };
    reader.close();

    return xD(k,v);
};  
