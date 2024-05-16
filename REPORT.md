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
При сжатии изменений используется до 4 потоков
Сжатие объектов: 100% (3/3), готово.
Запись объектов: 100% (4/4), 994 байта | 76.00 КиБ/с, готово.
Всего 4 (изменений 0), повторно использовано 0 (изменений 0), повторно использовано пакетов 0
To https://github.com/Trener-Egor/RK_2.git
 * [new branch]      main -> main
```

## Add c++ source file
```





```







