//
// Created by pkwv on 6/5/18.
//


#include <gtest/include/gtest/gtest.h>
#include "data_structure.h"
#include "parameter_initializer.h"

namespace xLearn {

TEST(PARAMETER_INIT_TEST, Init_fm) {
  int aux_size = 2;
  std::string score_func = "fm";
  index_t num_K = 6;
  index_t num_field = 1;
  real_t scale = 1.0;
  real_t* param_v = nullptr;
  index_t k_alinged = ceil((real_t)num_K / kAlign) * kAlign;
  int ret = posix_memalign((void**)&param_v, kAlignByte,
                           k_alinged * aux_size * sizeof(real_t));
  CHECK_EQ(ret, 0);
  ParameterInitializer::Get()->InitializeLatentFactor(param_v, aux_size, score_func, num_K, num_field, scale);
  for (index_t i = k_alinged; i < k_alinged * aux_size; ++ i) {
    EXPECT_FLOAT_EQ(param_v[i], 1.0);
  }
}

}

