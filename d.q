\d .d

// Using code.kx https://github.com/KxSystems/cookbook/tree/master/cpu_extension
/ To compute differences in cpu cycles
read_cycles: hsym[`$ getenv[`QHOME], "/libso/cpu"] 2:(`q_read_cycles_of_this_cpu;1);

/ To compute differences in proc/io stats
read_io: hsym[`$ getenv[`QHOME], "/libso/readPID"] 2: (`readPidFile;2);

// Define the function that measures time and memory stats
mStats: {
    s_cpu:read_cycles[]; 
    s_io:read_io[.z.i;`io]; 
    op:`time`mem!system "ts 0N!", x; 
    @[op; `cpudiff; :; read_cycles[] - s_cpu], read_io[.z.i;`io] - s_io
 };

// Define the d) debug mini-language function
e: {mStats x};




