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
  return new tools::Quantr::Assembler(*this);
}

auto QuantrToolChain::buildLinker() const -> Tool * {
  cout << "buildLinker" << endl;
  return new tools::Quantr::Linker(*this);
}

void tools::Quantr::Assembler::constructLinkAndEmitSpirvCommand(
    Compilation &C, const JobAction &JA, const InputInfoList &Inputs,
    const InputInfo &Output, const llvm::opt::ArgList &Args) const {
  cout << "Assembler::constructLinkAndEmitSpirvCommand" << endl;
}

void tools::Quantr::Assembler::ConstructJob(Compilation &C, const JobAction &JA,
                                            const InputInfo &Output,
                                            const InputInfoList &Inputs,
                                            const ArgList &Args,
                                            const char *LinkingOutput) const {
  cout << "Assembler::ConstructJob" << endl;
  cout << "------------------------------------------------------------------------------------" << endl;
  cout << "Input " << Inputs[0].getFilename() << endl;
  FILE *fp=fopen(Inputs[0].getFilename(), "rb");
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  cout << "fsize="<<fsize<<endl;
  fseek(fp, 0, SEEK_SET);
  char *string = (char *)malloc(fsize + 1);
  fread(string, fsize, 1, fp);
  fclose(fp);
  string[fsize] = 0;
  cout<<string<<endl;
  cout << "------------------------------------------------------------------------------------" << endl;
  cout << "Output " << Output.getFilename() << endl;
  cout << "------------------------------------------------------------------------------------" << endl;
  // cout << "LinkingOutput " << LinkingOutput << endl;
  // cout << "------------------------------------------------------------------------------------" << endl;

  ArgStringList CmdArgs;

  // const char *Exec = Args.MakeArgString(getToolChain().GetProgramPath("as"));
  // CmdArgs.push_back("-o");
  // CmdArgs.push_back(Output.getFilename());
  // CmdArgs.push_back(Inputs[0].getFilename());

  const char *Exec = Args.MakeArgString(getToolChain().GetProgramPath("cat"));
  CmdArgs.push_back(Inputs[0].getFilename());
  
  // const char *Exec =
      // Args.MakeArgString("/usr/bin/java -jar assembler.jar xxxxxx");
  C.addCommand(std::make_unique<Command>(JA, *this, ResponseFileSupport::None(),
                                         Exec, CmdArgs, Inputs, Output));
}

void tools::Quantr::Linker::constructLinkAndEmitSpirvCommand(
    Compilation &C, const JobAction &JA, const InputInfoList &Inputs,
    const InputInfo &Output, const llvm::opt::ArgList &Args) const {
  cout << "Linker::constructLinkAndEmitSpirvCommand" << endl;
}

void tools::Quantr::Linker::ConstructJob(Compilation &C, const JobAction &JA,
                                         const InputInfo &Output,
                                         const InputInfoList &Inputs,
                                         const ArgList &Args,
                                         const char *LinkingOutput) const {
  cout << "Linker::ConstructJob" << endl;
}
