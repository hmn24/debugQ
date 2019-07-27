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

extern "C" 

// Temporary implementation of /proc/pid/stats, which returns a list of strings
// This assumes strings come in ascending format which would be handle on the q level
K readPidStat(K pid, K list)
{
    J i, ind = 0; 
    std::string line; // Standard definition of variables

    if((pid->t!=-KI) || (list->t!=KJ)) {return krr((S) "type");}; 
    if(0 == list->n) {return krr((S) "Must provide at least one number");}; 
    K v = ktn(0, list->n);

    J eI = kJ(list)[list->n - 1];
    std::ifstream reader("/proc/" + std::to_string(pid -> i) + "/stat");
    if(!reader) {return krr((S) "Error opening file for output");}
    for (i=1; !reader.eof(); i++)
    {
    getline(reader,line,' ');
    if(i <= eI) {if(i==kJ(list)[ind]){kK(v)[ind] = kp((S) line.c_str()); ind++;};} else {break;}
    }
    if(0 <= (list->n)-ind-1){for(ind;ind<list->n;ind++){kK(v)[ind] = kp((S)" ");};}; // Create null values for empty ind
    reader.close();

    return v;
};

// Not necessary here but to create an exception in C++
// try {} catch (std::exception &e) {krr((S) e.what());};

