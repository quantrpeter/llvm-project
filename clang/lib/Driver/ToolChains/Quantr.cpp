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

auto QuantrToolChain::buildAssembler() const -> Tool * {
  cout << "buildAssembler" << endl;
  return NULL;
}

auto QuantrToolChain::buildLinker() const -> Tool * {
  cout << "buildLinker" << endl;
  return new tools::Quantr::Linker(*this);
}

void tools::Quantr::Linker::constructLinkAndEmitSpirvCommand(
    Compilation &C, const JobAction &JA, const InputInfoList &Inputs,
    const InputInfo &Output, const llvm::opt::ArgList &Args) const {
  cout << "constructLinkAndEmitSpirvCommand" << endl;
}

void tools::Quantr::Linker::ConstructJob(Compilation &C, const JobAction &JA,
                                         const InputInfo &Output,
                                         const InputInfoList &Inputs,
                                         const ArgList &Args,
                                         const char *LinkingOutput) const {
  cout << "ConstructJob" << endl;
}
