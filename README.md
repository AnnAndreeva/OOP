<h1 align="center">Лабораторные работы по ООП.</h1>
<h2>Лабораторная работа № 1: Объектно-ориентированное программирование обработки строк с использованием функций стандартной библиотеки языка С++ в стиле языка С.</h2>
Ввести с клавиатуры символьную строку длиной не более 80 символов, рассматриваемую как произвольное абстрактное предложение, состоящее из слов. Слова отделяются друг от друга как минимум одним символом «пробел». Строка должна быть введена посимвольно с использованием функции getchar(). Используя введённую строку, построить новую строку, в которой слова упорядочены по возрастанию последних символов.
 
<h2>Лабораторная работа № 2: Объектно-ориентированное программирование последовательного доступа к текстовым файлам с использованием функций стандартной библиотеки С++ в стиле языка C.</h2>
Написать программу, которая создаёт в текстовом режиме файл в текущем каталоге с именем, вводимым с клавиатуры, и заполняет его произвольными строками, которые также вводятся с клавиатуры. После ввода последней строки файл закрывается. По введённой с клавиатуры длине строки извлечь из файла все строки, длиннее заданной величины, и поместить их в другой текстовый файл в текущем каталоге с заданным именем. В файле с прежним именем оставить только слова короче или равные заданной длине.

<h2>Лабораторная работа № 3: Объектно-ориентированное программирование прямого доступа к записям файла с использованием функций стандартной библиотеки языка C.</h2>
Реализовать информационную базу, состоящую из трех файлов:
<li>FIO.DAT - содержит в виде символьных строк, оканчивающихся, список фамилий; 
<li>DOLGH.DAT - содержит в виде символьных строк наименования должностей, которые не повторяются; 
<li>LINK.IDX - содержит записи вида: <br><br>
struct {unsigned long name_idx; //индекс записи в файле FIO.DAT; <br>
            unsigned long post_idx; //индекс записи в файле DOLGH.DAT}, <br><br>
связывающие фамилии в FIO.DAT и должности в DOLGH.DAT. В качестве индекса используется значение позиции записи от начала файла, с которой запись располагается в соответствующем файле. Записи в FIO.DAT и в LINK.IDX взаимнооднозначно соответствуют друг другу. Программа должна обеспечивать выполнение следующих функций: 
<li>включение в информационную базу новой фамилии с указанием должности; 
<li>добавление новой должности; 
<li>по указанному порядковому номеру в индексном файле вывод на экран фамилии и должности в виде: 
Сотрудник <фамилия> - должность <должность>.

<h2>Лабораторная работа № 4: Освоение технологии объектно-ориентированного программирования на языке С++. Работа с объектами стандартных классовых типов.</h2>
Написать программу управления информацией, состоящей из трех списков: 
<li>Динамически формируемый список датчиков формата: 
{<шифр датчика>; <название датчика> };
<li>Динамически формируемый список подсистем: 
{<шифр подсистемы>; <название подсистемы> };
<li>Динамически формируемый список индексов формата: <br><br>
{<индекс_записи_в_списке_датчиков>;<br>
  <индекс_записи_в_списке_подсистем> }. <br><br>
Список индексных записей фиксирует принадлежность датчиков подсистемам. Датчик может быть задействован только в одной подсистеме или нигде. 
Индекс записи в списке датчиков – это указатель записи в памяти. 
Индекс записи в списке подсистем – это порядковый номер записи в списке. 
Шифры датчиков – трёхзначные целые числа. 
Названия датчиков – символьные строки переменной длины. 
Шифры подсистем - двузначные целые числа. 
Названия подсистем – символьные строки произвольной длины. 
Программа должна обеспечивать выполнение следующих функций: 
<li>Добавление нового датчика (добавление записи в конец списка датчиков).
<li>Добавление новой подсистемы (добавление записи в конец списка подсистем). 
<li>Включение датчика в подсистему. 
<li>Исключение датчика из подсистемы. 
<li>Удаление подсистемы (удаление записи из списка подсистем). 
<li>Удаление записей неиспользуемых датчиков из списка датчиков. 
<li>Вывод на экран названий подсистем, без датчиков.

<li>Результат можно возвращать из функции в вершине стека сопроцессора.
