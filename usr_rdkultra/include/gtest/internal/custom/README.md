English| [简体中文](./README_cn.md)

# Customization Points

自定义目录是自定义用户配置的注入点。

## Header `gtest.h`

### The following macros can be defined:

*   `GTEST_OS_STACK_TRACE_GETTER_` - An implementation 的名称 of `OsStackTraceGetterInterface`.
*   `GTEST_CUSTOM_TEMPDIR_FUNCTION_` - `testing::TempDir()` 的覆盖。查看 `testing::TempDir` 以获取语义和签名。

## Header `gtest-port.h`

下列宏可以被定义：

### 与标志相关的宏：

*   `GTEST_FLAG(flag_name)`
*   `GTEST_USE_OWN_FLAGFILE_FLAG_` - 当系统提供自己的标志文件标志解析时定义为 0。
*   `GTEST_DECLARE_bool_(name)`
*   `GTEST_DECLARE_int32_(name)`
*   `GTEST_DECLARE_string_(name)`
*   `GTEST_DEFINE_bool_(name, default_val, doc)`
*   `GTEST_DEFINE_int32_(name, default_val, doc)`
*   `GTEST_DEFINE_string_(name, default_val, doc)`

### 日志：

*   `GTEST_LOG_(severity)`
*   `GTEST_CHECK_(condition)`
*   函数 `LogToStderr()` 和 `FlushInfoLog()` 也必须提供。

### 线程：

*   `GTEST_HAS_NOTIFICATION_` - 如果已经提供通知，则启用。
*   `GTEST_HAS_MUTEX_AND_THREAD_LOCAL_` - 如果已经提供 `Mutex` 和 `ThreadLocal` 则启用。还必须提供 `GTEST_DECLARE_STATIC_MUTEX_(mutex)` 和 `GTEST_DEFINE_STATIC_MUTEX_(mutex)`
*   `GTEST_EXCLUSIVE_LOCK_REQUIRED_(locks)`
*   `GTEST_LOCK_EXCLUDED_(locks)`

### 底层库支持功能

*   `GTEST_HAS_CXXABI_H_`

### 导出 API 符号:*   `GTEST_API_` - 用于导出符号的修饰符。

## Header `gtest-printers.h`

*   查看 `gtest/gtest-printers.h` 中的文档，了解如何定义自定义打印程序的详细信息。