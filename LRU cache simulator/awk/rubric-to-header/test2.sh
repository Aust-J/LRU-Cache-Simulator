#!/bin/bash
# nested rubric

rm -f temp.txt
./rubric-to-header.awk rubric2.json > temp.txt
diff -w temp.txt gold2.txt > diffs.txt

