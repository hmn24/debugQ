\d .d

// Define the d) debug mini-language function
e: {mStats x};

// Define the function that measures time and memory stats
mStats: {`time`mem!system "ts 0N!", x};
