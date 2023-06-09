// Copyright (c) 2021 Horizon Robotics.All Rights Reserved.
//
// The material in this file is confidential and contains trade secrets
// of Horizon Robotics Inc. This is proprietary information owned by
// Horizon Robotics Inc. No part of this work may be disclosed,
// reproduced, copied, transmitted, or used in any way for any purpose,
// without the express written permission of Horizon Robotics Inc.

#ifndef _EASY_DNN_RESULT_DETECTION_RESULT_H_
#define _EASY_DNN_RESULT_DETECTION_RESULT_H_

#include <vector>

#include "easy_dnn/data_structure.h"

namespace hobot {
namespace easy_dnn {

struct PerceptionRect {
 public:
  float left;
  float top;
  float right;
  float bottom;
  float conf;
  int32_t type;
  int32_t perception_type;
  int32_t conf_scale;
  int32_t expand;
  int32_t branch;
  friend bool operator>(const PerceptionRect &lhs, const PerceptionRect &rhs) {
    return (lhs.conf > rhs.conf);
  }
};

class DetectionResult : public DNNResult {
 public:
  std::vector<PerceptionRect> boxes;
  void Reset() override { boxes.clear(); }
};

struct Bbox3D {
  uint16_t cls = 0;
  uint32_t grid_idx = 0;
  uint32_t grid_x = 0;
  uint32_t grid_y = 0;
  float score = 0.0;
  float x = 0.0;
  float y = 0.0;
  float z = 0.0;
  float w = 0.0;
  float l = 0.0;
  float h = 0.0;
  float d = 0.0;
  float r = 0.0;
  std::vector<std::vector<float>> corners2d;  // undistort, img ord
  std::vector<std::vector<float>> corners3d;  // undistort, camera ord
  inline static bool greater(const Bbox3D &a, const Bbox3D &b) {
    return a.score > b.score;
  }
  Bbox3D() {
    corners2d.resize(8, std::vector<float>(2));
    corners3d.resize(8, std::vector<float>(3));
  }
};

class Bev3DResult : public DNNResult {
 public:
  Bev3DResult() = default;
  void Reset() override {
    bbox3d.clear();
    feature_map.clear();
  }

 public:
  std::vector<Bbox3D> bbox3d;
  std::vector<std::vector<float>> feature_map;
};

class Filter2DResult : public DNNResult {
 public:
  std::vector<PerceptionRect> boxes;

  void Reset() override { boxes.clear(); }
};

class Real3dResult : public DNNResult {
 public:
  Real3dResult() = default;
  void Reset() override { bbox3d.clear(); }

 public:
  std::vector<Bbox3D> bbox3d;
};

}  // namespace easy_dnn
}  // namespace hobot

#endif  // _EASY_DNN_RESULT_DETECTION_RESULT_H_
