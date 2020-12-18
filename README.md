# get_next_line
## Полезные ссылки
1. [Очень полезные лекции по памяти](https://www.youtube.com/watch?v=_8-ht2AKyH4)
2. [Гайд для новичков в notion](https://www.notion.so/F-A-Q-21-a53b71ace3e44d00974191172179fece#bcc22588664e4cf3bb331706bb054d0c)
3. [Гайд для новичков на github](https://github.com/daniiomir/faq_for_school_21#guest)
4. [Гайд по настройке (Cline)](https://www.notion.so/Clion-Make-it-friendly-again-a1f07941b3e8419291184c7b9acee204)
5. [Лекции по get_next_line](https://www.notion.so/get_next_line-59fb1381311b4867b4cfaeec5b94c193)
6. [Теория по утечкам и программам (Valgrind, Leaks, Objdump)](https://github.com/daniiomir/faq_for_school_21/blob/master/docs/memory_leaks_amatilda.pdf)
7. [Теория по static variables](https://en.wikipedia.org/wiki/Static_variable)
8. [Про EOF](https://habr.com/ru/company/ruvds/blog/491700/#:~:text=EOF%20%E2%80%94%20%D1%8D%D1%82%D0%BE%20%D0%BD%D0%B5%20%D1%81%D0%B8%D0%BC%D0%B2%D0%BE%D0%BB.,%D1%84%D0%B0%D0%B9%D0%BB%D0%BE%D0%B2%20%D0%BD%D0%B5%D1%82%20%D0%BD%D0%B5%D0%BA%D0%BE%D0%B5%D0%B3%D0%BE%20%D0%BE%D1%81%D0%BE%D0%B1%D0%BE%D0%B3%D0%BE%20%D1%81%D0%B8%D0%BC%D0%B2%D0%BE%D0%BB%D0%B0.)  
9. [Теория по Valgrind](http://alexott.net/ru/linux/valgrind/Valgrind.html)

## Расшифровка результатов Valgrind  
При окончании работы программы valgrind выдает сводную таблицу, описывающую количество найденных ошибок, а также выделение памяти в программе, например:

ERROR SUMMARY: 2569904 errors from 493 contexts (suppressed: 17962 from 9)  
malloc/free: in use at exit: 85,066,939 bytes in 313,004 blocks.  
malloc/free: 10,552,914 allocs, 10,239,910 frees, 565,747,810 bytes allocated.  
For counts of detected errors, rerun with: -v. 
searching for pointers to 313,004 not-freed blocks.  
checked 117,623,772 bytes.  


И в самом конце отчета, выдается сводная таблица по каждому из типов ошибок работы с памятью:  

LEAK SUMMARY:  
   definitely lost: 2,260 bytes in 47 blocks.  
   indirectly lost: 1,680 bytes in 66 blocks.  
     possibly lost: 2,703,124 bytes in 13,791 blocks.  
   still reachable: 82,359,875 bytes in 299,100 blocks.  
        suppressed: 0 bytes in 0 blocks.  
        
Definitely lost означает, что valgrind нашел область памяти, на которую нет указателей, т.е. программист не освободил память, при выходе указателя за область видимости. Possibly lost показывает, что найден указатель, указывающий на часть области памяти, но valgrind не уверен в том, что указатель на начало области памяти до сих пор существует (это может происходить в тех случаях, когда программист вручную управляет указателями). Still reachable обычно означает, что valgrind нашел указатель на начало не освобожденного блока памяти, что во многих случаях связано с выделением глобальных переменных и т.п. вещей. Обычно эта информация показывается только при указании опции --show-reachable со значением yes.  

Между двумя этими таблицами выдаются данные по каждой из найденных ошибок работы с памятью, вида:  

756 bytes in 27 blocks are definitely lost in loss record 1,077 of 1,267. 
   at 0x4022AB8: malloc (vg_replace_malloc.c:207)  
   by 0x7C485DA: __libc_res_nsend (res_send.c:425)  
   by 0x7C47276: __libc_res_nquery (res_query.c:171)  
   by 0x7C47B5B: __res_nquery (res_query.c:223)  
   by 0x834A618: LookUp::LookUp(std::string&) (LookUp.cpp:83)  
   by 0x8637C29: ClientThread::Connect(LogFileEntry&) (ClientThread.cpp:359)  
   by 0x86394D5: ClientThread::Run() (ClientThread.cpp:215)  
   by 0x80FD839: Thread::StartRunLoop(void*) (Thread.cpp:315)  
   by 0x4163FD9: start_thread (pthread_create.c:297)  
   by 0x43843AD: clone (in /usr/lib/debug/libc-2.7.so)  
   
Первой строкой идет описание ошибки, вместе с указанием номера блока в списке потенциально потерянных блоков памяти, а также размером "потерянного" блока памяти. "Важность" ошибки соответствует описанию в итоговой таблице. После строки описания, приводится стек вызовов функций, которые привели к возникновению "потерянного" блока памяти. Этот список достаточно подробен для того, чтобы обнаружить точное место возникновения данной утечки памяти.
