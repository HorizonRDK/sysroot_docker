// Copyright (c) 2021 Horizon Robotics.All Rights Reserved.
//
// The material in this file is confidential and contains trade secrets
// of Horizon Robotics Inc. This is proprietary information owned by
// Horizon Robotics Inc. No part of this work may be disclosed,
// reproduced, copied, transmitted, or used in any way for any purpose,
// without the express written permission of Horizon Robotics Inc.

#ifndef _EASY_DNN_DESCRIPTION_H_
#define _EASY_DNN_DESCRIPTION_H_

#include <functional>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "any_utils.h"

namespace hobot {
namespace easy_dnn {

using ParamMap = AnyMap;

class Model;
class InputProcessor;
class OutputParser;

/**
 * Base description
 */
class Description {
 public:
  Description(Model *model, int32_t index, std::string type)
      : model_(model), index_(index), type_(std::move(type)) {}

  /**
   * Get model, kept for flexibility
   * @return model
   */
  inline Model *GetModel() { return model_; }

  /**
   * Set model
   * @param[in] model
   */
  inline void SetModel(Model *model) { model_ = model; }

  /**
   * Get input or output branch index, kept for flexibility
   * @return index
   */
  inline int32_t GetIndex() const { return index_; }

  /**
   * Set index, kept for flexibility
   * @param[in] index
   */
  inline void SetIndex(int32_t index) { index_ = index; }

  /**
   * Get description type, kept for flexibility
   * @return type
   */
  inline std::string &GetType() { return type_; }

  /**
   * Set type, kept for flexibility
   * @param[in] type
   */
  inline void SetType(const std::string &type) { type_ = type; }

  /**
   * Get param by key
   * @param[in] key
   * @param[out] value
   */
  template <typename ParamType>
  int32_t GetParam(ParamType &value, std::string const &key) {
    return params_.GetValue(value, key);
  }

  /**
   * Set param by key
   * @param[in] key
   * @param[in] value
   */
  template <typename ParamType>
  int32_t SetParam(std::string const &key, ParamType const &value) {
    return params_.SetValue(key, value);
  }

  /**
   * Update param by key
   * @param[in] key
   * @param[in] value
   */
  template <typename ParamType>
  int32_t UpdateParam(std::string const &key, ParamType const &value) {
    return params_.UpdateValue(key, value);
  }

  virtual ~Description() = default;

 protected:
  // members just for flexibility
  Model *model_;
  int32_t index_;
  std::string type_;
  ParamMap params_;
};

/**
 * Base input description
 */
class InputDescription : public Description {
 public:
  InputDescription(Model *model, int32_t index, std::string type = "")
      : Description(model, index, std::move(type)) {}
  ~InputDescription() override = default;
};

/**
 * Base output description
 */
class OutputDescription : public Description {
 public:
  OutputDescription(Model *model, int32_t index, std::string type = "")
      : Description(model, index, std::move(type)) {}
  /**
   * Get dependencies output branch
   * @return dependencies
   */
  std::vector<int32_t> &GetDependencies() { return dependencies_; }

  ~OutputDescription() override = default;

 protected:
  std::vector<int32_t> dependencies_;
};

}  // namespace easy_dnn
}  // namespace hobot

#endif  // _EASY_DNN_DESCRIPTION_H_
