# Aleksander Głowacki 261702
include("zad1.jl")
using .Interpolacja

x = [-1.0, 0.0, 1.0, 2.0]
fx = [1.0, 0.0, -1.0, 2.0]

a = naturalna(x, fx)

print("\n wsp: ")
print(a)
print("\n")