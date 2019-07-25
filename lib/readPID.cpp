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
    J i, lines;
    std::string line; 
    try 
    {
        if((file->t!=-KS) || (pid->t!=-KJ) || (kLines->t!=-KJ)) {krr((S) "type");};
        lines = kLines -> j;
        k = ktn(KS, lines); 
        v = ktn(KJ, lines);
        std::ifstream reader("/proc/" + std::to_string(pid -> j) + "/" + std::string(file -> s));
        for (i=0; i < lines; i++)
        {
        getline(reader,line,':'); kS(k)[i] = ss((S) line.c_str());
        getline(reader,line,'\n'); kJ(v)[i] = (J) std::stoi(line);
        };
        reader.close();
    }
    catch (std::exception &e) {krr((S) e.what());}
    return xD(k,v);
};  


