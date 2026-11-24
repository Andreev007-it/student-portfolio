import time
import random
import sys
from functools import lru_cache

def measure_time(func, *args, repeats=5):
    """
    Возвращает среднее время выполнения func(*args) за `repeats` запусков.
    """
    times = []
    for _ in range(repeats):
        t0 = time.perf_counter()
        func(*args)
        times.append(time.perf_counter() - t0)
    return sum(times) / len(times)


def run_experiment(func, sizes, setup=None):
    """
    Для каждого n из sizes вызывает measure_time.
    setup(n) -> tuple аргументов для func.
    Возвращает список (n, время).
    """
    results = []
    for n in sizes:
        args = setup(n) if setup else (n,)
        t = measure_time(func, *args)
        results.append((n, t))
    return results


#2

def sum_recursive(arr):
    """T(n) = T(n-1) + O(1)  =>  O(n)"""
    if not arr:          # база
        return 0
    return arr[0] + sum_recursive(arr[1:])


def sum_iterative(arr):
    """Итеративная версия: O(1) по памяти"""
    s = 0
    for x in arr:
        s += x
    return s


#3

def binary_search(arr, target, lo=0, hi=None):
    """T(n) = T(n/2) + O(1)  =>  O(log n)"""
    if hi is None:
        hi = len(arr) - 1
    if lo > hi:
        return -1
    mid = (lo + hi) // 2
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search(arr, target, mid + 1, hi)
    else:
        return binary_search(arr, target, lo, mid - 1)


#4

def fib_naive(n):
    """T(n) = T(n-1) + T(n-2) + O(1)  =>  O(phi^n)"""
    if n <= 1:
        return n
    return fib_naive(n - 1) + fib_naive(n - 2)


def fib_memo(n, memo=None):
    """T(n) = O(n), S(n) = O(n)"""
    if memo is None:
        memo = {}
    if n in memo:
        return memo[n]
    if n <= 1:
        return n
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo)
    return memo[n]


@lru_cache(maxsize=None)
def fib_lru(n):
    if n <= 1:
        return n
    return fib_lru(n - 1) + fib_lru(n - 2)


#5

def merge_sort(arr):
    """T(n) = 2·T(n/2) + O(n)  =>  O(n log n)"""
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)


def merge(a, b):
    """O(len(a) + len(b))"""
    result = []
    i = j = 0
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            result.append(a[i])
            i += 1
        else:
            result.append(b[j])
            j += 1
    result.extend(a[i:])
    result.extend(b[j:])
    return result


def bubble_sort(arr):
    """O(n^2) для сравнения"""
    a = arr[:]
    n = len(a)
    for i in range(n):
        for j in range(0, n - i - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
    return a


#6

moves = 0

def hanoi(n, src='A', dst='C', tmp='B'):
    """T(n) = 2·T(n-1) + O(1)  =>  O(2^n)"""
    global moves
    if n == 0:
        return
    hanoi(n - 1, src, tmp, dst)
    moves += 1  # перекладывание
    hanoi(n - 1, tmp, dst, src)


def hanoi_count(n):
    """Возвращает число перемещений без глобальной переменной"""
    if n == 0:
        return 0
    return 2 * hanoi_count(n - 1) + 1


#7

def depth(n):
    if n == 0:
        return 0
    return 1 + depth(n - 1)


def find_max_recursion_depth():
    """Находит максимальное n, при котором не возникает RecursionError"""
    original_limit = sys.getrecursionlimit()
    max_n = 0
    try:
        low, high = 1, original_limit + 100
        while low <= high:
            mid = (low + high) // 2
            try:
                depth(mid)
                max_n = mid
                low = mid + 1
            except RecursionError:
                high = mid - 1
    finally:
        sys.setrecursionlimit(original_limit)
    return max_n


if __name__ == "__main__":
    print("=== Тесты базовых функций ===")
    
    # sum
    arr = [1, 2, 3, 4, 5]
    print(f"sum_recursive({arr}) = {sum_recursive(arr)}")
    
    # binary search
    sorted_arr = list(range(0, 100, 2))
    print(f"binary_search(42) = {binary_search(sorted_arr, 42)}")
    print(f"binary_search(41) = {binary_search(sorted_arr, 41)}")
    
    # fib
    print(f"fib_naive(10) = {fib_naive(10)}")
    print(f"fib_memo(10) = {fib_memo(10)}")
    
    # merge_sort
    a = [5, 2, 8, 1, 9, 3]
    print(f"merge_sort({a}) = {merge_sort(a)}")
    
    # hanoi
    moves = 0
    hanoi(3)
    print(f"hanoi(3) moves = {moves}, expected 7")
    
    # depth
    print(f"Default recursion limit: {sys.getrecursionlimit()}")
    max_d = find_max_recursion_depth()
    print(f"Max recursion depth found: {max_d}")
