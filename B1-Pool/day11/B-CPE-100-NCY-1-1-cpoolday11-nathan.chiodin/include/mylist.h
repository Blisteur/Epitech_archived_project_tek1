/*
** EPITECH PROJECT, 2020
** mtlist
** File description:
** .h
*/

#ifndef MYLIST_H_
#define MYLIST_H_

typedef struct linked_list
{
    void *data;
    struct linked_list *next;
} linked_list_t;

#endif /* !MYLIST_H_ */