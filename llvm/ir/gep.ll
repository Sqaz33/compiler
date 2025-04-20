; ModuleID = 'main.c'
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"


@fibarr = global [10 x i32] zeroinitializer
define void @fill() {
    entry:
        %f0 = getelementptr [10 x i32], [10 x i32]* @fibarr, i64 0, i64 0
        %f1 = getelementptr [10 x i32], [10 x i32]* @fibarr, i64 0, i64 1
        store i32 1, i32* %f0
        store i32 1, i32* %f1
        br label %for.cond
    for.cond:
        %i.0 = phi i64 [2, %entry], [%inc, %for.body]
        %cmp = icmp ult i64 %i.0, 10
        br i1 %cmp, label %for.body, label %for.end

    for.body:
        %sub1 = sub i64 %i.0, 1
        %idx1 = getelementptr [10 x i32], [10 x i32]* @fibarr, i64 0, i64 %sub1
        %0 = load i32, i32* %idx1

        %sub2 = sub i64 %i.0, 2
        %idx2 = getelementptr [10 x i32], [10 x i32]* @fibarr, i64 0, i64 %sub2
        %1 = load i32, i32* %idx2

        %add = add i32 %0, %1
        %idx3 = getelementptr [10 x i32], [10 x i32]* @fibarr, i64 0, i64 %i.0
        store i32 %add, i32* %idx3

        %inc = add i64 %i.0, 1
        br label %for.cond
    
    for.end: 
        ret void
}

define dso_local i32 @main() #0 {
  ret i32 0
}

