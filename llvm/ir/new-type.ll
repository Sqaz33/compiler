; ModuleID = 'main.bc'
source_filename = "main.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.mystruct = type {i8, i32, [10 x i8]}
@obj = global %struct.mystruct zeroinitializer

define i32 @main() {
  %arr = alloca [5 x i8], align 4
  store [5 x i8] zeroinitializer, [5 x i8]* %arr

  %arr.1.ptr = getelementptr [5 x i8], [5 x i8]* %arr, i32 0, i32 1
  store i8 1, i8* %arr.1.ptr

  %arr.1 = load i8, i8* %arr.1.ptr


  %one = add i8 %arr.1, 48
  call i32 @putchar(i8 %one)

  %lf = add i8 0, 10
  call i32 @putchar(i8 %lf)


  %x = getelementptr %struct.mystruct, %struct.mystruct* @obj, i32 0, i32 2, i32 0
  

  ret i32 0
}

declare i32 @putchar(i8)