# debugQ
Creation of Mini-Language

__Compilation of readPID.cpp is__:

`g++ -shared -fPIC -fexceptions readPID.cpp -o $QHOME/libso/readPID.so`

__Compilation of cpu.c is__: 
(From https://code.kx.com/v2/interfaces/using-c-functions/)

`cc -I. -fPIC -shared -o ~/q/libso/cpu.so cpu.c`


## Instructions:

Place the following files under QHOME directory:
1) `Entire libso directory`
2) `d.k`
3) `d.q` 
