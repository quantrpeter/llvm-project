namespace clang{
	namespace driver{
		namespace toolchains{
			struct LLVM_LIBRARY_VISIBILITY QuantrToolChain : public Generic_ELF{
				QuantrToolChain(const Driver &D, const llvm::Triple &Triple, const llvm::opt::ArgList & Args) : Generic_ELF(D, triple, Args){}

				~QuantrToolChain() override {}

				//Disable the integrated assembler
				bool IsIntegratedAssemblerDefault() const override{return false;}
				bool useIntegratedAs() const override{return false;}

				void AddClangSystemIncludeArgs(const llvm::opt::ArgList &DriverArgs, llvm::opt::ArgStringList &CC1Args)
				const override;

				protected:
				Tool *buildAssembler() const override;
				Tool *buildLinker() const override;
			};
		}
	}
}