using System;

class Program
{
    static void Main()
    {
        while (true)
        {
            Console.WriteLine();
            Console.WriteLine("Выберите задание:");
            Console.WriteLine("1. Чётное или нечётное");
            Console.WriteLine("2. Максимум из трёх чисел");
            Console.WriteLine("3. Знак числа");
            Console.WriteLine("4. Оценка по баллам");
            Console.WriteLine("5. Високосный год");
            Console.WriteLine("6. Квадратное уравнение");
            Console.WriteLine("7. Треугольник существует?");
            Console.WriteLine("8. Калькулятор");
            Console.WriteLine("9. Скидка в магазине");
            Console.WriteLine("10. Время суток и приветствие");
            Console.WriteLine("0. Выход");
            Console.Write("Выберите задание: ");

            string vybor = Console.ReadLine();
            Console.WriteLine();

            if (vybor == "1")
                quest1();
            else if (vybor == "2")
                quest2();
            else if (vybor == "3")
                quest3();
            else if (vybor == "4")
                quest4();
            else if (vybor == "5")
                quest5();
            else if (vybor == "6")
                quest6();
            else if (vybor == "7")
                quest7();
            else if (vybor == "8")
                quest8();
            else if (vybor == "9")
                quest9();
            else if (vybor == "10")
                quest10();
            else if (vybor == "0")
            {
                Console.WriteLine("Выход из программы");
                break;
            }
            else
            {
                Console.WriteLine("Неверный выбор, попробуйте ещё раз");
            }
        }
    }

    static void quest1()
    {
        Console.WriteLine("--- Задание 1. Чётное или нечётное ---");
        Console.Write("Введите целое число: ");
        int n = int.Parse(Console.ReadLine());

        if (n % 2 == 0)
        {
            Console.WriteLine("Число чётное");
        }
        else
        {
            Console.WriteLine("Число нечётное");
        }
    }

    static void quest2()
    {
        Console.WriteLine("--- Задание 2. Максимум из трёх чисел ---");
        Console.Write("Введите a: ");
        int a = int.Parse(Console.ReadLine());
        Console.Write("Введите b: ");
        int b = int.Parse(Console.ReadLine());
        Console.Write("Введите c: ");
        int c = int.Parse(Console.ReadLine());

        int max;

        if (a >= b && a >= c)
        {
            max = a;
        }
        else if (b >= a && b >= c)
        {
            max = b;
        }
        else
        {
            max = c;
        }

        Console.WriteLine("Максимум = " + max);
    }

    static void quest3()
    {
        Console.WriteLine("--- Задание 3. Знак числа ---");
        Console.Write("Введите число: ");
        double x = double.Parse(Console.ReadLine());

        if (x > 0)
        {
            Console.WriteLine("Положительное");
        }
        else if (x < 0)
        {
            Console.WriteLine("Отрицательное");
        }
        else
        {
            Console.WriteLine("Равно нулю");
        }
    }

