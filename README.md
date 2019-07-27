# debugQ
Creation of Mini-Language

__Compilation of readPID.cpp is__:

`g++ -shared -fPIC -fexceptions readPID.cpp -o $QHOME/libso/readPID.so`

__Compilation of cpu.c is__: 
(From https://code.kx.com/v2/interfaces/using-c-functions/)

`cc -I. -fPIC -shared -o ~/q/libso/cpu.so cpu.c`


### Instructions:

Place the following files under QHOME directory:
1) `Entire libso directory`
2) `d.k`
3) `d.q` 


### Typical Outputs:

`
q)d)1+10000000
10000001
time                 | 0
mem                  | 1072
cpudiff              | 1236544
rchar                | 672
wchar                | 9
syscr                | 4
syscw                | 1
read_bytes           | 0
write_bytes          | 0
cancelled_write_bytes| 0
utime                | 0
stime                | 0
cutime               | 0
cstime               | 0
starttime            | 0
`
