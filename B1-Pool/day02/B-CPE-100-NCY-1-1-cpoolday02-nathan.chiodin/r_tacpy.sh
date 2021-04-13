#!/bin/bash
sed -n '2~2p' | cut -d: -f 1 | rev | tac | sort -dr | sed -n ${MY_LINE1},${MY_LINE2}p | sed -n -e ':a;N;$!ba;s/\n/, /g; s/$/./gp'
