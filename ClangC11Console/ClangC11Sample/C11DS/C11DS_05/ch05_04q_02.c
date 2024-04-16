/*
2. 1から 50まで３の倍数なら「Fizz」、5の倍数なら「Bazz」、
 15の倍数なら「FizzBazz」を表示するプログラム。
*/
#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 50; i++) {
        printf("%i ", i);
        if (i % 15 == 0) {
            puts("FizzBazz\n");
        }
        else if (i % 5 == 0) {
            puts("Bazz\n");
        }
        else if (i % 3 == 0) {
            puts("Fizz\n");
        }
        else {
            puts("\n");
        }
    }//for

    return 0;
}//main

/*
>ch05_04q_02
1

2

3 Fizz

4

5 Bazz

6 Fizz

7

8

9 Fizz

10 Bazz

11

12 Fizz

13

14

15 FizzBazz

16

17

18 Fizz

19

20 Bazz

21 Fizz

22

23

24 Fizz

25 Bazz

26

27 Fizz

28

29

30 FizzBazz

31

32

33 Fizz

34

35 Bazz

36 Fizz

37

38

39 Fizz

40 Bazz

41

42 Fizz

43

44

45 FizzBazz

46

47

48 Fizz

49

50 Bazz
*/