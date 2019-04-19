#!/bin/bash
# simple rubric

rm -f temp.txt
./rubric-to-header.awk rubric1.json > temp.txt
diff -w temp.txt gold1.txt > diffs.txt

