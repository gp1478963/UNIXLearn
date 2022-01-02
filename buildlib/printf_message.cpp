//
// Created by gp147 on 2022/1/3.
//

#include "printf_message.h"

std::ostream &printf_message::PrintfMessage(std::ostream &os) {
  return os << this->message_about_;
}
