#include <iostream>
#include <fstream>
#include <string>
#define KXVER 3
#include "k.h"


extern "C" {

// Read PI IO function
K readPidFile(K pid, K file){
    K k,v; 
    J i, ival;
    std::string line; 

    P(file->t!=-KS || pid->t!=-KI, krr((S)"type"));
    k = ktn(KS, 0); 
    v = ktn(KJ, 0);
    std::ifstream reader("/proc/" + std::to_string(pid->i) + "/" + std::string(file->s));
    P(!reader, krr((S)"Error opening file for output"));
    for (i=0; !reader.eof(); i++)
    {
        getline(reader,line,':');
        if(line.length()){js(&k, ss((S)line.c_str()));} 
        getline(reader,line,'\n'); 
        if(line.length()){ival = std::stoi(line); ja(&v, &ival);}
    };
    reader.close();

    return xD(k,v);
 }  

// Temporary implementation of /proc/pid/stats, which returns a list of strings
// This assumes strings come in ascending format which would be handle on the q level, and doesn't have 0 in its list
K readPidStat(K pid, K file, K list){
    J i, ind = 0; 
    std::string line; // Standard definition of variables

    P(file->t!=-KS || pid->t!=-KI || list->t!=KJ, krr((S)"type")); 
    P(0==list->n, krr((S)"Must provide at least one number"));
    J len = list->n, eI = kJ(list)[len-1];
    K v = ktn(0,len);

    std::ifstream reader("/proc/" + std::to_string(pid->i) + "/" + std::string(file->s));
    P(!reader, krr((S)"Error opening file for output"));
    for (i=1; !reader.eof(); i++)
    {
    getline(reader,line,' ');
    if(i<=eI) {if(i==kJ(list)[ind]){kK(v)[ind]=kp((S)line.c_str());ind++;};} else {break;}
    }
    if(1<=len-ind){DO(len-ind,kK(v)[ind+i]=kp((S)" "));}; // Create null values for empty ind
    reader.close();

    return v;
 }

}
