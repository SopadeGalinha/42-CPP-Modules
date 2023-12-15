#!/bin/bash

./account > test_output.log
# Compare the test output with the provided logs using diff
diff --ignore-matching-lines='\[.*\]' test_output.log 19920104_091532.log

# Check the exit code of diff
if [ $? -eq 0 ]; then
    exit 0
else
    exit 1
fi