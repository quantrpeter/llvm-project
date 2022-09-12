#include "Quantr.h"

#include "CommonArgs.h"
#include "clang/Driver/Compilation.h"
#include "clang/Driver/Options.h"
#include "llvm/Option/ArgList.h"
#include <iostream>

using namespace clang::driver;
using namespace clang::driver::toolchains;
using namespace llvm::opt;
using namespace clang;
using namespace std;

QuantrToolChain::QuantrToolChain(const Driver &D, const llvm::Triple &Triple,
                                 const ArgList &Args)
    : ToolChain(D, Triple, Args) {
  cout << "QuantrToolChain" << endl;
}

QuantrToolChain::~QuantrToolChain() {
  cout << "QuantrToolChain destructor" << endl;
}
