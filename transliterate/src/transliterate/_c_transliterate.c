/**
 * See interface.py for method description. 
 */

#include <Python.h>

/*{
{32, " "},
{33, "_"},
{34, "_"},
{39, "_"},
{40, "_"},
{41, "_"},
{42, "_"},
{45, "_"},
{94, "_"},
{126, "_"},
{1025, "E"},
{1030, "I"},
{1031, "YIu"},
{1040, "A"},
{1041, "B"},
{1042, "V"},
{1043, "G"},
{1044, "D"},
{1045, "E"},
{1046, "J"},
{1047, "Z"},
{1048, "I"},
{1049, "Y"},
{1050, "K"},
{1051, "L"},
{1052, "M"},
{1053, "N"},
{1054, "O"},
{1055, "P"},
{1056, "R"},
{1057, "S"},
{1058, "T"},
{1059, "U"},
{1060, "F"},
{1061, "H"},
{1062, "TS"},
{1063, "Ch"},
{1064, "Sh"},
{1065, "Shch"},
{1066, "I"},
{1067, "Y"},
{1068, ""},
{1069, "E"},
{1070, "YU"},
{1071, "YA"},
{1072, "a"},
{1073, "b"},
{1074, "v"},
{1075, "g"},
{1076, "d"},
{1077, "e"},
{1078, "j"},
{1079, "z"},
{1080, "i"},
{1081, "y"},
{1082, "k"},
{1083, "l"},
{1084, "m"},
{1085, "n"},
{1086, "o"},
{1087, "p"},
{1088, "r"},
{1089, "s"},
{1090, "t"},
{1091, "u"},
{1092, "f"},
{1093, "h"},
{1094, "ts"},
{1095, "ch"},
{1096, "sh"},
{1097, "shch"},
{1098, "i"},
{1099, "y"},
{1100, ""},
{1101, "e"},
{1102, "yu"},
{1103, "ya"},
{1105, "e"},
{1110, "i"},
{1111, "yi"},
}*/

/*#define SINGLE_CHAR_MAP_LEN 128
#define DOUBLE_CHAR_MAP_LEN 128
#define MISSING_CHAR "\00"
#define MULTI_MAP "\01"

static char _single_char_map[SINGLE_CHAR_MAP_LEN];
static void _init_translation_map(){

}

/*******************************************************************************
 *                        Transliterate character by map
 *******************************************************************************
*/

#define MAX_CHAR_ORD 1112

static PyObject** _trans_map;

static void _translit_char(Py_UCS4 single_uchar, PyObject** translited_str)
{
  // Сразу игнорим ASCII, так как оно не транслитерируется.
  if (single_uchar <= 127 )
  {
    *translited_str = PyUnicode_FromStringAndSize((char*)&single_uchar, 1);
    return;
  }
  // Находим транслитерацию в карте транслитерации.
  if (single_uchar <= MAX_CHAR_ORD)
  {
    PyObject* res = _trans_map[(long)single_uchar];
    if (res != NULL){
      //Py_INCREF(res); Не будем передавать в питон
      *translited_str = res;
      return;
    }
  }
  // Если не нашли, то возвращаем символ по умолчанию.
  *translited_str = PyUnicode_FromStringAndSize("-", 1);
}

