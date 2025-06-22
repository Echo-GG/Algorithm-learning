算法图解_Notes_Chapter2

sth_wrong_with_the_memory.cpp 能够正常输出运行结果，但在内存分配和释放上存在异常，会导致程序在输出正确排序结果之后异常终止.

ConsoleApplication1.cpp是最常见的选择排序实现方法(C++),但是对比《算法图解》原书中给出的参考python代码出入较大，因为这一实现采用的是原地排序，
而前面提到的内存异常的.cpp文件则还原度更高，且在书写时可以避免使用vector容器手动编写实现了pop,append等函数，力求体现代码思路的完整性，
也希望读者帮助修改该程序中内存异常的部分.

I would appreciate it if you could fix the bug in **sth_wrong_with_the_memory.cpp** without changing my original idea.
