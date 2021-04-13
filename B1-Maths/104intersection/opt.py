#!/usr/bin/env python3

import main
from math import *

def sphere(argv):
    print("Sphere of radius", int(argv[8]))
    print("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)" %(int(argv[2]), int(argv[3]), int(argv[4]), int(argv[5]), int(argv[6]), int(argv[7])))
    calcul_sphere(argv)

def cylinder(argv):
    print("Cylinder of radius", int(argv[8]))
    print("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)" %(int(argv[2]), int(argv[3]), int(argv[4]), int(argv[5]), int(argv[6]), int(argv[7])))
    calcul_cylinder(argv)

def cone(argv):
    print("Cone with a %d degree angle" %int((argv[8])))
    print("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)" %(int(argv[2]), int(argv[3]), int(argv[4]), int(argv[5]), int(argv[6]), int(argv[7])))
    calcul_cone(argv)

def calcul_sphere(argv):
    a = ((int(argv[5]) ** 2) + (int(argv[6]) ** 2) + (int(argv[7]) ** 2))
    b = (((int(argv[2]) * 2) * int(argv[5])) + ((int(argv[3]) * 2) * int(argv[6])) + ((int(argv[4]) * 2) * int(argv[7])))
    c = ((int(argv[2]) ** 2) + (int(argv[3]) ** 2) + (int(argv[4]) ** 2) - (int(argv[8]) ** 2))
    delta = (b * b) - (4 * a * c)
    if delta < 0:
        print("No intersection point.")
        return
    if delta == 0:
        print("1 intersection point.")
        x = -(b) / 2 * a
        res_x = (int(argv[2]) + x * int(argv[5]))
        res_y = (int(argv[3]) + x * int(argv[6]))
        res_z = (int(argv[4]) + x * int(argv[7]))
        print("(%.3f, %.3f, %.3f)" %(res_x, res_y, res_z))
    if delta > 0:
        print("2 intersection point.")
        x1 = -(b) + sqrt(delta) / 2 * a
        x2 = -(b) - sqrt(delta) / 2 * a
        res_1_x = (int(argv[2]) + x1 * int(argv[5]))
        res_1_y = (int(argv[3]) + x1 * int(argv[6]))
        res_1_z = (int(argv[4]) + x1 * int(argv[7]))
        res_2_x = (int(argv[2]) + x2 * int(argv[5]))
        res_2_y = (int(argv[3]) + x2 * int(argv[6]))
        res_2_z = (int(argv[4]) + x2 * int(argv[7]))
        print("(%.3f, %.3f, %.3f)" %(res_1_x, res_1_y, res_1_z))
        print("(%.3f, %.3f, %.3f)" %(res_2_x, res_2_y, res_2_z))

def calcul_cylinder(argv):
    a = ((int(argv[5]) ** 2) + (int(argv[6]) ** 2))
    b = (((int(argv[2]) * 2) * int(argv[5])) + ((int(argv[3]) * 2) * int(argv[6])))
    c = ((int(argv[2]) ** 2) + (int(argv[3]) ** 2) - (int(argv[8]) ** 2))
    delta = (b * b) - (4 * a * c)
    if delta < 0:
        print("No intersection point.")
        return
    if delta == 0:
        print("1 intersection point.")
        x = -(b) / 2 * a
        res_x = (int(argv[2]) + x * int(argv[5]))
        res_y = (int(argv[3]) + x * int(argv[6]))
        res_z = (int(argv[4]) + x * int(argv[7]))
        print("(%.3f, %.3f, %.3f)" %(res_x, res_y, res_z))
    if delta > 0:
        print("2 intersection point.")
        x1 = -(b) + sqrt(delta) / 2 * a
        x2 = -(b) - sqrt(delta) / 2 * a
        res_1_x = (int(argv[2]) + x1 * int(argv[5]))
        res_1_y = (int(argv[3]) + x1 * int(argv[6]))
        res_1_z = (int(argv[4]) + x1 * int(argv[7]))
        res_2_x = (int(argv[2]) + x2 * int(argv[5]))
        res_2_y = (int(argv[3]) + x2 * int(argv[6]))
        res_2_z = (int(argv[4]) + x2 * int(argv[7]))
        print("(%.3f, %.3f, %.3f)" %(res_1_x, res_1_y, res_1_z))
        print("(%.3f, %.3f, %.3f)" %(res_2_x, res_2_y, res_2_z))

def calcul_cone(argv):
    print("No intersection point.")