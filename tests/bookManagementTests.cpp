#include "doctest.h"
#include "../src/BookManagement/bookManagement.h"
#include <filesystem>

using namespace std;

const filesystem::path TEST_BOOKS_FILE = "data/books_test.csv";

TEST_CASE("BookManagement::Add") {
    BookManagement books;
    Date releaseDate(1, 1, 2020);

    SUBCASE("adds a valid book") {
        CHECK(books.Add("book", "author", releaseDate, BookGenre::fantasy, BookState::available) == 0);
    }

    SUBCASE("throws when name is empty") {
        CHECK_THROWS_AS(books.Add("", "author", releaseDate, BookGenre::fantasy, BookState::available), invalid_argument);
    }

    SUBCASE("throws when author is empty") {
        CHECK_THROWS_AS(books.Add("book", "", releaseDate, BookGenre::fantasy, BookState::available), invalid_argument);
    }

    SUBCASE("assigns sequential ids") {
        CHECK(books.Add("b1", "a1", releaseDate, BookGenre::fantasy, BookState::available) == 0);
        CHECK(books.Add("b2", "a2", releaseDate, BookGenre::horror, BookState::available) == 1);
        CHECK(books.Add("b3", "a3", releaseDate, BookGenre::action, BookState::notAvailable) == 2);
    }

    SUBCASE("next id follows highest current id after remove") {
        CHECK(books.Add("b1", "a1", releaseDate, BookGenre::fantasy, BookState::available) == 0);
        CHECK(books.Add("b2", "a2", releaseDate, BookGenre::horror, BookState::available) == 1);
        CHECK(books.Remove(1) == 1);
        CHECK(books.Add("b3", "a3", releaseDate, BookGenre::action, BookState::available) == 1);
    }
}

TEST_CASE("BookManagement::GetBook") {
    BookManagement books;
    Date releaseDate(10, 2, 2021);

    SUBCASE("returns nullptr for missing id") {
        CHECK(books.GetBook(0) == nullptr);
    }

    SUBCASE("returns populated book for existing id") {
        const int id = books.Add("name", "author", releaseDate, BookGenre::romance, BookState::available);
        Book* book = books.GetBook(id);
        REQUIRE(book != nullptr);
        CHECK(book->GetId() == static_cast<unsigned int>(id));
        CHECK(book->GetName() == "name");
        CHECK(book->GetAuthor() == "author");
        CHECK(book->GetGenre() == BookGenre::romance);
        CHECK(book->GetState() == BookState::available);
    }

    SUBCASE("const overload returns book for existing id") {
        const int id = books.Add("name", "author", releaseDate, BookGenre::action, BookState::notAvailable);
        const BookManagement& constBooks = books;
        const Book* book = constBooks.GetBook(id);
        REQUIRE(book != nullptr);
        CHECK(book->GetId() == static_cast<unsigned int>(id));
        CHECK(book->GetName() == "name");
    }

    SUBCASE("const overload returns nullptr for missing id") {
        const BookManagement& constBooks = books;
        CHECK(constBooks.GetBook(999) == nullptr);
    }
}

TEST_CASE("BookManagement::Remove") {
    BookManagement books;
    Date releaseDate(1, 1, 2020);

    SUBCASE("returns 0 when book does not exist") {
        CHECK(books.Remove(0) == 0);
    }

    SUBCASE("returns 1 when book exists") {
        const int id = books.Add("name", "author", releaseDate, BookGenre::fantasy, BookState::available);
        CHECK(books.Remove(id) == 1);
    }

    SUBCASE("removes book from map") {
        const int id = books.Add("name", "author", releaseDate, BookGenre::fantasy, BookState::available);
        REQUIRE(books.GetBook(id) != nullptr);
        CHECK(books.Remove(id) == 1);
        CHECK(books.GetBook(id) == nullptr);
    }
}

TEST_CASE("BookManagement::BookExists") {
    BookManagement books;
    Date releaseDate(1, 1, 2020);

    SUBCASE("returns false for missing id") {
        CHECK(books.BookExists(0) == false);
    }

    SUBCASE("returns true for existing id") {
        const int id = books.Add("name", "author", releaseDate, BookGenre::fantasy, BookState::available);
        CHECK(books.BookExists(id) == true);
    }

    SUBCASE("returns false for id that was removed") {
        const int id = books.Add("name", "author", releaseDate, BookGenre::fantasy, BookState::available);
        REQUIRE(books.Remove(id) == 1);
        CHECK(books.BookExists(id) == false);
    }
}

TEST_CASE("BookManagement::GetBooksQnt") {
    BookManagement books;
    Date releaseDate(1, 1, 2020);

    SUBCASE("returns 0 when map is empty") {
        CHECK(books.GetBooksQnt() == 0);
    }

    SUBCASE("returns number of books in map") {
        books.Add("b1", "a1", releaseDate, BookGenre::fantasy, BookState::available);
        books.Add("b2", "a2", releaseDate, BookGenre::horror, BookState::notAvailable);
        CHECK(books.GetBooksQnt() == 2);
    }
}

