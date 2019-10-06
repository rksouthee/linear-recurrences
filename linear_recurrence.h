#ifndef LINEAR_RECURRENCE_H
#define LINEAR_RECURRENCE_H

template <typename T>
// requires Regular(T)
struct binomial {
    T m0;
    T m1;

    binomial() = default;

    binomial(const T& x, const T& y)
        : m0(x), m1(y)
    { }
};

template <typename T>
// requires Regular(T)
struct trinomial {
    T m0;
    T m1;
    T m2;

    trinomial() = default;

    trinomial(const T& x, const T& y, const T& z)
        : m0(x), m1(y), m2(z)
    { }
};

template <typename Op, typename I, typename T>
// requires BinaryOperation(Op, T) && Integer(I)
T power_accumulate_positive(T r, T a, I n, Op op)
{
    // precondition: associative(op) && positive(n)
    while (true) {
        if (n % 2 != 0) {
            r = op(r, a);
            if (n == 1) return r;
        }
        a = op(a, a);
        n = n / 2;
    }
}

template <typename Op, typename I, typename T>
// requires BinaryOperation(Op, T) && Integer(I)
T power(T a, I n, Op op)
{
    // precondition: associative(op) && positive(n)
    while (n % 2 == 0) {
        a = op(a, a);
        n = n / 2;
    }
    n = n / 2;
    if (n == 0) return a;
    return power_accumulate_positive(a, op(a, a), n, op);
}

template <typename I>
// requires Integer(I)
class modular_quadratic_multiplies {
private:
    I c0;
    I c1;

public:
    modular_quadratic_multiplies(const I& x, const I& y)
        : c0(x), c1(y)
    { }

    binomial<I> operator()(const binomial<I>& x, const binomial<I>& y) const {
        I t0 = x.m1 * y.m1;
        return binomial<I>(
            x.m0 * y.m0 + c0 * t0,
            x.m0 * y.m1 + x.m1 * y.m0 + c1 * t0);
    }
};

template <typename I>
// requires Integer(I)
struct modular_cubic_multiplies {
private:
    I c0;
    I c1;
    I c2;

public:
    modular_cubic_multiplies(const I& x, const I& y, const I& z)
        : c0(x), c1(y), c2(z)
    { }

    trinomial<I> operator()(const trinomial<I>& x, const trinomial<I>& y) const {
        I t0 = x.m2 * y.m2;
        I t1 = x.m1 * y.m2 + x.m2 * y.m1 + c2 * t0;
        return trinomial<I>(
            x.m0 * y.m0 + c0 * t1,
            x.m0 * y.m1 + x.m1 * y.m0 + c0 * t0 + c1 * t1,
            x.m0 * y.m2 + x.m1 * y.m1 + x.m2 * y.m0 + c1 * t0 + c2 * t1);
    }
};

template <typename I, typename N>
// requires Integer(I) && Integer(N)
I order2(N n, I a0, I a1, I c0, I c1)
{
    // precondition: nonnegative(n)
    // a(0) = a0, a(1) = a1
    if (n == N(0)) return a0;
    binomial<I> t = power(binomial<I>(I(0), I(1)), n,
                          modular_quadratic_multiplies<I>(c0, c1));
    return a0 * t.m0 + a1 * t.m1;
}

template <typename I, typename N>
// requires Integer(I) && Integer(N)
I order3(N n, I a0, I a1, I a2, I c0, I c1, I c2)
{
    // precondition: nonnegative(n)
    // a(0) = a0, a(1) = a1, a(2) = a2
    if (n == N(0)) return a0;
    trinomial<I> t = power(trinomial<I>(I(0), I(1), I(0)), n,
                           modular_cubic_multiplies<I>(c0, c1, c2));
    return a0 * t.m0 + a1 * t.m1 + a2 * t.m2;
}

template <typename N, typename I = N>
// requires Integer(I) && Integer(N)
I fibonacci(N n)
{
    // precondition: nonnegative(n)
    return order2(n, I(0), I(1), I(1), I(1));
}

template <typename N, typename I = N>
// requires Integer(I) && Integer(N)
I lucas(N n)
{
    // precondition: nonnegative(n)
    return order2(n, I(2), I(1), I(1), I(1));
}

template <typename N, typename I = N>
// requires Integer(I) && Integer(N)
I pell(N n)
{
    // precondition: nonnegative(n)
    return order2(n, I(0), I(1), I(1), I(2));
}

template <typename N, typename I = N>
// requires Integer(I) && Integer(N)
I pell_lucas(N n)
{
    // precondition: nonnegative(n)
    return order2(n, I(2), I(2), I(1), I(2));
}

template <typename N, typename I = N>
// requires Integer(I) && Integer(N)
I padovan(N n)
{
    // precondition: nonnegative(n)
    return order3(n, I(1), I(0), I(0), I(1), I(1), I(0));
}

template <typename N, typename I = N>
// requires Integer(I) && Integer(N)
I perrin(N n)
{
    // precondition: nonnegative(n)
    return order3(n, I(3), I(0), I(2), I(1), I(1), I(0));
}

template <typename N, typename I = N>
// requires Integer(I) && Integer(N)
I tribonacci(N n)
{
    // precondition: nonnegative(n)
    return order3(n, I(0), I(0), I(1), I(1), I(1), I(1));
}

template <typename N, typename I = N>
// requires Integer(I) && Integer(N)
I tribonacci_lucas(N n)
{
    // precondition: nonnegative(n)
    return order3(n, I(3), I(1), I(3), I(1), I(1), I(1));
}

template <typename N, typename I = N>
// requires Integer(I) && Integer(N)
I cordonnier(N n)
{
    // precondition: nonnegative(n)
    return order3(n, I(1), I(1), I(1), I(1), I(1), I(0));
}

#endif
