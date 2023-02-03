// Copyright (c) 2021 Horizon Robotics.All Rights Reserved.
//
// The material in this file is confidential and contains trade secrets
// of Horizon Robotics Inc. This is proprietary information owned by
// Horizon Robotics Inc. No part of this work may be disclosed,
// reproduced, copied, transmitted, or used in any way for any purpose,
// without the express written permission of Horizon Robotics Inc.

#ifndef _EASY_DNN_RESULT_PARSING_RESULT_H_
#define _EASY_DNN_RESULT_PARSING_RESULT_H_

#include <vector>

#include "easy_dnn/data_structure.h"

namespace hobot {
namespace easy_dnn {

struct DNNDimension {
  int32_t height;
  int32_t width;
  int32_t channel;
};

class DepthResult : public DNNResult {
 public:
  std::vector<float> depth;
  int32_t height;
  int32_t width;
  int32_t channel;
  void Reset() override { depth.clear(); }
};

class ElevationResult : public DNNResult {
 public:
  std::vector<float> elevation;
  int32_t height;
  int32_t width;
  int32_t channel;
  void Reset() override { elevation.clear(); }
};

class ParsingResult : public DNNResult {
 public:
  std::vector<uint8_t> data;
  int32_t height;
  int32_t width;
  int32_t channel;

  void Reset() override { data.clear(); }
};

class ResidualResult : public DNNResult {
 public:
  std::vector<std::vector<float>> data;
  int32_t height;
  int32_t width;
  int32_t channel;

  void Reset() override { data.clear(); }
};

}  // namespace easy_dnn
}  // namespace hobot
#endif  // _EASY_DNN_RESULT_PARSING_RESULT_H_
