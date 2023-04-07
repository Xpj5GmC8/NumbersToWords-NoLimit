# NumbersToWords-NoLimit
This program converts numbers into how they're spelled in English, made to be fast and to have **no limits** to how long a number can be.

Since the program can print n-illions and someone might only need that, you can add the ``-i`` option (as the first argument) to have the program print only illions (1 returns million, 2 is billion, 34 is quattuortrigintillion, etc.).<br>
If no numbers are passed as arguments (after ``-i`` if it's present), the program will read numbers from ``stdin``, otherwise ``stdin`` is ignored.<br>
For "-illions", I used the "Conway-Guy system", which seems to be a universally accepted standard.<br>
The program was written in C++ and rewritten in Python.<br>
The C++ program uses Boost MP and GMP to bypass it's integer limitations. I think I fiddled with the code enough to make it's only limitation be the hardware's RAM, like Python's is by default, but I still can't guarantee that it is completely limit-free.<br>If you want to use the version that you can be more sure is limit-free, you should probably use the python version.

## Examples on the usage of the program
Convert from 1 to 10:
```bash
./NumbersToWords 1 2 3 4 5 6 7 8 9 10
```
Convert the 78th illion:
```bash
./NumbersToWords -i 78
```
Convert numbers (along with their negative counterparts) starting from 0 until the user terminates the program:
```bash
for((i=0;;i++));do printf "$i\n-$i\n";done | ./NumbersToWords
```
Convert to illions starting from million, until the user terminates the program:
```bash
for((i=1;;i++));do echo "$i";done | ./NumbersToWords -i
```
Googolplex's illion:
```bash
./NumbersToWords -i "$(printf "%0.s3" {1..99})2"
```
#
Compile the C++ program with:<br>
```bash
g++ NumbersToWords.cpp -lgmp -o NumbersToWords
```

The python version has the exact same functionality. To execute it, replace ``./NumbersToWords`` with ``./NumbersToWords.py`` or ``python3 NumbersToWords.py``


### Limitations:
- Decimal numbers are not supported
- It doesn't check for undesired characters (chars that aren't digits or dashes). You need to make sure the input is valid
- Only short scale is supported
- Ordinal numbers are not supported

### To-do list:
- More testing
- Make it even faster

### Tested with:
C++: GCC 10.2, Boost 1.74, GMP 6.2<br>
Python: Python 3.11 (CPython)

Comes with no warranty.