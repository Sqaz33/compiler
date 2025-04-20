target triple = "x86_64-pc-linux-gnu"

@LINE_FEED = global i8 10

; печать цифры
define void @print_numb(i8) { 
  %c = add i8 48, %0
  call i32 @putchar(i8 %c)
  ret void
}

; печать перевода строки
define void @print_line_feed() { 
  %lf = load i8, i8* @LINE_FEED
  call i32 @putchar(i8 %lf)
  ret void
}

define i32 @main() {
  %arr = alloca [5 x i8], align 4
  store [5 x i8] zeroinitializer, [5 x i8]* %arr

  %el.0_ptr = getelementptr [5 x i8], [5 x i8]* %arr, i32 0, i32 0
  %el.0 = load i8, i8* %el.0_ptr

  call void @print_numb(i8 %el.0)
  call void @print_line_feed()

  store i8 5, i8* %el.0_ptr
  %el.0.1 = load i8, i8* %el.0_ptr
  call void @print_numb(i8 %el.0.1)
  call void @print_line_feed()

  ret i32 0
}

declare i32 @putchar(i8)