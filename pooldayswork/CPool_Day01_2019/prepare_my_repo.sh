#!/bin/bash

blih -u nell.fauveau@epitech.eu repository create $1
blih -u nell.fauveau@epitech.eu repository setacl $1 ramassage-tek r
blih -u nell.fauveau@epitech.eu repository getacl $1 
