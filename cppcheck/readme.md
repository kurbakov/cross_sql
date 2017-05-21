### CPPCHECK

Для статического анализа будем использовать CPPCHECK

Запуск анализатора
```bash
cppcheck -q --enable=all --inconclusive ../ 2> ./cpp_check_error.txt
```

