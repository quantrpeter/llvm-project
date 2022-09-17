//===-- Quantr.cpp - Example Transformations --------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "llvm/Transforms/Utils/Quantr.h"

using namespace llvm;

PreservedAnalyses QuantrPass::run(Function &F,
                                      FunctionAnalysisManager &AM) {
  errs() << "Quantr="<<F.getName() << "\n";
  return PreservedAnalyses::all();
}
