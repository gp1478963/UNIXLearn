//
// Created by gp147 on 2022/1/2.
//

#include "../Linux_about/unix_interface_test.h"
#include <gtest/gtest.h>
#include <vector>
#include <numeric>
/**
 * @brief 测试单个函数
 */
TEST(TestS, AddFunc){
  std::vector<int> nums{1,2,3,4,5};
  auto sum = std::accumulate(nums.begin(), nums.end(), 0);
  EXPECT_EQ(sum, 15);
}

int
main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
