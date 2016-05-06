# My Trilinos tutorials

When I saw [Trilinos](https://trilinos.org/) I thought it looks like a powerful
collection of packages for science, but I found the original examples quite
difficult to read as most of them were doing more than I needed or were
integrated within the full Trilinos build. My CMake skills were also a little
dwindling at the point so even though the built was relatively straightforward
the process of building an application was obscure to me.

To help myself and perhaps others in the same position I decided to work out a
few simpler examples which do not show perhaps the full potential of Trilinos
but allow an incremental familiarisation with basic functionalities. The
target is to incorporate

Serial:
 - Constructing and operating on matrices
 - Running iterative sparse linear solvers
 - Solving a parabolic equation

Parallel:
 - Constructing and operating on matrices
