// Copyright (c) [2021-2022] [Horizon Robotics][Horizon Bole].
//
// You can use this software according to the terms and conditions of
// the Apache v2.0.
// You may obtain a copy of Apache v2.0. at:
//
//     http: //www.apache.org/licenses/LICENSE-2.0
//
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
// See Apache v2.0 for more details.

#ifndef HLOG_COMPILER_H_
#define HLOG_COMPILER_H_

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define HLOG_EXPORT __attribute__((dllexport))
#define HLOG_IMPORT __attribute__((dllimport))
#else
#define HLOG_EXPORT __declspec(dllexport)
#define HLOG_IMPORT __declspec(dllimport)
#endif

#ifdef HLOG_BUILDING_LIB
#define HLOG_PUBLIC
#else
#ifdef HLOG_BUILDING_DLL
#define HLOG_PUBLIC HLOG_EXPORT
#else
#define HLOG_PUBLIC HLOG_IMPORT
#endif
#endif

#define HLOG_LOCAL

// STL Export warning
#pragma warning(disable : 4251)

#else  // UNIX

#ifdef HLOG_BUILDING_LIB
#define HLOG_PUBLIC
#else
#define HLOG_PUBLIC __attribute__((visibility("default")))
#endif

#define HLOG_LOCAL __attribute__((visibility("hidden")))

#endif

#ifdef HLOG_BUILDING_UTEST
#define UTEST_HLOG_PUBLIC HLOG_PUBLIC
#else
#define UTEST_HLOG_PUBLIC
#endif

#include <memory>
#include <string>

#ifdef __GNUC__
#include <cxxabi.h>
#endif

namespace hobot {
namespace hlog {

template <typename T>
static inline std::string nice_type_name(void) {
  typedef typename std::remove_reference<T>::type TO;
  char* demangled_name = nullptr;
  const char* type_name = typeid(TO).name();

#if defined(__GNUC__) && !defined(NO_CXA_DEMANGLE)
  demangled_name = abi::__cxa_demangle(type_name, nullptr, nullptr, nullptr);
#endif

  std::string s;

  if (demangled_name) {
    s = demangled_name;
    std::free(demangled_name);
  } else {
    s = type_name;
  }

  if (std::is_const<TO>::value) s += " const";
  if (std::is_volatile<TO>::value) s += " volatile";
  if (std::is_lvalue_reference<T>::value)
    s += "&";
  else if (std::is_rvalue_reference<T>::value)
    s += "&&";
  return s;
}

}  // namespace hlog
}  // namespace hobot

#endif  // HLOG_COMPILER_H_
