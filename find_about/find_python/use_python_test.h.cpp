//
// Created by gp147 on 2022/1/3.
//

#include <Python.h>
#include <locale.h>
#include <string>
int
main(int argc, char* argv[]){
  std::string argv_index_o (argv[0]);
  std::string curLocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, "chs");

  auto p_str = argv_index_o.c_str();

  std::size_t char_num = argv_index_o.size()+1;

  wchar_t* dest = new wchar_t[char_num];
  mbstowcs_s(NULL,dest,char_num,argv_index_o.c_str(),char_num);
  std::wstring w_s(dest);
  delete[] dest;
  setlocale(LC_ALL,curLocale.c_str());

  Py_SetProgramName(w_s.c_str());
  Py_Initialize();
  PyRun_SimpleString("from time import time, ctime\n"
                     "print 'Today is',ctime(time())\n");
  Py_Finalize();
  return 0;
}

