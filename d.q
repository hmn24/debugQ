\d .d

// Using code.kx https://github.com/KxSystems/cookbook/tree/master/cpu_extension
/ To compute differences in cpu cycles
read_cycles: hsym[`$ getenv[`QHOME], "/libso/cpu"] 2: (`q_read_cycles_of_this_cpu;1);

// To compute differences in proc/pid/io
read_io: hsym[`$ getenv[`QHOME], "/libso/readPid"] 2: (`readPidFile;2);

// To compute differences in proc/pid/stat
/ Note that the read_stat takes in strictly an ascending order list, so ascending is best applied before using it
read_stat: hsym[`$ getenv[`QHOME], "/libso/readPid"] 2: (`readPidStat;3);

// Define function for cpu stats for specific pid
/ https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat
cpuStats: {
    `utime`stime`cutime`cstime`starttime!raze "J"$ read_stat[x; `stat; 14 15 16 17 22]
 };

memStats: {
    `VmSize`VmRSS`RssFileRssShmem!raze "J"$ read_stat[x; `statm; 1 2 3]
 };

// Define the function that measures time and memory stats
mStats: {
    s_cpu:read_cycles[]; 
    s_cpu_stat: cpuStats[.z.i]; 
    s_io: read_io[.z.i;`io]; 
    s_memStats: memStats[.z.i]; 
    op: .Q.ts[value; enlist x];
    end_io: read_io[.z.i;`io] - s_io;
    (enlist[`output]!enlist last op), @[`time`mem!first op; `cpudiff; :; read_cycles[] - s_cpu], end_io, (cpuStats[.z.i] - s_cpu_stat), (memStats[.z.i] - s_memStats)
 };

// Define the d) debug mini-language function
e: {mStats x};

