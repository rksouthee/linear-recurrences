# Linear Recurrences

A library for the generation of linear recurrence sequences based on the
results of [Miller and Brown [1986]][1] and [Fiduccia [1985]][2].

The library uses modular polynomial multiplication and `power` algorithms.
Using these algorithms, the *n*th term of linear sequence of order *k* requires
*O(f(k) * n)* operations, where *f(k)* is the total number of operations
to multiply two polynomials of degree *k - 1*. 

## Solutions

The library provides various functions for computing some well known
sequences, with the ability to define custom recurrences.

Currently, linear recurrence sequences of order 2 and order 3 are provided.

| Solution         | OEIS                                |
| ---------------- | ----------------------------------- |
| Fibonacci        | [A000045](https://oeis.org/A000045) |
| Lucas            | [A000032](https://oeis.org/A000032) |
| Pell             | [A000129](https://oeis.org/A000129) |
| Pell-Lucas       | [A002203](https://oeis.org/A002203) |
| Padovan          | [A000931](https://oeis.org/A000931) |
| Perrin           | [A001608](https://oeis.org/A001608) |
| Tribonacci       | [A000073](https://oeis.org/A000073) |
| Tribonacci-Lucas | [A001644](https://oeis.org/A001644) |
| Cordonnier       | [A134816](https://oeis.org/A134816) |

OEIS: *The On-Line Encyclopedia of Integer Sequences*, published electronically
at [https://oeis.org], 2019.

## Further Work

The algorithms implemented only allow linear recurrence sequences of order 2
and order 3. To provide implementations for an arbitrary order, we can
introduce a polynomial type. With the introduction of polynomials the
algorithms can use the Fast Fourier Transform to reduce the number of
operations required to multiply two polynomials.

[1]: https://academic.oup.com/comjnl/article/9/2/188/623434
[2]: https://dl.acm.org/citation.cfm?id=3679
