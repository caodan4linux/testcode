#!/usr/bin/env python
# -*- coding: utf-8 -*-

#--------------------------------------------------------------------
# File Name: condition.py
# Description:
# Author: Dan Cao <caodan@linuxtoy.cn>
# Created Time: 2017-10-15 21:32:15
#--------------------------------------------------------------------

# input will return a str
s = input('Please input your age:')

age = int(s)

if age >= 18:
    print('Adult')
elif age >= 6:
    print('Teenager')
else:
    print('Child')

