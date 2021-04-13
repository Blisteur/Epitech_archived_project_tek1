#!/usr/bin/env python3

import sys
import os.path
import math
import opt

def help():
    if os.path.exists("help.txt") == False:
        sys.stderr.write("ERROR: help file is missing !\n")
        exit(84)
    help_file = open("help.txt")
    print(help_file.read())
    help_file.close()
    exit(0)

def error_handler(argv):
    if len(argv) > 9 or len(argv) < 9:
        sys.stderr.write("ERROR: too few or too many argument !\n")
        exit(84)
    if argv[1] != "1" and argv[1] != "2" and argv[1] != "3":
        sys.stderr.write("ERROR: opt only 1/2/3 are accepted !\n")
        exit(84)
    for i in range(2, 8):
        neg = 0
        if argv[i][0] == '-' and len(argv[i]) > 1:
            neg += 1
        for n in range(neg, len(argv[i])):
            if argv[i][n] > '9' or argv[i][n] < '0':
                sys.stderr.write("ERROR: coord only numbers are accepted !\n")
                exit(84)
    if str(argv[5]) == "0" and str(argv[6]) == "0" and str(argv[7]) == "0":
        sys.stderr.write("ERROR: null vector !\n")
        exit(84)
    if int(argv[1]) == 1 or int(argv[1]) == 2:
        if str(argv[8][0]) == '-':
            sys.stderr.write("ERROR: parameter can not be negative !\n")
            exit(84)
        for n in range(len(argv[8])):
            if argv[8][n] > '9' or argv[8][n] < '0':
                sys.stderr.write("ERROR: parameter only numbers are accepted !\n")
                exit(84)
    else:
        neg = 0
        if str(argv[8][0]) == '-':
            neg = 1
        for n in range(neg, len(argv[8])):
            if argv[8][n] > '9' or argv[8][n] < '0':
                sys.stderr.write("ERROR: parameter only numbers are accepted !\n")
                exit(84)
        if int(str(argv[8])) > 360 or int(str(argv[8])) < -360 or int(str(argv[8])) == 0:
            sys.stderr.write("ERROR: parameter can not be more 360° !\n")
            exit(84)

def main(argv):
    if len(argv) == 2 and argv[1] == "-h":
        help()
    error_handler(argv)
    if int(argv[1]) == 1:
        opt.sphere(argv)
    elif int(argv[1]) == 2:
        opt.cylinder(argv)
    elif int(argv[1]) == 3:
        opt.cone(argv)
    return(0)