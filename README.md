# debugQ
Creation of Mini-Language

__Compilation of readPID.cpp is__:

`g++ -shared -fPIC -fexceptions readPID.cpp -o $QHOME/l64/readPID.so`

__Compilation of cpu.c is__: 
(From https://code.kx.com/v2/interfaces/using-c-functions/)

`cc -I. -fPIC -shared -o ~/q/l64/cpu.so cpu.c`


## Instructions:

Place the following files under QHOME directory:
1) libso directory
2) d.k
3) d.q 
