#!/bin/sh


# COLORS
# Reset
Color_Off='\033[0m'       # Text Reset
# Regular Colors
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan

# welcome message color
welcome_color="$Green"
# error message color
error_color="$Red"
# info message color
info_color="$Yellow"
# debug message color
debug_color="$Purple"
# success message color
success_color="$Cyan"

# welcome message mulitline
echo "----------" 
echo "${welcome_color}Welcome to the world of Linux😀\nkeep one your main this only design to work on lunix${Color_Off}"
echo "----------"

# ask user if remove folodr or no 
echo "${info_color}Do you want to remove the Exmaple Project?${Color_Off}"
echo "1. Yes 😎"
echo "2. No 😴"
read -p "Enter your choice: " choice

if [ $choice -eq 1 ]; then
    echo "${info_color}Removing the Example Project${Color_Off}"
    rm -rf ./Example
    echo "${success_color}Example Project removed successfully${Color_Off}"
elif [ $choice -eq 2 ]; then
    echo "${info_color}Exiting the script${Color_Off}"
else
    echo "${error_color}Invalid choice${Color_Off}"
fi

# git pull repo 
echo "${info_color}Pulling the repo${Color_Off}"
git submodule update --init --recursive
wait
echo "${success_color}mlx_linux pulled successfully${Color_Off}"

# build the mlx_linux
echo "${info_color}Building the mlx_linux${Color_Off}"
cd mlx_linux
./configure
wait
echo "${success_color}mlx_linux built successfully${Color_Off}"

# create the Example Project
echo "${info_color}Creating the Example Project${Color_Off}"
cd ..
mkdir Example
wait
echo "${success_color}Example Project created successfully${Color_Off}"

