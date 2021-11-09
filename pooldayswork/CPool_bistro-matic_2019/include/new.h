/*
** EPITECH PROJECT, 2019
** bistromatic
** File description:
** new.h
*/
#include<stdbool.h>
#ifndef NEW_H_
#define NEW_H_

struct Node
{
    char data;
    struct Node *next;
};

typedef struct Node stack_t;

void push(stack_t **head, char data);

bool is_empty(stack_t *head);

char peek(stack_t *head);

char pop(stack_t **head);

void display(stack_t *head);

#endif