static void _init_translation_map(void)
{
  _trans_map = (PyObject**)malloc(MAX_CHAR_ORD*sizeof(PyObject*));

  int i=0;
  for (;i<MAX_CHAR_ORD;i++){
    _trans_map[i]=NULL;
  }

  _trans_map[32] = PyUnicode_FromStringAndSize(" ", 1);
  _trans_map[33] = PyUnicode_FromStringAndSize("_", 1);
  _trans_map[34] = PyUnicode_FromStringAndSize("_", 1);
  _trans_map[39] = PyUnicode_FromStringAndSize("_", 1);
  _trans_map[40] = PyUnicode_FromStringAndSize("_", 1);
  _trans_map[41] = PyUnicode_FromStringAndSize("_", 1);
  _trans_map[42] = PyUnicode_FromStringAndSize("_", 1);
  _trans_map[45] = PyUnicode_FromStringAndSize("_", 1);
  _trans_map[94] = PyUnicode_FromStringAndSize("_", 1);
  _trans_map[126] = PyUnicode_FromStringAndSize("_", 1);
  _trans_map[1025] = PyUnicode_FromStringAndSize("E", 1);
  _trans_map[1030] = PyUnicode_FromStringAndSize("I", 1);
  _trans_map[1031] = PyUnicode_FromStringAndSize("YIu", 3);
  _trans_map[1040] = PyUnicode_FromStringAndSize("A", 1);
  _trans_map[1041] = PyUnicode_FromStringAndSize("B", 1);
  _trans_map[1042] = PyUnicode_FromStringAndSize("V", 1);
  _trans_map[1043] = PyUnicode_FromStringAndSize("G", 1);
  _trans_map[1044] = PyUnicode_FromStringAndSize("D", 1);
  _trans_map[1045] = PyUnicode_FromStringAndSize("E", 1);
  _trans_map[1046] = PyUnicode_FromStringAndSize("J", 1);
  _trans_map[1047] = PyUnicode_FromStringAndSize("Z", 1);
  _trans_map[1048] = PyUnicode_FromStringAndSize("I", 1);
  _trans_map[1049] = PyUnicode_FromStringAndSize("Y", 1);
  _trans_map[1050] = PyUnicode_FromStringAndSize("K", 1);
  _trans_map[1051] = PyUnicode_FromStringAndSize("L", 1);
  _trans_map[1052] = PyUnicode_FromStringAndSize("M", 1);
  _trans_map[1053] = PyUnicode_FromStringAndSize("N", 1);
  _trans_map[1054] = PyUnicode_FromStringAndSize("O", 1);
  _trans_map[1055] = PyUnicode_FromStringAndSize("P", 1);
  _trans_map[1056] = PyUnicode_FromStringAndSize("R", 1);
  _trans_map[1057] = PyUnicode_FromStringAndSize("S", 1);
  _trans_map[1058] = PyUnicode_FromStringAndSize("T", 1);
  _trans_map[1059] = PyUnicode_FromStringAndSize("U", 1);
  _trans_map[1060] = PyUnicode_FromStringAndSize("F", 1);
  _trans_map[1061] = PyUnicode_FromStringAndSize("H", 1);
  _trans_map[1062] = PyUnicode_FromStringAndSize("TS", 2);
  _trans_map[1063] = PyUnicode_FromStringAndSize("Ch", 2);
  _trans_map[1064] = PyUnicode_FromStringAndSize("Sh", 2);
  _trans_map[1065] = PyUnicode_FromStringAndSize("Shch", 4);
  _trans_map[1066] = PyUnicode_FromStringAndSize("I", 1);
  _trans_map[1067] = PyUnicode_FromStringAndSize("Y", 1);
  _trans_map[1068] = PyUnicode_FromStringAndSize("", 0);
  _trans_map[1069] = PyUnicode_FromStringAndSize("E", 1);
  _trans_map[1070] = PyUnicode_FromStringAndSize("YU", 2);
  _trans_map[1071] = PyUnicode_FromStringAndSize("YA", 2);
  _trans_map[1072] = PyUnicode_FromStringAndSize("a", 1);
  _trans_map[1073] = PyUnicode_FromStringAndSize("b", 1);
  _trans_map[1074] = PyUnicode_FromStringAndSize("v", 1);
  _trans_map[1075] = PyUnicode_FromStringAndSize("g", 1);
  _trans_map[1076] = PyUnicode_FromStringAndSize("d", 1);
  _trans_map[1077] = PyUnicode_FromStringAndSize("e", 1);
  _trans_map[1078] = PyUnicode_FromStringAndSize("j", 1);
  _trans_map[1079] = PyUnicode_FromStringAndSize("z", 1);
  _trans_map[1080] = PyUnicode_FromStringAndSize("i", 1);
  _trans_map[1081] = PyUnicode_FromStringAndSize("y", 1);
  _trans_map[1082] = PyUnicode_FromStringAndSize("k", 1);
  _trans_map[1083] = PyUnicode_FromStringAndSize("l", 1);
  _trans_map[1084] = PyUnicode_FromStringAndSize("m", 1);
  _trans_map[1085] = PyUnicode_FromStringAndSize("n", 1);
  _trans_map[1086] = PyUnicode_FromStringAndSize("o", 1);
  _trans_map[1087] = PyUnicode_FromStringAndSize("p", 1);
  _trans_map[1088] = PyUnicode_FromStringAndSize("r", 1);
  _trans_map[1089] = PyUnicode_FromStringAndSize("s", 1);
  _trans_map[1090] = PyUnicode_FromStringAndSize("t", 1);
  _trans_map[1091] = PyUnicode_FromStringAndSize("u", 1);
  _trans_map[1092] = PyUnicode_FromStringAndSize("f", 1);
  _trans_map[1093] = PyUnicode_FromStringAndSize("h", 1);
  _trans_map[1094] = PyUnicode_FromStringAndSize("ts", 2);
  _trans_map[1095] = PyUnicode_FromStringAndSize("ch", 2);
  _trans_map[1096] = PyUnicode_FromStringAndSize("sh", 2);
  _trans_map[1097] = PyUnicode_FromStringAndSize("shch", 4);
  _trans_map[1098] = PyUnicode_FromStringAndSize("i", 1);
  _trans_map[1099] = PyUnicode_FromStringAndSize("y", 1);
  _trans_map[1100] = PyUnicode_FromStringAndSize("", 0);
  _trans_map[1101] = PyUnicode_FromStringAndSize("e", 1);
  _trans_map[1102] = PyUnicode_FromStringAndSize("yu", 2);
  _trans_map[1103] = PyUnicode_FromStringAndSize("ya", 2);
  _trans_map[1105] = PyUnicode_FromStringAndSize("e", 1);
  _trans_map[1110] = PyUnicode_FromStringAndSize("i", 1);
  _trans_map[1111] = PyUnicode_FromStringAndSize("yi", 2);
}

