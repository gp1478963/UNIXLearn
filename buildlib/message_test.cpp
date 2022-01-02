//
// Created by gp147 on 2022/1/3.
//

#include "printf_message.h"

int
main(){
  printf_message message_first("cmake");
  printf_message message_second("hello");
  std::cout << message_first << " " <<  message_second << std::endl;
  return 0;
}