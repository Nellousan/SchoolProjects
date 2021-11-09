#!/usr/bin/env bash
##
## EPITECH PROJECT, 2020
## skip-synthesis
## File description:
## s
##

gawk '{print $3,"\t",$9}' | grep \ $1
