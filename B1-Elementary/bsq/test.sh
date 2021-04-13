##
## EPITECH PROJECT, 2020
## B-CPE-110-NCY-1-1-BSQ-nathan.chiodin
## File description:
## test
##

#!/bin/bash

nb=1
nbmax=39
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_34_137_empty > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_34_137_empty
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_34_137_filled > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_34_137_filled
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_34_137_with_obstacles_25pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_34_137_with_obstacles_25pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_34_137_with_obstacles_50pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_34_137_with_obstacles_50pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_34_137_with_obstacles_75pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_34_137_with_obstacles_75pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_97_21_empty > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_97_21_empty
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_97_21_filled > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_97_21_filled
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_97_21_with_obstacles_25pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_97_21_with_obstacles_25pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_97_21_with_obstacles_50pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_97_21_with_obstacles_50pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_97_21_with_obstacles_75pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_97_21_with_obstacles_75pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_100_100 > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_100_100
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_187_187_empty > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_187_187_empty
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_187_187_filled > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_187_187_filled
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_187_187_with_obstacles_25pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_187_187_with_obstacles_25pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_187_187_with_obstacles_50pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_187_187_with_obstacles_50pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_187_187_with_obstacles_75pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_187_187_with_obstacles_75pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_200_200 > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_200_200
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_500_500 > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_500_500
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_500_500_2 > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_500_500_2
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_500_500_3 > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_500_500_3
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_1000_1000 > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_1000_1000
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_1000_1000_2 > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_1000_1000_2
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_2000_2000 > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_2000_2000
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_5000_5000 > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_5000_5000
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_10000_10000 > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_10000_10000
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_empty_corners > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_empty_corners
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_filled_corners > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_filled_corners
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_one_column_with_obstacles_25pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_one_column_with_obstacles_25pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_one_column_with_obstacles_50pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_one_column_with_obstacles_50pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_one_column_with_obstacles_75pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_one_column_with_obstacles_75pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_one_empty_box > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_one_empty_box
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_one_empty_column > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_one_empty_column
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_one_empty_line > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_one_empty_line
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_one_filled_box > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_one_filled_box
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_one_filled_column > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_one_filled_column
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_one_filled_line > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_one_filled_line
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_one_line_with_obstacles_25pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_one_line_with_obstacles_25pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_one_line_with_obstacles_50pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_one_line_with_obstacles_50pc
echo -e "\e[32m$nb/$nbmax\e[39m"
let "nb += 1"
timeout 20 ./bsq B-CPE-110_BSQ_Bootstrap_files/mouli_maps/intermediate_map_one_line_with_obstacles_75pc > res.txt
diff -s --color res.txt B-CPE-110_BSQ_Bootstrap_files/mouli_maps_solved/intermediate_map_one_line_with_obstacles_75pc