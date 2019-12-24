# statsQ
Mini Stats Language in Q to track Unix Stats


`Note that this runs on .z.K (3.6) with .z.k (2019.06.09), which means .Q.ts provides both output as well as time/mem stats rather than just time/mem stats only for .z.K (3.6) with .z.k (2018.06.14)`


__Compilation of readPid.cpp is__:

`g++ -shared -fPIC -fexceptions readPid.cpp -o $QHOME/libso/readPid.so`

__Compilation of cpu.c is__: 
(From https://code.kx.com/v2/interfaces/using-c-functions/)

`cc -I. -fPIC -shared -o ~/q/libso/cpu.so cpu.c`


### Instructions:

Place the following files under QHOME directory:
1) `Entire libso directory`
2) `d.k`
3) `d.q` 


### Typical Outputs:

Only works for Unix-based systems

```
q)d)([]a:til 10)
output               | +(,`a)!,0 1 2 3 4 5 6 7 8 9
time                 | 0
mem                  | 1184
cpudiff              | 810699
rchar                | 129
wchar                | 0
syscr                | 3
syscw                | 0
read_bytes           | 0
write_bytes          | 0
cancelled_write_bytes| 0
utime                | 0
stime                | 0
cutime               | 0
cstime               | 0
starttime            | 0
VmSize               | 0
VmRSS                | 0
RssFileRssShmem      | 0
```
`Note:` There's a base of 129 rchar which "seems to be present" due to the implicit cost of running the set of codes above
