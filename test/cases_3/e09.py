# 和e09.c完全一致的python文件，只是为了验证计算结果的方便

def test(arg1, arg2):
    return (arg1 + arg2) * arg1 // arg2 & arg1

def func(arg1, arg2):
    return (arg1 + arg2) * arg1 // arg2 & arg1

def main():
    a = test(1, 2) + func(3, 4) + 9 * 10
    print(a)
    b = test(func(1, 2), func(3, 4))
    print(b)
    c = func(test(1, 2), test(3, 4))
    print(c)
    return 0

if __name__ == "__main__":
    main()