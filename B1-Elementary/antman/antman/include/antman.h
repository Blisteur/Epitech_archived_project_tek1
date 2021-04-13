/*
** EPITECH PROJECT, 2021
** antman
** File description:
** .h
*/

#ifndef ANTMAN
#define ANTMAN

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int error_handler(int argc, char **argv);
int antman(char **argv);

#endif /* !ANTMAN */