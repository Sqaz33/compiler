; ModuleID = 'main.c'
source_filename = "main.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"


; Function Attrs: noinline nounwind optnone uwtable
define i32 @main() #0 {
  %x = alloca [10 x i32], align 4 ; указатель на стеке
  store [10 x i32] zeroinitializer, [10 x i32]* %x 

  %y = getelementptr [10 x i32], [10 x i32]* %x, i32 0, i32 0
  store i32 1, i32* %y

  %z = load i32, i32* %y
  %c = add i32 %z, 48
  call i32 @putchar(i32 %c)
  call i32 @putchar(i32 10)
  ret i32 0
}

declare i32 @putchar(i32 noundef) #1

