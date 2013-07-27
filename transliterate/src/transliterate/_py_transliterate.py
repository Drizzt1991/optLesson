####### -*- coding: utf-8 -*- ##################################################

# This is a pure python implementation of the transliterate module.

from copy import copy
import functools
import io
import re
import string

trans_dict =    {
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

     u'!':u'_' , u'~':u'_'   , u'-':u'_'   , u'"':u'_', "'":u'_' , u'(':u'_',
     u')':u'_' , u'*':u'_'   , u'^':u'_'   , u' ':u' ',   
     }


# class Transliterator:

#     def __init__(
#             self,
#             safe_chars=None,
#             extended_mapping=None,
#             escape_char=None):
#         pass

#     def transliterate(self, ustring):
#         result = u''
#         trans_map = trans_dict
#         for char in ustring:
#             result += trans_map.get(char, char)
#         return result

# _default_transliterator = Transliterator()

# ord_map = dict((ord(x[0]), ord(y[0])) for x,y in trans_dict.items() if y)


def transliterate(ustring=u'u'):
    """function makes transliteration"""
    #V1.0
    # result = u''
    # for char in ustring:
    #     result += trans_dict.get(char, char)
    # return result
    # Sentence - 21.11
    # Kobzar - 12.79

    # V1.1
    getter = lambda x, get=trans_dict.get: get(x, x)
    return u''.join(map(getter, ustring))
    # Sentence - 23.00
    # Kobzar - 12.82

    # V1.2
    # new_str = ustring
    # for k, v in trans_dict.items():
    #     new_str = new_str.replace(k, v)
    # return new_str
    # Sentence - 26.19
    # Kobzar - 3.3
    # Hmm... quite fast on Kobzar test

    # V1.3
    # Read that re.sub is o(N). Let's try :D
    # getter = lambda x, get=trans_dict.get: get(x.group(1), x.group(1))
    # return re.sub(r'(.)', getter, ustring)
    # Neee Lies.
    # Sentence - 85.2
    # Kobzar - 49.0

    # V1.4
    # Using cStringIO is o(N) for join. Let's try :)
    # res = io.StringIO()
    # getter = trans_dict.get
    # for char in ustring:
    #     res.write(getter(char, char))
    # return res.getvalue()
    # Quite nice ^_^
    # Sentence - 19.60
    # Kobzar - 11.00

    # V1.5
    # Lets test how much do we need to perform decoding by iter
    # getter = trans_dict.get
    # for char in ustring:
    #     getter(char, char)
    # Sentence - 11.0
    # Kobzar - 6.336

    # V1.6
    # Lets test how much we can win if use standart c encode method.
    # Must be good
    # return ustring.translate(ord_map)
    # HMMM. Some interesting results we have here
    # Sentence - 6.69
    # Kobzar - 3.81
    ## WHY!!! This was supposed to be the fastest!

    # if escape_char is None:
    #     return _default_transliterator.transliterate(ustring)
    # return Transliterator(escape_char=escape_char).transliterate(ustring)
