EE205 Animal Farm
=================

<img src="images/animal_farm_full.jpg" style="width:300px; float: left; margin: 0 10px 10px 0;" alt="Animal farm"/>

Animal Farm is a series of labs intended to teach the basics of C and C++.  It's also intended to introduce good
Software Engineering practices.  Students are expected to "Live" in
this project as the code evolves over a series of requirements.

#### Links
The project's home page (hosted by GitHub) is [here](https://github.com/marknelsonengineer/ee205_animal_farm)

The source code documentation (hosted by UH) is [here](https://www2.hawaii.edu/~marknels/ee205/ee205_animal_farm)

#### Roadmap
| Animal Farm Version | Description                                                                                                                                                                                                                                                                                                                                                                                    |
|---------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Animal Farm 0       | An array-based database of cats, where each attribute is an array.                                                                                                                                                                                                                                                                                                                             |
| Animal Farm 1       | An array-based database of cats, where each a cat's attributes are collected in a `struct`.                                                                                                                                                                                                                                                                                                    |
| Animal Farm 2       | A procedural singly linked-list database of cats, where each cat is an object.                                                                                                                                                                                                                                                                                                                 |
| Animal Farm 3       | A collection class that implements a singly linked database of Animal objects using: <ul><li>An abstract List</li><li>A concrete SinglyLinkedList</li><li>generic Node</li></ul>Add an abstract Animal (which also inherits from Node) & Mammal to the Cat object model.                                                                                                                       |
| Animal Farm 4       | A collection class that implements a doubly linked list.  <br/>Add Fish, Bird and Dog to the object model.<br/>Build a class factory for Cat.  <br/>Add destructors to the object model. <br/>Create a CatLinkedList that inherits from SinglyLinkedList… and then implement findCatByName <br/>Have Cat override > to sort cats by name<br/>…think about how we are going to sort our animals |
| Animal Farm 5       | Refactor the collection class into a Binary Search Tree.  <br/>Add Birds and Fish to the object model.                                                                                                                                                                                                                                                                                         |

#### Toolchain
This project is the product of a tremendous amount of R&D and would not be possible without the following world-class tools:

| Tool           | Website                     |                                                Logo                                                 |
|----------------|-----------------------------|:---------------------------------------------------------------------------------------------------:|
| **gcc**        | https://gcc.gnu.org         |   <img src="images/logo_gcc.png" style="height:40px; float: center; margin: 0 0 0 0;" alt="GCC"/>   |
| **llvm/clang** | https://clang.llvm.org      |  <img src="images/logo_llvm.png" style="height:40px; float: center; margin: 0 0 0 0;" alt="GCC"/>   |
| **CLion**      | https://jetbrains.com/clion |  <img src="images/logo_clion.png" style="height:40px; float: center; margin: 0 0 0 0;" alt="GCC"/>  |
| **CMake**      | https://cmake.org           |  <img src="images/logo_cmake.png" style="height:40px; float: center; margin: 0 0 0 0;" alt="GCC"/>  |
| **Doxygen**    | https://doxygen.nl          | <img src="images/logo_doxygen.png" style="height:40px; float: center; margin: 0 0 0 0;" alt="GCC"/> |
| **Boost**      | https://boost.org           |  <img src="images/logo_boost.png" style="height:40px; float: center; margin: 0 0 0 0;" alt="GCC"/>  |
| **Git**        | https://git-scm.com         |   <img src="images/logo_git.png" style="height:40px; float: center; margin: 0 0 0 0;" alt="GCC"/>   |
| **GitHub**     | https://github.com          | <img src="images/logo_github.png" style="height:40px; float: center; margin: 0 0 0 0;" alt="GCC"/>  |
| **GitLab**     | https://gitlab.org          | <img src="images/logo_gitlab.png" style="height:40px; float: center; margin: 0 0 0 0;" alt="GCC"/>  |
| **Linux**      | https://kernel.org          |  <img src="images/logo_linux.png" style="height:40px; float: center; margin: 0 0 0 0;" alt="GCC"/>  |
