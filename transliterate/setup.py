####### -*- coding: utf-8 -*- ##################################################

from distutils.core import setup, Extension
import os

here = os.path.abspath(os.path.dirname(__file__))
README = open(os.path.join(here, 'README.txt')).read()
CHANGES = open(os.path.join(here, 'CHANGES.txt')).read()

ext = Extension("transliterate._c_transliterate",
                sources=["src/transliterate/_c_transliterate.c"])

setup(
    name="transliterate",
    version="0.0.1",
    description="Transliterate module",
    ext_modules=[ext],
    package_dir={'': 'src'},
    packages=['transliterate', 'transliterate.tests'],
    include_package_data=True,
)
