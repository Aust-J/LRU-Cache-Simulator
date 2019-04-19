#!/usr/bin/awk -f 
BEGIN{temp = ""; problem = ""; before = 0; section = ""; subsection = ""; x = 0}


{if ($1 ~ /\{/) {before += 1} if($1 ~ /\}/) before -= 1;}

/\"/{gsub("\"", ""); if (before == 1) {problem = ","$1""} if (before == 2) {section ="_"$1""; subsection = ""} if(before == 3) {subsection = "_"$1""} if (before != 1 && subsection != "_a") {temp = temp problem section subsection} if(subsection == "_a"){temp = temp subsection}}


END{print "Identifier,\"Full name\""temp",comments"}
