#!/usr/bin/env python
# -*- coding: utf-8 -*-

#--------------------------------------------------------------------
# File Name: loop_break.py
# Description:
# Author: Dan Cao <caodan@linuxtoy.cn>
# Created Time: 2017-10-20 23:15:43
#--------------------------------------------------------------------


n = 1
while n <= 100:
    if n > 10:
        break

    print(n)
    n =  n + 1

print('END')

