\d .d

// Using code.kx https://github.com/KxSystems/cookbook/tree/master/cpu_extension
/ To compute differences in cpu cycles
read_cycles: hsym[`$ getenv[`QHOME], "/libso/cpu"] 2: (`q_read_cycles_of_this_cpu;1);

/ To compute differences in proc/pid/io
read_io: hsym[`$ getenv[`QHOME], "/libso/readPID"] 2: (`readPidFile;2);

/ To compute differences in proc/pid/stat
read_stat: hsym[`$ getenv[`QHOME], "/libso/readPID"] 2: (`readPidStat;3);

// Define function for cpu stats for specific PID
/ https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat
cpuStats: {
    `utime`stime`cutime`cstime`starttime!raze "J"$ read_stat[x]'[14 22;17 22]
 };

// Define the function that measures time and memory stats
mStats: {
    s_cpu:read_cycles[]; 
    s_io:read_io[.z.i;`io]; 
    s_cpu_stat: cpuStats[.z.i]; 
    op:`time`mem!system "ts 0N!", x; 
    @[op; `cpudiff; :; read_cycles[] - s_cpu], (read_io[.z.i;`io] - s_io), (cpuStats[.z.i] - s_cpu_stat) 
 };

// Define the d) debug mini-language function
e: {mStats x};
