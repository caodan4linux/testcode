#!/usr/bin/env python
# -*- coding: utf-8 -*-

#--------------------------------------------------------------------
# File Name: loop.py
# Description:
# Author: Dan Cao <caodan@linuxtoy.cn>
# Created Time: 2017-10-20 22:50:08
#--------------------------------------------------------------------

# count from 0 to 100
sum = 0
for x in list(range(101)):
    sum = sum + x

print(sum)


L = ['Bart', 'Lisa', 'Adam']
for name in L:
    print("hello %s" % name)

