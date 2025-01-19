# LLVM pass plugin out of source with new pass manager

## Prerequsite
- LLVM
```shell
brew install llvm
```
- cmake
```shell
brew install cmake
```

## build
```shell
cmake -B build .
```

## run
```shell
opt --disable-output --load-pass-plugin=build/MyPass/libMyPass.so -p mypass sum.ll
```
### output
```
Function: sum;Num of args: 2
```

## if you want to generate sum.ll
```shell
clang -emit-llvm -S sum.c -o sum.ll -mllvm -disable-llvm-optzns -O1
```
`-mllvm -disable-llvm-optzns -O1` is required for generate IR for future optimize

if use `-O0`, the function will be arributed with `optnone`, and the pass we wrote will not be used.

## Reference:
- https://llvm.org/docs/CMake.html
- https://llvm.org/docs/WritingAnLLVMNewPMPass.html
- https://github.com/banach-space/llvm-tutor
