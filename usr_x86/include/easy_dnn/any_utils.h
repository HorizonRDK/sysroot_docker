// Copyright (c) 2021 Horizon Robotics.All Rights Reserved.
//
// The material in this file is confidential and contains trade secrets
// of Horizon Robotics Inc. This is proprietary information owned by
// Horizon Robotics Inc. No part of this work may be disclosed,
// reproduced, copied, transmitted, or used in any way for any purpose,
// without the express written permission of Horizon Robotics Inc.

#ifndef _EASY_DNN_ANY_UTILS_H_
#define _EASY_DNN_ANY_UTILS_H_

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

#include "status.h"

namespace hobot {
namespace easy_dnn {

class AnyType final {
 public:
  struct DataHolderBase {
    virtual ~DataHolderBase() = default;
    virtual std::type_info const &type() const = 0;
  };

  template <typename DType>
  struct DataHolder : DataHolderBase {
    explicit DataHolder(DType data) : data_{std::move(data)} {}
    DType data_;
    std::type_info const &type() const override { return typeid(DType); }
  };

  AnyType() : data_ptr_{nullptr} {}
  ~AnyType() {}

  AnyType(AnyType const &other) : data_ptr_(other.data_ptr_) {}

  AnyType(AnyType &&other) noexcept { other.swap(*this); }

  template <typename DType,
            typename DecayType = typename std::decay<DType>::type,
            typename std::enable_if<!std::is_same<DecayType, AnyType>::value,
                                    int32_t>::type = 0>
  explicit AnyType(DType &&value) noexcept
      : data_ptr_{new DataHolder<DecayType>(std::forward<DType>(value))} {}

  AnyType &operator=(AnyType const &other) {
    AnyType tmp{other};
    tmp.swap(*this);
    return *this;
  }

  AnyType &operator=(AnyType &&other) noexcept {
    other.swap(*this);
    return *this;
  }

  template <typename DType,
            typename DecayType = typename std::decay<DType>::type,
            typename std::enable_if<!std::is_same<DecayType, AnyType>::value,
                                    int32_t>::type = 0>
  AnyType &operator=(DType &&value) {
    AnyType tmp{std::move(value)};
    tmp.swap(*this);
    return *this;
  }

  void swap(AnyType &other) noexcept { std::swap(data_ptr_, other.data_ptr_); }

  template <typename DType>
  int32_t Get(DType &var) const {
    if (data_ptr_ == nullptr) {
      return DNN_INVALID_ARGUMENT;
    }

    if (data_ptr_->type() == typeid(typename std::decay<DType>::type)) {
      var = static_cast<AnyType::DataHolder<DType> *>(data_ptr_.get())->data_;
      return DNN_SUCCESS;
    } else {
      return DNN_INVALID_ARGUMENT;
    }
  }

 private:
  std::shared_ptr<DataHolderBase> data_ptr_;
};

inline void swap(AnyType &x, AnyType &y) noexcept { x.swap(y); }

class AnyMap final {
 public:
  AnyMap() {}
  ~AnyMap() { data_.clear(); }

  template <typename DType>
  int32_t GetValue(DType &value, std::string const &key) {
    if (key.empty()) {
      return DNN_INVALID_ARGUMENT;
    }

    auto it = data_.find(key);
    if (it != data_.end()) {
      return it->second.Get(value);
    }

    return DNN_INVALID_ARGUMENT;
  }

  template <typename DType>
  int32_t SetValue(std::string const &key, DType const &value) {
    if (key.empty()) {
      return DNN_INVALID_ARGUMENT;
    }

    data_[key] = value;
    return DNN_SUCCESS;
  }

  template <typename DType>
  int32_t UpdateValue(std::string const &key, DType const &value) {
    if (data_.count(key) == 0) {
      return DNN_INVALID_ARGUMENT;
    }
    return SetValue(key, value);
  }

  void Clear() { data_.clear(); }

 private:
  std::unordered_map<std::string, AnyType> data_;
};

}  // namespace easy_dnn
}  // namespace hobot

#endif  // _EASY_DNN_ANY_UTILS_H_
