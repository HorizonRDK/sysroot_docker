// Copyright (c) 2021 Horizon Robotics.All Rights Reserved.
//
// The material in this file is confidential and contains trade secrets
// of Horizon Robotics Inc. This is proprietary information owned by
// Horizon Robotics Inc. No part of this work may be disclosed,
// reproduced, copied, transmitted, or used in any way for any purpose,
// without the express written permission of Horizon Robotics Inc.

#ifndef _EASY_DNN_RESULT_CLASSIFICATION_RESULT_H_
#define _EASY_DNN_RESULT_CLASSIFICATION_RESULT_H_

#include <string>
#include <vector>

#include "easy_dnn/data_structure.h"

namespace hobot {
namespace easy_dnn {

class ClassificationResult : public DNNResult {
 public:
  float max_conf;
  int32_t class_id;
  std::string class_name;
};

class HaloClassificationResult : public DNNResult {
 public:
  std::vector<int8_t> features_;
  void Reset() override { features_.clear(); }
};

}  // namespace easy_dnn
}  // namespace hobot

#endif  // _EASY_DNN_RESULT_CLASSIFICATION_RESULT_H_
