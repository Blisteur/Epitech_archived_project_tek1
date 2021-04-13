#!/usr/bin/env python3

import sys
import math

def help():
    print("USAGE\n   ./103cipher message key flag\n")
    print("DESCRIPTION\n    message    a message, made of ASCII characters")
    print("    key        the encryption key, made of ASCII characters")
    print("    flag       0 for the massage to be encrypted, 1 to be decrypted")
    exit(0)

def error_handler(argv):
    if len(argv) == 2 and str(argv[1]) == "-h":
        help()
    if len(argv) != 4:
        print("ERROR: too many or too few arguments !")
        exit(84)
    if argv[3] != "0" and argv[3] != "1":
        print("ERROR: argument 3 is 0 for encrypt 1 for decrypt !")
        exit(84)

def matrix2(argv):
    tab = [0, 0, 0, 0]
    for i in range(0, len(argv[2])):
        tab[i] = ord(argv[2][i])
    print("Key matrix:")
    tmp = 0
    for i in range (0, 2):
        space = 8
        space -= len(str(tab[tmp]))
        print(tab[tmp], end=space * " ")
        print(tab[tmp + 1])
        tmp += 2
    return(tab)

def matrix3(argv):
    tab = [0, 0, 0, 0, 0, 0, 0, 0, 0]
    for i in range(0, len(argv[2])):
        tab[i] = ord(argv[2][i])
    print("Key matrix:")
    tmp = 0
    for i in range(0, 3):
        space = 8
        space -= len(str(tab[tmp]))
        print(tab[tmp], end=space * " ")
        space = 8
        space -= len(str(tab[tmp + 1]))
        print(tab[tmp + 1], end=space * " ")
        print(tab[tmp + 2])
        tmp += 3
    return(tab)

def matrix4(argv):
    tab = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for i in range(0, len(argv[2])):
        tab[i] = ord(argv[2][i])
    print("Key matrix:")
    tmp = 0
    for i in range(0, 4):
        space = 8
        space -= len(str(tab[tmp]))
        print(tab[tmp], end=space * " ")
        space = 8
        space -= len(str(tab[tmp + 1]))
        print(tab[tmp + 1], end=space * " ")
        space = 8
        space -= len(str(tab[tmp + 2]))
        print(tab[tmp + 2], end=space * " ")
        print(tab[tmp + 3])
        tmp += 4
    return(tab)


def matrixcustom(argv):
    print("test")

def exep(argv):
    tab = [0]
    tab[0] = ord(argv[1][0])
    print("Key matrix:")
    print(tab[0])
    len_arg = len(argv[1])
    tab2 = [0] * int(len_arg)
    for i in range(0, len(argv[1])):
        tab2[i] = ord(argv[1][i])
    print()
    tabtmp = list(tab2)
    h = 0
    j = 0
    for i in range(0, int(len_arg)):
        tabtmp[h] = tab2[j] * tab[0]
        j += 1
        h += 1
    print("Encrypted message:")
    for i in range(0, len_arg - 1):
        print(tabtmp[i], end=" ")
    print(tabtmp[i + 1])


def matrix2_encrypt(tab, argv):
    len_arg = len(argv[1])
    if len_arg % 2 == 0:
        tab2 = [0] * int(len_arg / 2) * 2
    else:
        len_arg += 1
        tab2 = [0] * int(len_arg / 2) * 2
    for i in range(0, len(argv[1])):
        tab2[i] = ord(argv[1][i])
    print()
    tabtmp = list(tab2)
    h = 0
    j = 0
    for i in range(0, int(len_arg / 2)):
        tabtmp[h] = tab2[j] * tab[0] + tab2[j + 1] * tab[2]
        tabtmp[h + 1] = tab2[j] * tab[1] + tab2[j + 1] * tab[3]
        j += 2
        h += 2
    print("Encrypted message:")
    for i in range(0, len_arg - 1):
        print(tabtmp[i], end=" ")
    print(tabtmp[i + 1])

def matrix3_encrypt(tab, argv):
    len_arg = len(argv[1])
    if len_arg % 3 == 0:
        tab2 = [0] * int(len_arg / 3) * 3
    else:
        while len_arg % 3 != 0:
            len_arg += 1
        tab2 = [0] * int(len_arg / 3) * 3
    for i in range(0, len(argv[1])):
        tab2[i] = ord(argv[1][i])
    print()
    tabtmp = list(tab2)
    h = 0
    j = 0
    for i in range(0, int(len_arg / 3)):
        tabtmp[h] = tab2[j] * tab[0] + tab2[j + 1] * tab[3] + tab2[j + 2] * tab[6]
        tabtmp[h + 1] = tab2[j] * tab[1] + tab2[j + 1] * tab[4] + tab2[j + 2] * tab[7]
        tabtmp[h + 2] = tab2[j] * tab[2] + tab2[j + 1] * tab[5] + tab2[j + 2] * tab[8]
        j += 3
        h += 3
    print("Encrypted message:")
    for i in range(0, len_arg - 1):
        print(tabtmp[i], end=" ")
    print(tabtmp[i + 1])

def matrix4_encrypt(tab, argv):
    len_arg = len(argv[1])
    if len_arg % 4 == 0:
        tab2 = [0] * int(len_arg / 4) * 4
    else:
        while len_arg % 4 != 0:
            len_arg += 1
        tab2 = [0] * int(len_arg / 4) * 4
    for i in range(0, len(argv[1])):
        tab2[i] = ord(argv[1][i])
    print()
    tabtmp = list(tab2)
    h = 0
    j = 0
    for i in range(0, int(len_arg / 4)):
        tabtmp[h] = tab2[j] * tab[0] + tab2[j + 1] * tab[3] + tab2[j + 2] * tab[6]
        tabtmp[h + 1] = tab2[j] * tab[1] + tab2[j + 1] * tab[4] + tab2[j + 2] * tab[7]
        tabtmp[h + 2] = tab2[j] * tab[2] + tab2[j + 1] * tab[5] + tab2[j + 2] * tab[8]
        tabtmp[h + 3] = tab2[j] * tab[3] + tab2[j + 1] * tab[6] + tab2[j + 2] * tab[9]
        j += 4
        h += 4
    print("Encrypted message:")
    for i in range(0, len_arg - 1):
        print(tabtmp[i], end=" ")
    print(tabtmp[i + 1])

def encrypt(argv):
    if len(argv[2]) == 1:
        exep(argv)
    elif len(argv[2]) <= 4:
        tab = matrix2(argv)
        matrix2_encrypt(tab, argv)

    elif len(argv[2]) <= 9:
        tab = matrix3(argv)
        matrix3_encrypt(tab, argv)

    elif len(argv[2]) <= 16:
        tab = matrix4(argv)
        matrix4_encrypt(tab, argv)

def decrypt(argv):
    print("Test prepa")

def main(argv):
    error_handler(argv)
    if argv[3] == "0":
        encrypt(argv)
    elif argv[3] == "1":
        decrypt(argv)
