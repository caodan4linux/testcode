#!/usr/bin/env python
# -*- coding: utf-8 -*-

#--------------------------------------------------------------------
# File Name: loop_continue.py
# Description:
# Author: Dan Cao <caodan@linuxtoy.cn>
# Created Time: 2017-10-20 23:18:18
#--------------------------------------------------------------------

n = 0
while n < 10:
    n = n + 1
    if n % 2 == 0:
        continue

    print(n)

