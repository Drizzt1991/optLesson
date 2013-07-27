#### -*- coding:utf-8 -*- ########
from __future__ import print_function

import sys


def change_a():
    frame = sys._getframe(1)
    frame.f_locals['a'] = 30


class test_frame(object):
    a = 20
    print(a)
    change_a()
    print(a)


def main():
    test_frame()


if __name__ == "__main__":
    main()