/*******************************************************************************
 *                            Transliter string
 *******************************************************************************
*/

/**
 * Returns NEW REFERENCE
 */
static PyObject * transliterate(PyObject *self, PyObject *args)
{
    // Обьявляем ссылку на нашу строку в аргументах.
    PyObject* ustring;

    if (!PyArg_ParseTuple(args, "U", &ustring))
       return NULL;

    // Удостоверится надо, что наша строка каноническая
    int ready = PyUnicode_READY(ustring);
    // If allocation problem - return with EXC
    if (ready == -1){
      return NULL;
    } 
    
    // Для прохода по строке нам надо узать:
    // длину 1 символа в байтах 
    int ustring_kind = PyUnicode_KIND(ustring);
    // длину всей строки
    Py_ssize_t ustring_size = PyUnicode_GET_LENGTH(ustring);
    // буфер данных для прямого обращения
    void * ustring_data = PyUnicode_DATA(ustring);

    // Создаем масив результатов. Результаты будут хранится в виде питоновских 
    // 1-символьных строк, так как мы не знаем ни KIND результата ни количество 
    // символов в результате (1 символ входной может превращатся в разное 
    // количество выходных)
    PyObject** out_array = (PyObject**)malloc(ustring_size * sizeof(PyObject*));
    Py_ssize_t read_index;
    Py_ssize_t out_size=0;
    Py_UCS4 out_max_char=0;

    // и читать макросом в цикле. Мы тут же следим сколько будет символов в 
    // результате (это предугадать по другому не выйдет) и какой тип результата.
    for (read_index=0; read_index < ustring_size; read_index++)
    {
      // Находим наш символ, что надо транслитировать
      Py_UCS4 to_translit_char = PyUnicode_READ(
        ustring_kind, ustring_data, read_index);

      // Находим транслит в виде Питоновской строки.
      PyObject* translited_str;
      _translit_char(to_translit_char, &translited_str);

      // Записываем результат в наш масив. 
      // Отметим использование ’макроса без проверки’, так как наш список пустой
      out_array[read_index] = translited_str;
      out_size += PyUnicode_GET_SIZE(translited_str);
      Py_UCS4 translit_max_char = PyUnicode_MAX_CHAR_VALUE(translited_str);
      if (translit_max_char>out_max_char)
      {
        out_max_char = translit_max_char;
      }
    }

    PyObject* out_string = PyUnicode_New(out_size, out_max_char);
    int out_kind = PyUnicode_KIND(out_string);
    void* out_data = PyUnicode_DATA(out_string);
    Py_ssize_t out_write_index = 0;

    for (read_index=0; read_index < ustring_size; read_index++) 
    {
      PyObject* substr = out_array[read_index];
      Py_ssize_t substr_size = PyUnicode_GET_SIZE(substr);
      int substr_kind = PyUnicode_KIND(substr);
      void* substr_data = PyUnicode_DATA(substr);
      Py_ssize_t substr_index = 0;
      if (substr_kind == out_kind)
      {
        memcpy(out_data, substr_data, out_kind*substr_size);
      } else 
      {
        for (;substr_index<substr_size;substr_index++)
        {
          PyUnicode_WRITE(
            out_kind, out_data, out_write_index,
            PyUnicode_READ(substr_kind, substr_data, substr_index)
          );
          out_write_index++;
        }
      }
    }
    // PyObject* out_string = PyUnicode_Join(
    //   PyUnicode_FromStringAndSize("", 0),
    //   out_array
    // );
    // Py_DECREF(out_array);
    return out_string;
}


/*******************************************************************************
 *                        Standart module definition
 *******************************************************************************
*/

static PyMethodDef TranslitMethods[] = {
   {"transliterate",  transliterate, METH_VARARGS,
    "Transliterate a unicode string."},
   {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef transliterate_module = {
  PyModuleDef_HEAD_INIT,
  "transliterate",  /* name of module */
  NULL,             /* module documentation,
                     may be NULL */
  -1,               /* size of per-interpreter
                    state of the module,
                    or -1 if the module keeps
                    state in global variables. */
  TranslitMethods
};

PyMODINIT_FUNC PyInit__c_transliterate(void)
{
  _init_translation_map();
  return PyModule_Create(&transliterate_module);
}

