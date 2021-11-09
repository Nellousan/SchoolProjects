#!/usr/bin/env bash
##
## EPITECH PROJECT, 2019
## build library
## File description:
## script that build *.c int the folder into libmy.a
##

gcc -c *.c
ar rc libmy.a *.o
