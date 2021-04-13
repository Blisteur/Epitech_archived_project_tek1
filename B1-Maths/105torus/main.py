#!/usr/bin/env python3

import sys
import os.path
import math

def help():
    if os.path.exists("help.txt") == False:
        sys.stderr.write("ERROR: help file is missing !\n")
        exit(84)
    help_file = open("help.txt")
    print(help_file.read())
    help_file.close()
    exit(0)

def error_handler(argv):
    if len(argv) < 8 or len(argv) > 8:
        sys.stderr.write("ERROR: too many or too few arguments !\n")
        exit(84)
    if argv[1] != "1" and argv[1] != "2" and argv[1] != "3":
        sys.stderr.write("ERROR: opt only number 1/2/3 accepted !\n")
        exit(84)
    for i in range(2, 7):
        neg = 0
        if argv[i][0] == '-' and len(argv[i]) > 1:
            neg += 1
        for n in range(neg, len(argv[i])):
            if argv[i][n] > '9' or argv[i][n] < '0':
                sys.stderr.write("ERROR: only numbers are accepted !\n")
                exit(84)
    for n in range(len(argv[7])):
            if argv[7][n] > '9' or argv[7][n] < '0':
                sys.stderr.write("ERROR: only positive numbers are accepted !\n")
                exit(84)

def bisection(argv):
    n = 0.5
    x = 0
    nb1 = 0
    nb2 = 0
    v = 1
    tmp = 0;
    print("x = 0.5")
    for rd in range(50):
        x = ((n + v) / 2)
        if tmp == round(x, int(argv[7])):
            return
        if rd < int(argv[7]):
            print("x = %.*f" %(rd + 2, x))
        else:
            print("x = %.*f" %(int(argv[7]), x))
        tmp = round(x, int(argv[7]))
        nb1 = ((int(argv[6]) * (x ** 4)) + (int(argv[5]) * (x ** 3)) + (int(argv[4]) * (x ** 2)) + (int(argv[3]) * x) + int(argv[2]))
        nb2 = ((int(argv[6]) * (n ** 4)) + (int(argv[5]) * (n ** 3)) + (int(argv[4]) * (n ** 2)) + (int(argv[3]) * n) + int(argv[2]))
        if nb1 * nb2 < 0:
            v = x
        else:
            n = x
    return

def newton(argv):
    n = 0.5
    x = 0
    nb1 = 0
    nb2 = 0
    tmp = 0;
    print("x = 0.5")
    for rd in range(50):
        nb1 = ((int(argv[6]) * (n ** 4)) + (int(argv[5]) * (n ** 3)) + (int(argv[4]) * (n ** 2)) + (int(argv[3]) * n) + int(argv[2]))
        nb2 = (int(argv[3]) + (2 * int(argv[4]) * n) + (3 * (int(argv[5]) * (n ** 2))) + (4 * (int(argv[6]) * (n ** 3))))
        if nb2 == 0:
            return
        x = n - (nb1 / nb2)
        if tmp == round(x, int(argv[7])):
            return
        print("x = %.*f" %(int(argv[7]), x))
        tmp = round(x, int(argv[7]))
        n = x
    return

def secant(argv):
    print("x = 0.5")
    return

def main(argv):
    if len(argv) == 2 and argv[1] == "-h":
        help()
    error_handler(argv)
    if argv[1] == "1":
        bisection(argv)
    if argv[1] == "2":
        newton(argv)
    if argv[1] == "3":
        secant(argv)
    return(0)