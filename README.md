# Library Management System

A lightweight, terminal-based Library Management System built in C++. This application provides a straightforward interface to manage a library.

**Note:** This is my first-ever real C++ project! I built this from scratch specifically as a hands-on way to learn and practice the fundamentals of the language.

## Features

### User Management
* **Add/Remove Users:** Register new patrons or delete existing accounts.
* **Update Data:** Modify user information and profiles as needed.
* **Ban System:** Restrict specific users from borrowing books by updating their account status.

### Book Management
* **Inventory Control:** Add new books to the catalog or remove unneeded copies.
* **Update Details:** Edit existing book information.
* **Availability Tracking:** Update and check a book's state to ensure it is available for borrowing before a loan is created.

### Loan Management
* **Process Loans:** Assign available books to active, unbanned users.
* **Lifecycle Tracking:** Monitor loans through their specific states (e.g., to pick up, actively loaned, or finished/returned).

## Technology Stack
* **Language:** C++
* **Testing:** doctest (Fast, single-header unit testing framework)
* **Documentation:** Doxygen

## Run

### Run the program
From the project root:

```bash
cd src
make
./program
```

Optional cleanup:

```bash
make clean
```

### Run the tests
From the project root:

```bash
cd tests
make
./run_tests
```

Optional cleanup:

```bash
make clean
```
