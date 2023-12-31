# KP

### Variant 14

### Аллокаторы памяти
```
Исследование 2 аллокаторов памяти: необходимо реализовать два алгоритма аллокации памяти и 
сравнить их по следующим характеристикам:
    - Фактор использования
    - Скорость выделения блоков
    - Скорость освобождения блоков
    - Простота использования аллокатора

Каждый аллокатор памяти должен иметь функции аналогичные стандартным функциям free и 
malloc (realloc, опционально).  Перед работой каждый аллокатор инициализируется свободными 
страницами памяти, выделенными стандартными средствами ядра. Необходимо самостоятельно 
разработать стратегию тестирования для определения ключевых характеристик аллокаторов 
памяти. При тестировании нужно свести к минимуму потери точности из-за накладных расходов 
при измерении ключевых характеристик, описанных выше.

В отчете необходимо отобразить следующее:
    - Подробное описание каждого из исследуемых алгоритмов
    - Процесс тестирования
    - Обоснование подхода тестирования
    - Результаты тестирования
    - Заключение по проведенной работе
```

```
Сравнение алгоритмов аллокаторов памяти (детальное описание задания описано выше). Каждый 
аллокатор должен обладать следующим интерфейсом (могут быть отличия в зависимости от 
особенностей алгоритма):
    - Allocator* createMemoryAllocator(void *realMemory, size_t memory_size) (создание 
      аллокатора памяти размера memory_size)
    - void* alloc(Allocator * allocator, size_t block_size) (выделение памяти при помощи 
      аллокатора размера block_size)
    - void* free(Allocator * allocator, void * block) (возвращает выделенную память аллокатору)
```

### Задание варианта
```
Необходимо сравнить два алгоритма аллокации: списки свободных блоков (первое 
подходящее) и алгоритм Мак-Кьюзи-Кэрелса
```

### Команды для запуска:
Build project:
```
make build
```

Run program:
```
make run
```

Check strace:
```
make strace
```