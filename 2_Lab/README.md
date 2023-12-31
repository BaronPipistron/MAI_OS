# Lab Work №2

### Variant 2

### Цель работы
```
Целью является приобретение практических навыков в:
    - Управление потоками в ОС 
    - Обеспечение синхронизации между потоками    
```

### Задание:
```
Составить программу на языке C/C++, обрабатывающую данные в многопоточном режиме. При 
обработки использовать стандартные средства создания потоков операционной системы 
(Windows/Unix). Ограничение максимального количества потоков, работающих в один момент 
времени, должно быть задано ключом запуска вашей программы.

Так же необходимо уметь продемонстрировать количество потоков, используемое вашей 
программой с помощью стандартных средств операционной системы.

В отчете привести исследование зависимости ускорения и эффективности алгоритма от входных 
данных и количества потоков. Получившиеся результаты необходимо объяснить.
```

### Задание варианта:
```
Отсортировать массив целых чисел при помощи параллельного алгоритма быстрой 
сортировки
```

### Команды для запуска:
Build project:
```
make build
```

Run program:
```
make run threads={THREADS_COUNT}
```

Check strace:
```
make strace
```

Generate test data:
```
make generate-test
```

Show graphic with statistic: Ox - Number of threads, Oy - Time [ms]
```
make show-graphic
```

Clean
```
make clean
```