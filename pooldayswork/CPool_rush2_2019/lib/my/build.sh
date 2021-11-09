#!/usr/bin/env bash
##
## EPITECH PROJECT, 2019
## script
## File description:
## créer ma librairie
##

gcc *.c -c
ar rc libmy.a *.o
rm *.o
