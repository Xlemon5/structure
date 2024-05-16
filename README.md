# Лабораторные работы 2 курс - структуры и алгоритмы данных
* lab1.1 (lab1.2): Реализация хэш таблиц (вставка, поиск, удаление, вывод)
* lab2 (по вариантам (12)):	
	Написать программу генерации m-последовательностей 0 и 1, удовлетворяющих обоим требованиям: 1) хотя бы 3  единицы стоят рядом; 2)число единиц кратно 3. 
* lab3: Расставить N ферзей на доске NxN так чтобы ни один не находился под боем другого.

* lab4: Вывести маршрут шахматного коня, проходящего через все клетки доски NxN по одному разу.

* lab5 (по вариантам (12)): Для заданной системы двусторонних дорог определите, можно ли, закрыв какие-нибудь три дороги, запретить перемещение из города А в город Б.

* lab5.1: Обход графа в ширину.

* lab5.2: Обход графа в глубину.

* lab6: Треугольник Паскаля.

* lab_dynamic:
	+ lab7: Сколько n-значных чисел можно составить, используя цифры 5 и 9, в которых три одинаковые цифры не стоят рядом? 
	Вход. Одно число n (n ≤ 30).
	Выход. Количество n-значных чисел.

	+ lab8: Вычислить количество последовательностей длины n, состоящих только из нулей и единиц, в которых не встречается три единицы подряд.
	Вход. Длина последовательностей n (1 ≤ n ≤ 105).
	Выход. Вывести количество искомых последовательностей по модулю 12345.

	+ lab9: Рассмотрим следующую задачу: есть определённое количество кувшинок, расположенных в ряд, кузнечик стоит на первой из них. Он может прыгнуть на следующую кувшинку, либо перепрыгнуть через одну. Сколько существует разных способов (путей) добраться до последней кувшинки?

	+ lab10:Дано N предметов, ni предмет имеет массу wi>0 и стоимость pi>0. Необходимо выбрать из этих предметов такой набор, чтобы суммарная масса не превосходила заданной величины W (вместимость рюкзака), а суммарная стоимость была максимальна.

* lab_zhadniy:
	+ Деду Морозу и Снегурочке нужно доставить n подарков детям. Зная время t1 упаковки каждого подарка Снегурочкой и время его доставки Дедом Морозом t2, вычислить 		наименьшее время, необходимое для выполнения всех заказов. В свой мешок Дед Мороз может положить только один подарок Вход: В первой строке находится количество подарков n (1 ≤ n ≤ 300). В следующих двух строках содержится по n чисел, соответственно: во второй строке – время упаковки 		каждого подарка Снегурочкой, а в третьей – время его доставки Дедом Морозом. Известно, что 0 < t1, t2 ≤ 1000.
	Выход. Наименьшее время доставки всех подарков.

	+ Пример входа
	+ 10 2 1
	+ 22 4 1
	+ 60 5 6
	
	+ Пример выхода
	+ 4
	+ 4
	+ 11

	+ Сапожнику необходимо выполнить n работ. Каждый день сапожник может выполнять только одну работу. Для каждой i - ой работы известно время ее выполнения Ti и штраф Si, 	который каждый день должен платить сапожник до тех пор, пока он не отдаст i - ую работу заказчику. Найти последовательность выполнения работ, при которой сумма 		штрафа 	будет минимальной. Вход.  Состоит из нескольких тестов. Первая строка каждого теста содержит количество работ n (1 < n < 1000), за которой следуют n строк, содержащие характеристики 		работ T_i (1 < T_i < 1000) и S_i (1 < S_i < 10000). Выход.  Для каждого теста в отдельной строке вывести порядок работ, при котором сумма штрафа минимальна. При существовании нескольких оптимальных порядков работ 		выводить лексикографически наименьший.

	+ Пример входа
	+ 10 2 1
	+ 22 4 1
	+ 60 5 6
	
	+ Пример выхода
	+ 4
	+ 4
	+ 11



	+ Сапожнику необходимо выполнить n работ. Каждый день сапожник может выполнять только одну работу. Для каждой i - ой 	работы известно время ее выполнения T_i и штраф 	S_i, который каждый день должен платить сапожник до тех пор, пока он 	не отдаст i - ую работу заказчику. Найти последовательность выполнения работ, при которой сумма 	штрафа будет минимальной. Вход.  Состоит из нескольких тестов. Первая строка каждого теста содержит количество работ n (1 < n < 1000), за 	которой следуют n строк, содержащие 			характеристики работ Ti (1 < T_i < 1000) и S_i (1 < S_i < 10000). Выход.  Для каждого теста в отдельной строке вывести порядок работ, при котором сумма штрафа минимальна. При 		существовании нескольких оптимальных порядков работ выводить лексикографически наименьший.

	+ Пример входа
	+ 10 2 1
	+ 22 4 1
	+ 60 5 6
	
	+ Пример выхода
	+ 4
	+ 4
	+ 11


