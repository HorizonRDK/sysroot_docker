// Copyright (c) 2021 Horizon Robotics.All Rights Reserved.
//
// The material in this file is confidential and contains trade secrets
// of Horizon Robotics Inc. This is proprietary information owned by
// Horizon Robotics Inc. No part of this work may be disclosed,
// reproduced, copied, transmitted, or used in any way for any purpose,
// without the express written permission of Horizon Robotics Inc.

#ifndef _EASY_DNN_TENSOR_UTILS_H_
#define _EASY_DNN_TENSOR_UTILS_H_

#include <memory>
#include <vector>

#include "easy_dnn/data_structure.h"

namespace hobot {
namespace easy_dnn {
class TensorUtils {
 public:
  /**
   * Alloc BPU tensor
   * @param[in] properties
   * @param[in] is_pad_data
   * @param[out] tensor
   * @param[out] data_addr
   * @param[out] mem_size
   * @return 0 if success, return defined error code otherwise
   */
  static int32_t AllocateTensor(std::shared_ptr<DNNTensor> &tensor,
                                std::vector<void *> &data_addr,
                                std::vector<int32_t> &mem_size,
                                hbDNNTensorProperties &properties,
                                bool const &is_pad_data = false);

  /**
   * Flush BPU tensor
   * @param[in] tensor
   * @param[in] flag
   * flag : HB_SYS_MEM_CACHE_INVALIDATE (1), use when BPU write done. CPU read
   * from DDR directly.
   * flag : HB_SYS_MEM_CACHE_CLEAN (2), use before BPU read.
   * Flush CPU cache data to DDR.
   * @return 0 if success, return defined error code otherwise
   */
  static int32_t FlushTensor(std::shared_ptr<DNNTensor> &tensor, int32_t flag);
};

}  // namespace easy_dnn
}  // namespace hobot

#endif  // _EASY_DNN_TENSOR_UTILS_H_
