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

extern "C" 

// Temporary implementation of /proc/pid/stats, which returns a list of strings  
K readPidStat(K pid, K sI, K eI)
{
    J length, i; 
    std::string line; // Standard definition of variables
    
    if((pid->t!=-KI) || (sI->t!=-KJ) || (eI->t!=-KJ)) {return krr((S) "type");}; 
    if(eI->j >= sI->j) {length = 1 + eI->j - sI->j;} else {return krr((S) "Ending Index must be larger than Starting Index");}; 
    K v = ktn(0, length);

    std::ifstream reader("/proc/" + std::to_string(pid -> i) + "/stat");
    if(!reader) {return krr((S) "Error opening file for output");}
    for (i=1; (!reader.eof()); i++)
    {
    getline(reader,line,' ');
    if(i >= sI->j) {kK(v)[i - sI->j] = kp((S) line.c_str()); if(i == eI->j){break;};}
    }
    reader.close();
    return v;
};

