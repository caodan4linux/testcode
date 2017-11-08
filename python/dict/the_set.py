#!/usr/bin/env python
# -*- coding: utf-8 -*-

#--------------------------------------------------------------------
# File Name: set.py
# Description:
#        set 和 dict类似, 也是一组key的集合，但不存储value
# Author: Dan Cao <caodan@linuxtoy.cn>
# Created Time: 2017-11-09 00:48:11
#--------------------------------------------------------------------


# 创建一个set, 需要提供一个list作为输入集合
s = set([1, 2, 3])
print(s)

# 重复的元素将会被 过滤掉
s = set([1, 2, 3, 5, 1, 3, 7])
print(s)

# 添加元素
s.add(8)
s.add(7)
print(s)

# 删除元素
print("Remove 3 from set")
s.remove(3)
print(s)

# 可以将set看作数学意义上 无序和无重复元素的集合
# 因此多个set可以做并集, 交集运算
s1 = set([1, 2, 4])
s2 = set([2, 3, 4])
print("\n")
print("s1 = ", s1)
print("s2 = ", s2)
print("s1 & s2 = ", s1 & s2)
print("s1 | s2 = ", s1 | s2)