TEST_CASE("BookManagement::GetAvailableBooksQnt") {
    BookManagement books;
    Date releaseDate(1, 1, 2020);

    SUBCASE("returns 0 when map is empty") {
        CHECK(books.GetAvailableBooksQnt() == 0);
    }

    SUBCASE("counts only available books") {
        books.Add("b1", "a1", releaseDate, BookGenre::fantasy, BookState::available);
        books.Add("b2", "a2", releaseDate, BookGenre::horror, BookState::notAvailable);
        books.Add("b3", "a3", releaseDate, BookGenre::action, BookState::available);
        CHECK(books.GetAvailableBooksQnt() == 2);
    }
}

TEST_CASE("BookManagement::GetNotAvailableBooksQnt") {
    BookManagement books;
    Date releaseDate(1, 1, 2020);

    SUBCASE("returns 0 when map is empty") {
        CHECK(books.GetNotAvailableBooksQnt() == 0);
    }

    SUBCASE("counts only not available books") {
        books.Add("b1", "a1", releaseDate, BookGenre::fantasy, BookState::available);
        books.Add("b2", "a2", releaseDate, BookGenre::horror, BookState::notAvailable);
        books.Add("b3", "a3", releaseDate, BookGenre::action, BookState::notAvailable);
        CHECK(books.GetNotAvailableBooksQnt() == 2);
    }
}

TEST_CASE("BookManagement::StoreDataInFile") {
    BookManagement books;
    Date releaseDate(1, 1, 2020);
    filesystem::create_directories("data");
    error_code ec;
    filesystem::remove(TEST_BOOKS_FILE, ec);

    SUBCASE("returns 1 when file is writable") {
        books.Add("name", "author", releaseDate, BookGenre::fantasy, BookState::available);
        CHECK(books.StoreDataInFile(TEST_BOOKS_FILE.string()) == 1);
        CHECK(filesystem::exists(TEST_BOOKS_FILE));
    }

    SUBCASE("writes non-empty file after storing at least one book") {
        books.Add("name", "author", releaseDate, BookGenre::fantasy, BookState::available);
        REQUIRE(books.StoreDataInFile(TEST_BOOKS_FILE.string()) == 1);
        CHECK(filesystem::file_size(TEST_BOOKS_FILE) > 0);
    }

    filesystem::remove(TEST_BOOKS_FILE, ec);
}

TEST_CASE("BookManagement::ReadDataFromFile") {
    filesystem::create_directories("data");
    error_code ec;
    filesystem::remove(TEST_BOOKS_FILE, ec);

    SUBCASE("returns 0 when file does not exist") {
        BookManagement books;
        CHECK(books.ReadDataFromFile(TEST_BOOKS_FILE.string()) == 0);
    }

    SUBCASE("returns 1 and loads saved books") {
        Date d1(1, 1, 2020);
        Date d2(2, 2, 2021);
        BookManagement writer;
        const int id1 = writer.Add("name1", "author1", d1, BookGenre::fantasy, BookState::available);
        const int id2 = writer.Add("name2", "author2", d2, BookGenre::horror, BookState::notAvailable);
        REQUIRE(writer.StoreDataInFile(TEST_BOOKS_FILE.string()) == 1);

        BookManagement reader;
        CHECK(reader.ReadDataFromFile(TEST_BOOKS_FILE.string()) == 1);
        const Book* b1 = reader.GetBook(id1);
        const Book* b2 = reader.GetBook(id2);
        REQUIRE(b1 != nullptr);
        REQUIRE(b2 != nullptr);
        CHECK(b1->GetName() == "name1");
        CHECK(b2->GetState() == BookState::notAvailable);
    }

    filesystem::remove(TEST_BOOKS_FILE, ec);
}

TEST_CASE("BookManagement::PrintBook") {
    BookManagement books;
    Date releaseDate(1, 1, 2020);

    SUBCASE("returns 0 when book does not exist") {
        CHECK(books.PrintBook(0) == 0);
    }

    SUBCASE("returns 1 when book exists") {
        const int id = books.Add("name", "author", releaseDate, BookGenre::fantasy, BookState::available);
        CHECK(books.PrintBook(id) == 1);
    }
}

TEST_CASE("BookManagement::PrintBooks") {
    BookManagement books;
    Date releaseDate(1, 1, 2020);

    SUBCASE("does not throw when no books exist") {
        CHECK_NOTHROW(books.PrintBooks());
    }

    SUBCASE("does not throw when books exist") {
        books.Add("name", "author", releaseDate, BookGenre::fantasy, BookState::available);
        CHECK_NOTHROW(books.PrintBooks());
    }
}
