# ft_containers

## Summary
The `ft_containers` project involves re-implementing various container types from the C++ standard template library. The objective is to gain a thorough understanding of these containers by creating our own versions of them and be good at OOP.

## Version: 5.2

## Contents
- [Objectives](#objectives)
- [General Rules](#general-rules)
- [Mandatory Part](#mandatory-part)
  - [Requirements](#requirements)
  - [Testing](#testing)
- [Bonus Part](#bonus-part)

## Objectives
In this project, we will implement several container types from the C++ standard template library. The structure of each standard container will serve as a reference. If any part of the Orthodox Canonical form is missing in a standard container, we will not implement it. Our implementation should comply with the C++98 standard, utilizing all C++98 features (including deprecated ones) while refraining from using any later container features.

## General Rules
### Compiling
- Compile the code with `c++` and the flags `-Wall -Wextra -Werror`.
- Ensure that the code still compiles when the flag `-std=c++98` is added.
- Provide a Makefile that compiles the source files without relinking.
- The Makefile should include the following rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

### Formatting and Naming Conventions
- For each container, provide appropriately named class files.
- No specific coding style is enforced. You can follow your preferred style. However, keep in mind that clean and readable code is essential for peer-evaluators to understand and grade your work.

### Allowed/Forbidden
- Use everything from the standard library. Instead of sticking to what you already know, it is encouraged to use the C++-ish versions of C functions.
- External libraries like C++11 (and derived forms) and Boost libraries are forbidden.
- The following functions are also forbidden: `*printf()`, `*alloc()`, and `free()`. Using them will result in a grade of 0.

### Mandatory Part
Implement the following containers and provide the necessary `<container>.hpp` files along with a Makefile:
- `vector` (excluding the specialization for `vector<bool>`)
- `map`
- `stack` 

Additionally, implement the following:
- `std::iterator_traits`
- `std::reverse_iterator`
- `std::enable_if`
- `std::is_integral`
- `std::equal` and/or `std::lexicographical_compare`
- `std::pair`
- `std::make_pair`

#### Requirements
- The namespace must be `ft`.
- Each inner data structure used in your containers must be logical and justified.
- Public functions should not exceed the number offered in the standard containers. All additional functions and variables must be private or protected. Provide justification for each public function or variable.
- Implement all member functions, non-member functions, and overloads of the standard containers.
- Follow the original naming conventions and pay attention to details.
- If the container has an iterator system, implement it.
- Use `std::allocator`.
- The `friend` keyword is allowed for non-member overloads. Each use of `friend` must be justified and will be evaluated.

#### Testing
- Provide tests, including a `main.cpp` file for your defense. Go beyond the provided example `main`.
- Create two binaries that run the same tests: one with your containers only and the other with the STL containers.
- Compare outputs and performance/timing, noting that your containers may be up to 20 times slower.
- Test your containers using `ft::<container>`.

## Bonus Part
Implement an additional container: `set`. This time, a Red-Black tree implementation is mandatory.

## References
- [cplusplus.com](https://www.cplusplus.com/)
- [cppreference.com](https://cppreference.com/)
