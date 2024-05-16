# Отчет по РК 2
## Create new repository
```
> cd Trener-Egor/workspace/
> mkdir rk_2 && cd rk_2
> git init
подсказка: Using 'master' as the name for the initial branch. This default branch name
подсказка: is subject to change. To configure the initial branch name to use in all
подсказка: of your new repositories, which will suppress this warning, call:
подсказка: 
подсказка: 	git config --global init.defaultBranch <name>
подсказка: 
подсказка: Names commonly chosen instead of 'master' are 'main', 'trunk' and
подсказка: 'development'. The just-created branch can be renamed via this command:
подсказка: 
подсказка: 	git branch -m <name>
Инициализирован пустой репозиторий Git в /home/egor/Trener-Egor/workspace/rk_2/.git/
> gh repo create Trener-Egor/RK_2 --public
✓ Created repository Trener-Egor/RK_2 on GitHub
> echo "# TIMP RK2" > README.md
> git status
Текущая ветка: master

Еще нет коммитов

Неотслеживаемые файлы:
  (используйте «git add <файл>...», чтобы добавить в то, что будет включено в коммит)
	README.md

индекс пуст, но есть неотслеживаемые файлы
(используйте «git add», чтобы проиндексировать их)
> git add . && git commit -m "first commit"
[master (корневой коммит) 0d2adad] first commit
 2 files changed, 38 insertions(+)
 create mode 100644 README.md
 create mode 100644 REPORT.md
> git branch -M main 
> git remote add origin https://github.com/Trener-Egor/RK_2.git
> git push origin main
Перечисление объектов: 4, готово.
Подсчет объектов: 100% (4/4), готово.
Пtouch main.cpp
ри сжатии изменений используется до 4 потоков
Сжатие объектов: 100% (3/3), готово.
Запись объектов: 100% (4/4), 994 байта | 76.00 КиБ/с, готово.
Всего 4 (изменений 0), повторно использовано 0 (изменений 0), повторно использовано пакетов 0
To https://github.com/Trener-Egor/RK_2.git
 * [new branch]      main -> main
```

## Add c++ source file
```
> mkdir source && cd source
> touch main.cpp
> nvim main.cpp
// Исходный код берется из https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/memento.cpp
```

## Create CMakeLists.txt

```
> cat > CMakeLists.txt <<EOF
> cmake_minimum_required(VERSION 3.10)

project(rk_2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER g++)

# Указываем папку с исходными файлами
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source)

# Указываем исходный файл
add_executable(rk_2 ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp) 

EOF

> cmake -H. -Bbuild
-- Configuring done
-- Generating done
-- Build files have been written to: /home/egor/Trener-Egor/workspace/rk_2/build
> cmake --build build
Consolidate compiler generated dependencies of target rk_2
[ 50%] Building CXX object CMakeFiles/rk_2.dir/source/main.cpp.o
[100%] Linking CXX executable rk_2
[100%] Built target rk_2
>cd build && ./rk_2
2
1
3

> git add . && git commit -m "create main.cpp"
[main 68825f0] create main.cpp
 3 files changed, 119 insertions(+), 3 deletions(-)
 create mode 100644 CMakeLists.txt
 create mode 100644 source/main.cpp
> git push origin main
Перечисление объектов: 8, готово.
Подсчет объектов: 100% (8/8), готово.
При сжатии изменений используется до 4 потоков
Сжатие объектов: 100% (5/5), готово.
Запись объектов: 100% (6/6), 1.73 КиБ | 84.00 КиБ/с, готово.
Всего 6 (изменений 1), повторно использовано 0 (изменений 0), повторно использовано пакетов 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/Trener-Egor/RK_2.git
   4c0c63b..68825f0  main -> main
> 
```

## Create GitHub Action 
```
> mkdir -p .github/workflows
> touch .github/workflows/build.yml 
> nvim .github/workflows/build.yml
name: TIMP RK_2 workflow

on:
  push:
    branches: [ main ]
  pull_request:
    branches: [ main ]

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
      - uses: actions/checkout@v2

      - name: Install GCC
        run: sudo apt-get update && sudo apt-get install -y g++

      - name: Create build directory
        run: mkdir build

      - name: Configure CMake
        run: cmake -H. -Bbuild
      
      - name: Build project 
        run: cmake --build build 
      
      - name: Run project
        run: cd build && ./rk_2

      - name: Upload artifact
        uses: actions/upload-artifact@v2
        with:
          name: rk_2_executable
          path: build/rk_2
> git add . && git commit -m "cteate github action"
[main 74a7d17] cteate github action
 2 files changed, 91 insertions(+), 1 deletion(-)
 create mode 100644 .github/workflows/build.yml
> git push origin main
Перечисление объектов: 8, готово.
Подсчет объектов: 100% (8/8), готово.
При сжатии изменений используется до 4 потоков
Сжатие объектов: 100% (4/4), готово.
Запись объектов: 100% (6/6), 1.46 КиБ | 1.46 МиБ/с, готово.
Всего 6 (изменений 1), повторно использовано 0 (изменений 0), повторно использовано пакетов 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/Trener-Egor/RK_2.git
   68825f0..74a7d17  main -> main
 
> gh run list --workflow="TIMP RK_2 workflow" --repo="Trener-Egor/rk_2"
STATUS  NAME                  WORKFLOW            BRANCH  EVENT  ID          ELAPSED  AGE
✓       cteate github action  TIMP RK_2 workflow  main    push   9107918743  25s      2m

For details on a run, try: gh run view <run-id>
```

## GTest
```


// Добавляем код в main.cpp 
namespace jc {

 TEST(MementoTest, ValueIsCorrect) {
   Memento memento(5);
   ASSERT_EQ(memento.Value(), 5);
}

TEST(OriginatorTest, SaveAndLoadMemento) {
   Originator originator(10);
   Memento memento = originator.ValueMemento();
   
   originator.SetValue(20);
   originator.Load(memento);
   
   ASSERT_EQ(originator.ValueMemento().Value(), 10);
}

TEST(CaretakerTest, SaveAndLoadState) {
   Caretaker caretaker;
   Originator originator(30);
   
   caretaker.SetState("test", originator.ValueMemento());
   originator.SetValue(40);

   originator.Load(caretaker.State("test"));
   
   ASSERT_EQ(originator.ValueMemento().Value(), 30);
 }

}  // namespace jc

// Добавляем код в функцию main

::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
// Редактрируем CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(rk_2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER g++)

# Найти GTest
find_package(GTest REQUIRED)
if (TARGET GTest::gtest)
  message(STATUS "GTest found")
else()
  message(FATAL_ERROR "GTest not found. Install GTest or use FetchContent.")
endif()

# Исполняемый файл
add_executable(rk_2 ./source/pattern_memento.cpp) 
target_link_libraries(rk_2 GTest::gtest GTest::gtest_main)
>
>
>


```



