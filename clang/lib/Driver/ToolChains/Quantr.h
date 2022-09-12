#ifndef LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_QUANTR_H
#define LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_QUANTR_H

#include "Gnu.h"
#include "clang/Driver/ToolChain.h"

namespace clang {
namespace driver {
namespace toolchains {
class LLVM_LIBRARY_VISIBILITY QuantrToolChain : public ToolChain {
public:
  QuantrToolChain(const Driver &D, const llvm::Triple &Triple,
                  const llvm::opt::ArgList &Args);
  ~QuantrToolChain() override;

  bool isPICDefault() const override { return false; }
  bool isPIEDefault(const llvm::opt::ArgList &Args) const override {
    return false;
  }
  bool isPICDefaultForced() const override { return false; }

  // Disable the integrated assembler
  bool IsIntegratedAssemblerDefault() const override { return false; }
  bool useIntegratedAs() const override { return false; }

  //   void
  //   AddClangSystemIncludeArgs(const llvm::opt::ArgList &DriverArgs,
  //                             llvm::opt::ArgStringList &CC1Args) const
  //                             override;

protected:
  Tool *buildAssembler() const override;
  Tool *buildLinker() const override;
};

} // namespace toolchains

namespace tools {
namespace Quantr {

class LLVM_LIBRARY_VISIBILITY Linker : public Tool {
public:
  Linker(const ToolChain &TC) : Tool("Quantr::Linker", "quantr-link", TC) {}

  bool hasIntegratedCPP() const override { return false; }

  void ConstructJob(Compilation &C, const JobAction &JA,
                    const InputInfo &Output, const InputInfoList &Inputs,
                    const llvm::opt::ArgList &TCArgs,
                    const char *LinkingOutput) const override;

private:
  void constructLinkAndEmitSpirvCommand(Compilation &C, const JobAction &JA,
                                        const InputInfoList &Inputs,
                                        const InputInfo &Output,
                                        const llvm::opt::ArgList &Args) const;
};
} // namespace Quantr

} // namespace tools
} // namespace driver
} // namespace clang

#endif