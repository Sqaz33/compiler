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
  %1 = icmp ult i32 0, 1
  br i1 %1, label %2, label %3

; bb %2
  %x = add i8 0, 3
  br label %exit

; bb %3
  %y = add i8 0, 4
  br label %exit

exit:
  %z = phi i8 [%x, %2], [%y, %3]
  call void @print_numb(i8 %z)
  call void @print_line_feed()
  ret i32 0

}

declare i32 @getchar() 
declare i32 @putchar(i8)