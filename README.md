# Simple Shell

## Description

This project consists of creating our own version of a simple shell which is capable of interacting directly with the user through commands, we create a system that is capable of handling a path that is in charge of detecting if the arguments entered by the user are found and then executing them, differentiating what type they are, whether they are built-in commands or not, to go through the forking process. which immediately handles calls to the execv system, running according to the process and finally exiting with exit or ^D.

## How To Install & Compile

 To have this repository and its content, you must execute the following on your terminal:

 $git clone https://github.com/SamuelFCorrea/simple_shell.git
 $cd simple_shell
 $ls

 And execute the following in your terminal:

 $gcc -Wall -Werror -Wextra -pedantic *.c
 $./a.out [...]
