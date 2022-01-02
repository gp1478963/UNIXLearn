//
// Created by gp147 on 2022/1/3.
//

#ifndef UNIXLEARN_PRINTF_MESSAGE_H
#define UNIXLEARN_PRINTF_MESSAGE_H

#include "bits/stdc++.h"

class printf_message {
 public:
  printf_message() = default;
  explicit printf_message(std::string message_str) :message_about_(std::move(message_str)) {}
  ~printf_message() = default;
  friend std::ostream& operator<<(std::ostream& os,printf_message& message ){
    return message.PrintfMessage(os);
  }
 private:
  std::ostream& PrintfMessage(std::ostream& os);

 private:
  std::string message_about_;

};



#endif //UNIXLEARN_PRINTF_MESSAGE_H
