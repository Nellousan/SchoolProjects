#!bin/bash

cut -d":" -f "1" | rev | sed -n "2~2p" | sort -r | head -n $MY_LINE2 | tail -n $[$MY_LINE2 - $MY_LINE1 + 1] | sed -e ':a' -e 'N' -e '$!ba' -e 's/\n/, /g' | tr '\n' '%' | sed 's/%/.\n/'
