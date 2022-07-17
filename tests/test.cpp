#include "pch.h"
#include "../vibe templates library/vector.hpp"

#include<string>

using namespace vtl;

TEST(vector, simple_construct_base_types) {
    ASSERT_NO_THROW(vector<bool> v);
    ASSERT_NO_THROW(vector<char> v);
    ASSERT_NO_THROW(vector<int> v);
    ASSERT_NO_THROW(vector<float> v);
    ASSERT_NO_THROW(vector<double> v);
}