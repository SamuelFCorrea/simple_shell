# Simple Shell

## Introduction:

In this project is developed a simple veresion of the **UNIX** command line interpreter (shell) as a part of Holberton School project.

## Description

This project consists of creating our own version of a simple shell which is capable of interacting directly with the user through commands, we create a system that is capable of handling a path that is in charge of detecting if the arguments entered by the user are found and then executing them, differentiating what type they are, whether they are built-in commands or not, to go through the forking process. which immediately handles calls to the execv system, running according to the process and finally exiting with exit or ^D.

## Requirements:

### General:

+ Allowed editors: **vi**, **vim**, **emacs**
+ All your files will be compiled on Ubuntu 14.04 LTS
+ Your C programs and functions will be compiled with **gcc 4.8.4 using the flags -Wall -Werror -Wextra** and **-pedantic**
+ All your files should end with a new line
+ A README.md file, at the root of the folder of the project is mandatory
+ Your code should use the **Betty** style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
+ Your shell should not have any memory leaks
+ No more than 5 functions per file
+ All your header files should be include guarded
+ Use system calls only when you need to ([why?](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems))

## Flowchart:

![Diagrama en blanco](https://user-images.githubusercontent.com/66297338/100475586-7e39e480-30b1-11eb-9a01-55259ea636fb.png)

## How To Install & Compile

 To have this repository and its content, you must execute the following on your terminal:

```
$ git clone https://github.com/SamuelFCorrea/simple_shell.git

$ cd simple_shell

$ ls
```

 And execute the following in your terminal:

```
 $ gcc -Wall -Werror -Wextra -pedantic *.c -o shell

 $ ./shell
```
And now you can type and execute commands writing its relative path, see below:

```
$ ./shell
 ($) /bin/ls
 AUTHORS  README.md command_execute.c command_maker.c errors.c main.c man_1_simple_shell sh_mode.c shell.h strings.c
 ($)
 ($) exit
$
```
Or you can write the keyword of the command:

```
 ($) ls
 AUTHORS  README.md command_execute.c command_maker.c errors.c main.c man_1_simple_shell sh_mode.c shell.h strings.c
 ($)
```

### AUTHORS
* **Samuel Correa** - [SamuelFCorrea](https://github.com/SamuelFCorrea)
* **Sebastián Paruma** - [sebastianparuma](https://github.com/sebastianparuma)
* **Luisa Uribe** - [luisauribe](https://github.com/luisauribe)
