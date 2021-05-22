# Dexel - a simple application for comma-separated values spreadsheets
## Track process at Jira : https://delcho.atlassian.net/jira/software/projects/SPREAD/boards/1/roadmap
* Username: dexeljira@mailinator.com
* Password: 123456view

## Presentation of data
The data of a table will be saved to a text file (in CSV format) as follows:

1. Each line in the file represents a separate line in the table.
1. Each row in the file contains comma separated data. This data is interpreted as the values in the row cells.
1. Each row in the table can contain a different number of cells. Therefore, each row in the file may contain a different number of items separated by comma.
1. An empty row in the file represents a blank row in the table. (i.e. a row in which all cells are blank).
1. There may be no data between two comes in the file. In this way, a blank cell is represented.
1. There may be any number of blank symbols between the data and com comers.

There may be different representations for a table. For example, the table:


|10|20|30|40|
| :-: | :-: | :-: | :-: |
| | | | |
|10| |1000| |
| | | | |
| |10| | |

can be presented in the following ways (other presentations are possible):


|<p>10, 20, 30, 40</p><p></p><p>10, ,1000,</p><p>, , ,</p><p>, 10</p>|<p>10, 20, 30 , 40</p><p></p><p>10, , 1000,</p><p> ,   ,     ,</p><p>, 10</p>|
| :- | :- |
## Data types in the table
Each cell in the table has a type, and there can be cells of different types in one table at the same time. Your application should be able to support the following types:

**Integer** –** a series of digits without any other symbols between them.

123

-123

+123

**Fractional number** – a sequence of digits, followed by a dot symbol and then another sequence of digits.

123.456

-123.456

+123.456

**Character string (string)** – a series of random characters enclosed in quotation marks. Like strings in C++, if you want to include the quotation mark in a string, you must present it as \", and if you want to include a slash, you should present it as \\.

"Hello world!"

"C:\\temp\\"

"\"This is a quotation\""

IMPORTANT: Note that quotation marks around the symbol string play a role only in reading the string (or when we read it from the file or when typing with the edit command).

[**Formula](#_Formulas) **–** the formula always starts with an equal (=) symbol.
## Required functionality
The columns, rows, and cells in the table we will denote in the standard for this type of application way:

- The columns in the table are indicated by the letters A - Z. For convenience, we assume that there can be no more than 26 columns in it.
- Rows are indicated by integers. The first row is number 1. We can have an unlimited number of rows.
- Cells are indicated as the intersection of column and row. For example, A11, B1, Z12345, etc. For example, A1 and a1 denote the same cell.

If your app detects a problem when loading the data, it should display an appropriate error message and terminate the operation. The message should tell the user what is wrong with the input data. e.g:

- If a comma is missing, it must be displayed in which order and after which symbol the comma is missing;
- If the contents of a cell are of an unknown type, it must be displayed on which row and which column the cell is and what exactly is the incorrect content. For example, let's assume that on row 2, column 3, the user has introduced 123.123.123. Your app may display, for example, the following *message: "Error: row 2, col 3, 123.123.123 is an unknown data type"*.

Once your application has opened a file, it must be able to perform the following operations:
## Display the table on the screen (Print)
When output, the data in the columns must be aligned. Vertical bar symbols must be placed between the individual columns (|). At the top and left of the table, indicate the indexes of the corresponding rows and columns. The following is an example of an input file and possible output:


|Input File|Operation of the command|
| :- | :- |
|<p>10, "abc", 123.56</p><p>"\"Quoted\""</p><p>1, 2, 3, 400</p><p>,,A3+B3+C3</p><p></p><p></p>|<p>> print</p><p>| A       | B   | C      | D   |</p><p>1 |      10 | abc | 123.56 |     |</p><p>2 |"Quoted" |     |        |     |</p><p>3 |       1 |   2 |      3 | 400 |</p><p>4 |         |     |      6 |     |</p>|

## Edit Cells
The command allows the user to change the values of the individual cells. Arguments are a reference to a cell and a new value that we want to fit into it. e.g:
```
> edit A2 123456
Successfully set A2 to 123456
```
The user can enter any type of data that is supported by your program (for example, integer, fractional number, string, formula, etc.). Note that this way the type of a cell can be changed, for example, by a number, it can become a formula or text.

If the user enters incorrect data, your app should not change anything in the table, only display a message that incorrect data has been entered. In this case, your app should not stop its execution, but simply not change the cell. e.g:
```
> edit A2 12.34.56
Error: incorrect value 12.34.56
```
The user can enter any cell number. If it goes beyond the dimensions of the currently loaded table, it must be automatically expanded. This creates a large amount of new cells. Unless a specific value is set for them, they must be empty. For example, assume that the currently loaded table contains 2 rows and 5 columns. The user can enter a command:
```
> edit Z2000 "Hello world!"
Successfully set Z2000 to Hello world
```
After it, the table will be measuring 2000 rows and 26 columns. Cell Z2000 will have hello world symbol string value, and all newly added cells will be blank.
## Formulas
Only:

1. Literals: whole or fractional numbers.
1. References to random cell types.

Formulas are symbolic strings that start with the equal symbol (=).

The following rules apply to accounts:

1. If only numbers participate in a formula, then the account is carried out according to the traditional rules of arithmetic. As a special case, we can separate the division into two integers. In this case, you should not lose the remainder and the result should be a fractional number (for example, 1 divided by 2 gives a score of 0.5).
1. If a string is involved in a formula, it must be converted to a number. This is as follows: If the string contains only numbers or a series of digits, a point symbol, and another sequence of digits, it is converted to the corresponding number. All other strings are converted to zero. e.g:


|string|Converted Value|
| :- | :- |
|"123"|123|
|"123.456.789"|0|
|"123.456"|123.456|
|"Hello world"|0|
|"123abc"|0|
3. If a blank cell is involved in a formula, it is converted to zero. This also applies to cells whose coordinates exceed the dimensions of the table.
3. If there is an error in a formula (for example, division by zero), your application should not interrupt its execution. Instead, when it displays the table on the screen, text is displayed in the corresponding cell #ERROR.

A sample table is given below. In it, the cells in yellow color are of a number type. Cells in green are of a character string type:


|** |**A**|**B**|**C**|
| :-: | :-: | :-: | :-: |
|**1**|10|Hello world!|123.56|
|**2**|123| | |

Below are formulas that are evaluated in the sample table above. For each formula, its assessment is given:


|**Formula in cell**|**Actual account**|**Cell Value**|**commentary**|
| :-: | :-: | :-: | :-: |
|= 10 + 10|10 + 10|20| |
|= A1 + C1|10 + 123.56|133.56| |
|= A1 \* B1|10 \* 0|0|The string "Hello world!" is converted to zero|
|= A1 \* A2|10 \* 123|1230|The string "123" is converted to 123.|
|= A1 \* B2|10 \* 0|0|Cell B2 is empty|
|= A1 \* Z1000|10 \* 0|0|There is no row 1000 or column Z in the table.|
|= 10 / 0|10 / 0|ERROR| |
|= 10 / A2|10 / 0|ERROR| |
|= A1 / A2|10 / 0|ERROR| |


