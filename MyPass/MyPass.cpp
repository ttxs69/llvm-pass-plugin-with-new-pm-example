#include "MyPass.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"

using namespace llvm;

PreservedAnalyses MyPass::run(Function &F, FunctionAnalysisManager &AM) {
  errs() << "Function: " << F.getName() << ";Num of args: " << F.arg_size()
         << "\n";
  return PreservedAnalyses::all();
}

llvm::PassPluginLibraryInfo getMyPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "MyPass", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (Name == "mypass") {
                    FPM.addPass(MyPass());
                    return true;
                  }
                  return false;
                });
          }};
}

extern "C" ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() LLVM_ATTRIBUTE_WEAK {
  return getMyPassPluginInfo();
}
