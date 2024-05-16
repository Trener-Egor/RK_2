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
```

## Create GitHub Action 
```




```




