#!/usr/bin/env python
# -*- coding: utf-8 -*-

#--------------------------------------------------------------------
# File Name: condition1.py
# Description: Calculate the BMI(Body Mass Index)
# Author: Dan Cao <caodan@linuxtoy.cn>
# Created Time: 2017-10-15 21:44:38
#--------------------------------------------------------------------

s = input('Please input you height(m): ')
height=float(s)

s = input('Please input you weight(kg): ');
weight = float(s)

print('height: %.2f m, weight: %.2f kg' % (height, weight))


bmi = weight / (height * height)

print('bmi=%f' % bmi)

if bmi < 18.5:
    print('偏瘦')
elif bmi >= 18.5 and bmi < 25:
    print('正常')
elif bmi >= 25 and bmi < 28:
    print('过重')
else:
    print('肥胖')

