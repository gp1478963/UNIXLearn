//
// Created by gp147 on 2022/1/1.
//

#ifndef UNIXLEARN_UNIX_INTERFACE_TEST_H
#define UNIXLEARN_UNIX_INTERFACE_TEST_H
#include <cstdio>
#include <dirent.h>
//c++ include
#include "bits/stdc++.h"
template<typename ContainerType>
[[maybe_unused]] void PrintfEveryThing(ContainerType conter){
  for(const auto& val : conter){
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

class [[maybe_unused]] unix_interface_test {
 public:
  unix_interface_test() = default;
  ~unix_interface_test() = default;

  [[maybe_unused]] static void QueryAllSubDir(const std::string& query_dir){
    if(query_dir.empty()) return;
    ::DIR *dp = ::opendir(query_dir.c_str());
    if(dp == nullptr) {
      std::cout << "open dir error" << std::endl;
      return;
    }
    struct dirent *dirent;
    while((dirent = ::readdir(dp))){
      std::cout << dirent->d_name << std::endl;
    }
    ::closedir(dp);
  }
 private:
};


#endif //UNIXLEARN_UNIX_INTERFACE_TEST_H
