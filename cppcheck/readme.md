### CPPCHECK

Для статического анализа будем использовать CPPCHECK

Запуск анализатора
```bash
cppcheck -q --enable=all --inconclusive ../ 2> ./cpp_check_error.txt
```

больше инормации по функционалу здесь:
- http://cppcheck.sourceforge.net/manual.pdf
- https://habrahabr.ru/post/210256/
