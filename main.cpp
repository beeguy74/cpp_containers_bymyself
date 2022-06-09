#include <iostream>
#include "gtest/gtest.h"
#include "iterator_traits.hpp"

TEST(HelloTest, BasicAssertions) {
    int kek[4] = {1, 2, 3, 4};
    ft::reverse_iterator<int *> vasya(kek);
    for (int i = 1; i < 5; i++){
        ASSERT_TRUE(*(vasya--) == i);
    }
}
