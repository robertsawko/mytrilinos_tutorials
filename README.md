# Trilinos for Dummies

## Rationale and aims

When I saw [Trilinos](https://trilinos.org/) I thought it looks like a powerful
collection of packages for science, but I found the original examples quite
difficult to read as most of them were doing more than I needed or were
integrated within the full Trilinos build. My CMake skills were also a little
fledging at the point so even though the built was relatively straightforward
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

## Constraints

This tutorial focuses on the "new stacks" e.g. Tpetra is prefered over Epetra
or Amesos2 is preferred over Amesos. 

## Tutorials

### Hello World

Tpetra says hello and informs about Trilinos version. This is a very minimal example
on how to build against a Trilinos with CMake.

### Enter Teuchos

Teuchos is a package full of useful tools and programming constructs. We
present reference counting pointers (RCP) and automatic command-line parsing.

### Norms etc (serial)

A tutorial which looks at creating vectors, matrices, accessing their
components and running norm operations on them.

### Solve me

Amesos2 and tutorials in th

