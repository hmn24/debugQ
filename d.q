\d .d

// Using code.kx https://github.com/KxSystems/cookbook/tree/master/cpu_extension
/ To compute differences in cpu cycles
read_cycles: `:libso/cpu 2:(`q_read_cycles_of_this_cpu;1)

// Define the function that measures time and memory stats
mStats: {s:.d.read_cycles[]; op:`time`mem!system "ts 0N!", x; update cpudiff:.d.read_cycles[]-s from op};

// Define the d) debug mini-language function
e: {mStats x};




