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

Only works for linux systems

```
q)d)1+til 10000000
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29..
time                 | 65
mem                  | 268435952
cpudiff              | 209478571
rchar                | 658
wchar                | 80
syscr                | 4
syscw                | 1
read_bytes           | 0
write_bytes          | 0
cancelled_write_bytes| 0
utime                | 3
stime                | 2
cutime               | 0
cstime               | 0
starttime            | 0
```
