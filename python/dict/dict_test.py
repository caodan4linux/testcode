#!/usr/bin/env python
# -*- coding: utf-8 -*-

#--------------------------------------------------------------------
# File Name: dict_test.py
# Description:
#    dict 和 list 相比较有如下几个特点:
#      1. 查找和插入的速度极快，不会随着key的增加而变慢.
#      2. 需要占用大量的内存
#    而list和dict正好相反:
#      1. 查找和插入的时间随着元素的增加而增加.
#      3. 占用空间小.
#    所以dict是用空间换取时间的一种做法.
# Author: Dan Cao <caodan@linuxtoy.cn>
# Created Time: 2017-10-29 22:06:06
#--------------------------------------------------------------------

d = {'Michael': 95, 'Bob': 75, 'Tracy': 85}


if 'Tom' in d:
    print('Tom in the dict')
else:
    print('Tom not in the dict')


if 'Michael' in d:
    print('Michael in the dict')
    print('Michael scores %d' % d['Michael'])

if d.get('Jack', -1) == -1:
    print('Jack not in the dict')

d['Jack'] = 79
if d.get('Jack', -1) != -1:
    print('Add jack to the dict')
    print('Jack scores %d' % d['Jack'])


d.pop('Jack')
print("Remove Jack ......")
if d.get('Jack', -1) == -1:
    print('Jack not in the dict')
else:
    print('Jack in the dict')