    static void quest4()
    {
        Console.WriteLine("--- Задание 4. Оценка по баллам ---");
        Console.Write("Введите баллы (0-100): ");
        int score = int.Parse(Console.ReadLine());

        if (score >= 90 && score <= 100)
        {
            Console.WriteLine("Отлично");
        }
        else if (score >= 75 && score <= 89)
        {
            Console.WriteLine("Хорошо");
        }
        else if (score >= 60 && score <= 74)
        {
            Console.WriteLine("Удовлетворительно");
        }
        else if (score >= 0 && score <= 59)
        {
            Console.WriteLine("Неудовлетворительно");
        }
        else
        {
            Console.WriteLine("Неправильные баллы");
        }
    }
    static void quest5()
    {
        Console.WriteLine("--- Задание 5. Високосный год ---");
        Console.Write("Введите год: ");
        int year = int.Parse(Console.ReadLine());

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            Console.WriteLine("Год високосный");
        }
        else
        {
            Console.WriteLine("Год не високосный");
        }
    }

    static void quest6()
    {
        Console.WriteLine("--- Задание 6. Квадратное уравнение ---");
        Console.Write("Введите a: ");
        double a = double.Parse(Console.ReadLine());
        Console.Write("Введите b: ");
        double b = double.Parse(Console.ReadLine());
        Console.Write("Введите c: ");
        double c = double.Parse(Console.ReadLine());

        if (a == 0)
        {

            if (b == 0)
            {
                if (c == 0)
                    Console.WriteLine("Бесконечно много решений");
                else
                    Console.WriteLine("Нет решений");
            }
            else
            {
                double x = -c / b;
                Console.WriteLine("Один корень: " + x);
            }
        }
        else
        {
            double d = b * b - 4 * a * c;

            if (d > 0)
            {
                double x1 = (-b + Math.Sqrt(d)) / (2 * a);
                double x2 = (-b - Math.Sqrt(d)) / (2 * a);
                Console.WriteLine("Два корня:");
                Console.WriteLine("x1 = " + x1);
                Console.WriteLine("x2 = " + x2);
            }
            else if (d == 0)
            {
                double x = -b / (2 * a);
                Console.WriteLine("Один корень: " + x);
            }
            else
            {
                Console.WriteLine("Нет действительных корней");
            }
        }
    }

    static void quest7()
    {
        Console.WriteLine("--- Задание 7. Треугольник существует? ---");
        Console.Write("Введите сторону a: ");
        double a = double.Parse(Console.ReadLine());
        Console.Write("Введите сторону b: ");
        double b = double.Parse(Console.ReadLine());
        Console.Write("Введите сторону c: ");
        double c = double.Parse(Console.ReadLine());

        if (a + b > c && a + c > b && b + c > a)
        {
            Console.WriteLine("Треугольник существует");

            if (a == b && b == c)
            {
                Console.WriteLine("Равносторонний");
            }
            else if (a == b || a == c || b == c)
            {
                Console.WriteLine("Равнобедренный");
            }
            else
            {
                Console.WriteLine("Разносторонний");
            }
        }
        else
        {
            Console.WriteLine("Треугольник не существует");
        }
    }

    static void quest8()
    {
        Console.WriteLine("--- Задание 8. Калькулятор ---");
        Console.Write("Введите первое число: ");
        double a = double.Parse(Console.ReadLine());
        Console.Write("Введите второе число: ");
        double b = double.Parse(Console.ReadLine());
        Console.Write("Введите операцию (+ - * /): ");
        string op = Console.ReadLine();

        if (op == "+")
        {
            Console.WriteLine("Результат = " + (a + b));
        }
        else if (op == "-")
        {
            Console.WriteLine("Результат = " + (a - b));
        }
        else if (op == "*")
        {
            Console.WriteLine("Результат = " + (a * b));
        }
        else if (op == "/")
        {
            if (b == 0)
            {
                Console.WriteLine("Ошибка: деление на ноль");
            }
            else
            {
                Console.WriteLine("Результат = " + (a / b));
            }
        }
        else
        {
            Console.WriteLine("Неизвестная операция");
        }
    }

    static void quest9()
    {
        Console.WriteLine("--- Задание 9. Скидка в магазине ---");
        Console.Write("Введите сумму покупки: ");
        double sum = double.Parse(Console.ReadLine());

        double discount = 0;

        if (sum < 1000)
        {
            discount = 0;
        }
        else if (sum >= 1000 && sum < 5000)
        {
            discount = 0.05;
        }
        else if (sum >= 5000 && sum < 10000)
        {
            discount = 0.10;
        }
        else if (sum >= 10000)
        {
            discount = 0.15;
        }

        double itogo = sum - sum * discount;

        Console.WriteLine("Скидка: " + (discount * 100) + "%");
        Console.WriteLine("Итого к оплате: " + itogo);
    }

    static void quest10()
    {
        Console.WriteLine("--- Задание 10. Время суток и приветствие ---");
        Console.Write("Введите час (0-23): ");
        int hour = int.Parse(Console.ReadLine());

        if (hour < 0 || hour > 23)
        {
            Console.WriteLine("Ошибка: час должен быть от 0 до 23");
        }
        else if (hour >= 6 && hour <= 11)
        {
            Console.WriteLine("Доброе утро");
        }
        else if (hour >= 12 && hour <= 17)
        {
            Console.WriteLine("Добрый день");
        }
        else if (hour >= 18 && hour <= 22)
        {
            Console.WriteLine("Добрый вечер");
        }
        else
        {
            Console.WriteLine("Доброй ночи");
        }
    }
}
