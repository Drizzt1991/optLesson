####### -*- coding: utf-8 -*- ##################################################

import unittest
from transliterate import _py_transliterate
from transliterate import _c_transliterate

cyrilic_map = {
     u'А':u'A' , u'Б':u'B'   , u'В':u'V'   , u'Г':u'G', u'Д':u'D' , u'Е':u'E',
     u'Ё':u'E' , u'Ж':u'J'   , u'З':u'Z'   , u'И':u'I', u'Й':u'Y' , u'К':u'K',
     u'Л':u'L' , u'М':u'M'   , u'Н':u'N'   , u'О':u'O', u'П':u'P' , u'Р':u'R',
     u'С':u'S' , u'Т':u'T'   , u'У':u'U'   , u'Ф':u'F', u'Х':u'H' , u'Ц':u'TS',
     u'Ч':u'Ch', u'Ш':u'Sh'  , u'Щ':u'Shch', u'Ъ':u'I', u'Ы':u'Y' , u'Ь':u'',
     u'Э':u'E' , u'Ю':u'YU'  , u'Я':u'YA'  , u'І':u'I', u'Ї':u'YIu',

     u'а':u'a' , u'б':u'b'   , u'в':u'v'   , u'г':u'g', u'д':u'd' , u'е':u'e',
     u'ё':u'e' , u'ж':u'j'   , u'з':u'z'   , u'и':u'i', u'й':u'y' , u'к':u'k',
     u'л':u'l' , u'м':u'm'   , u'н':u'n'   , u'о':u'o', u'п':u'p' , u'р':u'r',
     u'с':u's' , u'т':u't'   , u'у':u'u'   , u'ф':u'f', u'х':u'h' , u'ц':u'ts',
     u'ч':u'ch', u'ш':u'sh'  , u'щ':u'shch', u'ъ':u'i', u'ы':u'y' , u'ь':u'',
     u'э':u'e' , u'ю':u'yu'  , u'я':u'ya'  , u'і':u'i', u'ї':u'yi',

     # u'!':u'_' , u'~':u'_'   , u'-':u'_'   , u'"':u'_', "'":u'_' , u'(':u'_',
     # u')':u'_' , u'*':u'_'   , u'^':u'_'   , u' ':u' ',   
}

class FunctionTests:

    _module = None

    def test_default_chars(self):
        for k, v in cyrilic_map.items():
            self.assertEqual(self._module.transliterate(k), v)

class TestPythonFunction(FunctionTests, unittest.TestCase):
    _module = _py_transliterate

class TestCFunction(FunctionTests, unittest.TestCase):
    _module = _c_transliterate

