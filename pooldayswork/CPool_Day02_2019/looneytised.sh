#!/bin/bash

sed -e "s/theo1/Wile E. Coyote/gi" -e "s/steven1/Daffy Duck/gi" -e  "s/arnaud1/Porky Pig/gi" -e "s/pierre-jean/Marvin the Martian/gi" |
grep "Wile E. Coyote\|Daffy Duck\|Porky Pig\|Marvin the Martian"
