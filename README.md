# Osis_lab

Написать программу (А), которая
1. Запускает подпрограмму (Б)
2. Ждет сигнала от Б.
3. После получения сигнала ждет n секунд, если подпрограмма Б не завершилась, или не завершились подпрограммы, которые запускала Б, то А должна отправить им сигнал для их завершения

Подпрограмма Б будет эмулировать работу | (конвейер, pipe)
Ожидает от пользователя ввод в формате
<prog1> <prog1 args> | <prog2> <prog2 args> | ... | <progN> <progN args>
Например, ls -l | grep "hello"
После ввода пользователя отправляет сигнал процессу А
Затем последовательно запускается prog1...progN и передается вывод progK на вход progK+1
