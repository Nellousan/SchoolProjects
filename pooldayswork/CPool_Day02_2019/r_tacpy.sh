#!/bin/bash

resultat=$[$MY_LINE2 - $MY_LINE1 + 1]
cut -d ':' -f 1 | sed -n '2~2p' | rev | sort -r | head -n $MY_LINE2  | tail -n $resultat | sed -e ":a" -e 'N' -e '$!ba' -e 's/\n/, /g' | tr '\n' '%' | sed 's/%/.\n/' 
