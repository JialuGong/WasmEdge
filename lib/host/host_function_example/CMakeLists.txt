# SPDX-License-Identifier: Apache-2.0
# SPDX-FileCopyrightText: 2019-2022 Second State INC

wasmedge_add_library(wasmedgeHostModuleHostFuncExample
  examplefunc.cpp
  examplemodule.cpp
  myhostfunc.cpp
  myhostmodule.cpp
)
wasmedge_add_library(wasmedgeHostModuleHostFuncMyHost
  myhostfunc.cpp
  myhostmodule.cpp
)

target_link_libraries(wasmedgeHostModuleHostFuncExample
  PUBLIC
  wasmedgeCommon
  wasmedgeSystem
)
target_link_libraries(wasmedgeHostModuleHostFuncMyHost
  PUBLIC
  wasmedgeCommon
  wasmedgeSystem
)
