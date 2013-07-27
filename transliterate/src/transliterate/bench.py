####### -*- coding: utf-8 -*- ##################################################

import timeit
import sys
import os.path
from transliterate import _py_transliterate, _c_transliterate
import cProfile

sentence = u"Для иллюстрации рассмотрим немного изменённый пример из "\
    "приведенной в самом начале статьи."


class Runner:
    _module = None

    def __init__(self):
        data_file = os.path.join(
            os.path.dirname(os.path.abspath(__file__)), 'KOBZAR.txt')
        with open(data_file, 'r', encoding="utf-8") as f:
            data = f.read()
        self.data = data

        def run_kobzar(data=data, transliterate=self._module.transliterate):
            transliterate(data)
        self.run = run_kobzar


class PyRunner(Runner):
    _module = _py_transliterate


class CRunner(Runner):
    _module = _c_transliterate


def main():
    # import pdb;pdb.set_trace()
    # p = cProfile.Profile()
    # p.runcall(PyRunner().run)
    # p.print_stats()

    print("Sentence test")
    print("Python:", timeit.timeit(
        't(sentence)',
        "from __main__ import _py_transliterate, sentence;"
        "t=_py_transliterate.transliterate"))
    print("Pure C:", timeit.timeit(
        't(sentence)',
        "from __main__ import _c_transliterate, sentence;"
        "t=_c_transliterate.transliterate"))
    print("KOBZAR test")
    print("Python:", timeit.timeit(
        'run()', "from __main__ import PyRunner;run=PyRunner().run",
        number=100))
    print("Pure C:", timeit.timeit(
        'run()', "from __main__ import CRunner;run=CRunner().run",
        number=100))

if __name__ == "__main__":
    main()
