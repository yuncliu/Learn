def add(a):
    def xxx(x = None):
        if x is not None:
            return add(x + a)
        else:
            return a
    return xxx



if __name__ == "__main__":
    x = add(1)(2)(3)(4)(5)
    print(type(x))
    print(x())
