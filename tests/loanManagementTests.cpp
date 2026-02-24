#include "doctest.h"
#include "../src/LoanManagement/loanManagement.h"

#include <filesystem>

using namespace std;

const filesystem::path TEST_LOANS_FILE = "data/loans_test.csv";
const filesystem::path TEST_USER_LOANS_FILE = "data/user_loans_test.csv";
const filesystem::path TEST_BOOK_LOANS_FILE = "data/book_loans_test.csv";

TEST_CASE("LoanManagement::GetNextId") {
    LoanManagement loans;
    Date start(1, 1, 2020);
    Date end(10, 1, 2020);
    Date delivered(0, 0, 0);

    SUBCASE("returns 0 when there are no loans") {
        CHECK(loans.GetNextId() == 0);
    }

    SUBCASE("returns next id after adding loans") {
        loans.Add(10, 20, start, end, delivered, LoanState::toPickUp);
        loans.Add(11, 21, start, end, delivered, LoanState::loaned);
        CHECK(loans.GetNextId() == 2);
    }
}

TEST_CASE("LoanManagement::Add") {
    LoanManagement loans;
    Date start(1, 1, 2020);
    Date end(10, 1, 2020);
    Date delivered(0, 0, 0);

    SUBCASE("adds a loan and returns its id") {
        CHECK(loans.Add(10, 20, start, end, delivered, LoanState::toPickUp) == 0);
    }

    SUBCASE("assigns sequential ids") {
        CHECK(loans.Add(10, 20, start, end, delivered, LoanState::toPickUp) == 0);
        CHECK(loans.Add(11, 21, start, end, delivered, LoanState::loaned) == 1);
        CHECK(loans.Add(12, 22, start, end, delivered, LoanState::finished) == 2);
    }
}

TEST_CASE("LoanManagement::Remove") {
    LoanManagement loans;
    Date start(1, 1, 2020);
    Date end(10, 1, 2020);
    Date delivered(0, 0, 0);

    SUBCASE("returns 0 when loan does not exist") {
        CHECK(loans.Remove(0) == 0);
    }

    SUBCASE("returns 1 when loan exists") {
        const int id = loans.Add(10, 20, start, end, delivered, LoanState::toPickUp);
        CHECK(loans.Remove(id) == 1);
    }

    SUBCASE("removes loan from map") {
        const int id = loans.Add(10, 20, start, end, delivered, LoanState::toPickUp);
        REQUIRE(loans.GetLoan(id) != nullptr);
        CHECK(loans.Remove(id) == 1);
        CHECK(loans.GetLoan(id) == nullptr);
    }
}

TEST_CASE("LoanManagement::GetLoan") {
    LoanManagement loans;
    Date start(1, 1, 2020);
    Date end(10, 1, 2020);
    Date delivered(0, 0, 0);

    SUBCASE("returns nullptr for missing id") {
        CHECK(loans.GetLoan(0) == nullptr);
    }

    SUBCASE("returns loan for existing id") {
        const int id = loans.Add(10, 20, start, end, delivered, LoanState::loaned);
        Loan* loan = loans.GetLoan(id);
        REQUIRE(loan != nullptr);
        CHECK(loan->GetId() == id);
        CHECK(loan->GetBookId() == 10);
        CHECK(loan->GetUserId() == 20);
        CHECK(loan->GetState() == LoanState::loaned);
    }

    SUBCASE("const overload returns loan for existing id") {
        const int id = loans.Add(10, 20, start, end, delivered, LoanState::toPickUp);
        const LoanManagement& constLoans = loans;
        const Loan* loan = constLoans.GetLoan(id);
        REQUIRE(loan != nullptr);
        CHECK(loan->GetId() == id);
    }

    SUBCASE("const overload returns nullptr for missing id") {
        const LoanManagement& constLoans = loans;
        CHECK(constLoans.GetLoan(999) == nullptr);
    }
}

TEST_CASE("LoanManagement::LoanExists") {
    LoanManagement loans;
    Date start(1, 1, 2020);
    Date end(10, 1, 2020);
    Date delivered(0, 0, 0);

    SUBCASE("returns false for missing id") {
        CHECK(loans.LoanExists(0) == false);
    }

    SUBCASE("returns true for existing id") {
        const int id = loans.Add(10, 20, start, end, delivered, LoanState::toPickUp);
        CHECK(loans.LoanExists(id) == true);
    }

    SUBCASE("returns false after removing id") {
        const int id = loans.Add(10, 20, start, end, delivered, LoanState::toPickUp);
        REQUIRE(loans.Remove(id) == 1);
        CHECK(loans.LoanExists(id) == false);
    }
}

TEST_CASE("LoanManagement::ExistsKeyUserMap") {
    LoanManagement loans;

    SUBCASE("returns false when key is missing") {
        CHECK(loans.ExistsKeyUserMap(100) == false);
    }

    SUBCASE("returns true when key exists") {
        REQUIRE(loans.AddIdUserMap(100, 1) == 1);
        CHECK(loans.ExistsKeyUserMap(100) == true);
    }
}

TEST_CASE("LoanManagement::ExistsKeyBookMap") {
    LoanManagement loans;

    SUBCASE("returns false when key is missing") {
        CHECK(loans.ExistsKeyBookMap(200) == false);
    }

    SUBCASE("returns true when key exists") {
        REQUIRE(loans.AddIdBookMap(200, 1) == 1);
        CHECK(loans.ExistsKeyBookMap(200) == true);
    }
}

TEST_CASE("LoanManagement::LoanIdUserMapExists") {
    LoanManagement loans;

    SUBCASE("returns false when key is missing") {
        CHECK(loans.LoanIdUserMapExists(100, 1) == false);
    }

    SUBCASE("returns false when id is not in key vector") {
        REQUIRE(loans.AddIdUserMap(100, 2) == 1);
        CHECK(loans.LoanIdUserMapExists(100, 1) == false);
    }

    SUBCASE("returns true when id is in key vector") {
        REQUIRE(loans.AddIdUserMap(100, 1) == 1);
        CHECK(loans.LoanIdUserMapExists(100, 1) == true);
    }
}

TEST_CASE("LoanManagement::LoanIdBookMapExists") {
    LoanManagement loans;

    SUBCASE("returns false when key is missing") {
        CHECK(loans.LoanIdBookMapExists(200, 1) == false);
    }

    SUBCASE("returns false when id is not in key vector") {
        REQUIRE(loans.AddIdBookMap(200, 2) == 1);
        CHECK(loans.LoanIdBookMapExists(200, 1) == false);
    }

    SUBCASE("returns true when id is in key vector") {
        REQUIRE(loans.AddIdBookMap(200, 1) == 1);
        CHECK(loans.LoanIdBookMapExists(200, 1) == true);
    }
}

TEST_CASE("LoanManagement::GetUserLoanIds") {
    LoanManagement loans;

    SUBCASE("returns nullptr when key does not exist") {
        CHECK(loans.GetUserLoanIds(100) == nullptr);
    }

    SUBCASE("returns vector pointer when key exists") {
        REQUIRE(loans.AddIdUserMap(100, 1) == 1);
        REQUIRE(loans.AddIdUserMap(100, 2) == 1);
        const vector<unsigned int>* ids = loans.GetUserLoanIds(100);
        REQUIRE(ids != nullptr);
        CHECK(ids->size() == 2);
    }
}

TEST_CASE("LoanManagement::AddIdUserMap") {
    LoanManagement loans;

    SUBCASE("adds id for new key") {
        CHECK(loans.AddIdUserMap(100, 1) == 1);
        CHECK(loans.LoanIdUserMapExists(100, 1) == true);
    }

    SUBCASE("does not add duplicate id for same key") {
        REQUIRE(loans.AddIdUserMap(100, 1) == 1);
        CHECK(loans.AddIdUserMap(100, 1) == 0);
    }
}

TEST_CASE("LoanManagement::RemoveIdUserMap") {
    LoanManagement loans;

    SUBCASE("returns 0 when key does not exist") {
        CHECK(loans.RemoveIdUserMap(100, 1) == 0);
    }

    SUBCASE("returns 0 when id does not exist in key") {
        REQUIRE(loans.AddIdUserMap(100, 2) == 1);
        CHECK(loans.RemoveIdUserMap(100, 1) == 0);
    }

    SUBCASE("returns 1 and removes existing id") {
        REQUIRE(loans.AddIdUserMap(100, 1) == 1);
        CHECK(loans.RemoveIdUserMap(100, 1) == 1);
        CHECK(loans.LoanIdUserMapExists(100, 1) == false);
    }
}

TEST_CASE("LoanManagement::AddIdBookMap") {
    LoanManagement loans;

    SUBCASE("adds id for new key") {
        CHECK(loans.AddIdBookMap(200, 1) == 1);
        CHECK(loans.LoanIdBookMapExists(200, 1) == true);
    }

    SUBCASE("does not add duplicate id for same key") {
        REQUIRE(loans.AddIdBookMap(200, 1) == 1);
        CHECK(loans.AddIdBookMap(200, 1) == 0);
    }
}

TEST_CASE("LoanManagement::RemoveIdBookMap") {
    LoanManagement loans;

    SUBCASE("returns 0 when key does not exist") {
        CHECK(loans.RemoveIdBookMap(200, 1) == 0);
    }

    SUBCASE("returns 0 when id does not exist in key") {
        REQUIRE(loans.AddIdBookMap(200, 2) == 1);
        CHECK(loans.RemoveIdBookMap(200, 1) == 0);
    }

    SUBCASE("returns 1 and removes existing id") {
        REQUIRE(loans.AddIdBookMap(200, 1) == 1);
        CHECK(loans.RemoveIdBookMap(200, 1) == 1);
        CHECK(loans.LoanIdBookMapExists(200, 1) == false);
    }
}

TEST_CASE("LoanManagement::GetUserMapSize") {
    LoanManagement loans;

    SUBCASE("returns 0 when key does not exist") {
        CHECK(loans.GetUserMapSize(100) == 0);
    }

    SUBCASE("returns vector size for existing key") {
        REQUIRE(loans.AddIdUserMap(100, 1) == 1);
        REQUIRE(loans.AddIdUserMap(100, 2) == 1);
        CHECK(loans.GetUserMapSize(100) == 2);
    }
}

TEST_CASE("LoanManagement::StoreLoansDataInFile") {
    LoanManagement loans;
    filesystem::create_directories("data");
    error_code ec;
    filesystem::remove(TEST_LOANS_FILE, ec);

    Date start(1, 1, 2020);
    Date end(10, 1, 2020);
    Date delivered(0, 0, 0);

    SUBCASE("returns 1 when path is writable") {
        loans.Add(10, 20, start, end, delivered, LoanState::toPickUp);
        CHECK(loans.StoreLoansDataInFile(TEST_LOANS_FILE.string()) == 1);
        CHECK(filesystem::exists(TEST_LOANS_FILE));
    }

    SUBCASE("writes non-empty file when there are loans") {
        loans.Add(10, 20, start, end, delivered, LoanState::toPickUp);
        REQUIRE(loans.StoreLoansDataInFile(TEST_LOANS_FILE.string()) == 1);
        CHECK(filesystem::file_size(TEST_LOANS_FILE) > 0);
    }

    filesystem::remove(TEST_LOANS_FILE, ec);
}

TEST_CASE("LoanManagement::ReadLoansDataFromFile") {
    LoanManagement loans;
    filesystem::create_directories("data");
    error_code ec;
    filesystem::remove(TEST_LOANS_FILE, ec);

    Date start(1, 1, 2020);
    Date end(10, 1, 2020);
    Date delivered(0, 0, 0);

    SUBCASE("returns 0 when file does not exist") {
        CHECK(loans.ReadLoansDataFromFile(TEST_LOANS_FILE.string()) == 0);
    }

    SUBCASE("returns 1 and loads loans from file") {
        LoanManagement writer;
        const int id1 = writer.Add(10, 20, start, end, delivered, LoanState::toPickUp);
        const int id2 = writer.Add(11, 21, start, end, delivered, LoanState::loaned);
        REQUIRE(writer.StoreLoansDataInFile(TEST_LOANS_FILE.string()) == 1);

        LoanManagement reader;
        CHECK(reader.ReadLoansDataFromFile(TEST_LOANS_FILE.string()) == 1);
        CHECK(reader.GetLoan(id1) != nullptr);
        CHECK(reader.GetLoan(id2) != nullptr);
    }

    filesystem::remove(TEST_LOANS_FILE, ec);
}

TEST_CASE("LoanManagement::StoreUserLoansDataInFile") {
    LoanManagement loans;
    filesystem::create_directories("data");
    error_code ec;
    filesystem::remove(TEST_USER_LOANS_FILE, ec);

    SUBCASE("returns 1 when path is writable") {
        loans.AddIdUserMap(100, 1);
        CHECK(loans.StoreUserLoansDataInFile(TEST_USER_LOANS_FILE.string()) == 1);
        CHECK(filesystem::exists(TEST_USER_LOANS_FILE));
    }

    SUBCASE("writes non-empty file when map has data") {
        loans.AddIdUserMap(100, 1);
        REQUIRE(loans.StoreUserLoansDataInFile(TEST_USER_LOANS_FILE.string()) == 1);
        CHECK(filesystem::file_size(TEST_USER_LOANS_FILE) > 0);
    }

    filesystem::remove(TEST_USER_LOANS_FILE, ec);
}

TEST_CASE("LoanManagement::ReadUserLoansDataFromFile") {
    filesystem::create_directories("data");
    error_code ec;
    filesystem::remove(TEST_USER_LOANS_FILE, ec);

    SUBCASE("returns 0 when file does not exist") {
        LoanManagement loans;
        CHECK(loans.ReadUserLoansDataFromFile(TEST_USER_LOANS_FILE.string()) == 0);
    }

    SUBCASE("returns 1 and loads user loan map") {
        LoanManagement writer;
        writer.AddIdUserMap(100, 1);
        writer.AddIdUserMap(100, 2);
        REQUIRE(writer.StoreUserLoansDataInFile(TEST_USER_LOANS_FILE.string()) == 1);

        LoanManagement reader;
        CHECK(reader.ReadUserLoansDataFromFile(TEST_USER_LOANS_FILE.string()) == 1);
        CHECK(reader.ExistsKeyUserMap(100) == true);
        CHECK(reader.LoanIdUserMapExists(100, 1) == true);
        CHECK(reader.LoanIdUserMapExists(100, 2) == true);
    }

    filesystem::remove(TEST_USER_LOANS_FILE, ec);
}

TEST_CASE("LoanManagement::StoreBookLoansDataInFile") {
    LoanManagement loans;
    filesystem::create_directories("data");
    error_code ec;
    filesystem::remove(TEST_BOOK_LOANS_FILE, ec);

    SUBCASE("returns 1 when path is writable") {
        loans.AddIdBookMap(200, 1);
        CHECK(loans.StoreBookLoansDataInFile(TEST_BOOK_LOANS_FILE.string()) == 1);
        CHECK(filesystem::exists(TEST_BOOK_LOANS_FILE));
    }

    SUBCASE("writes non-empty file when map has data") {
        loans.AddIdBookMap(200, 1);
        REQUIRE(loans.StoreBookLoansDataInFile(TEST_BOOK_LOANS_FILE.string()) == 1);
        CHECK(filesystem::file_size(TEST_BOOK_LOANS_FILE) > 0);
    }

    filesystem::remove(TEST_BOOK_LOANS_FILE, ec);
}

TEST_CASE("LoanManagement::ReadBookLoansDataFromFile") {
    filesystem::create_directories("data");
    error_code ec;
    filesystem::remove(TEST_BOOK_LOANS_FILE, ec);

    SUBCASE("returns 0 when file does not exist") {
        LoanManagement loans;
        CHECK(loans.ReadBookLoansDataFromFile(TEST_BOOK_LOANS_FILE.string()) == 0);
    }

    SUBCASE("returns 1 and loads book loan map") {
        LoanManagement writer;
        writer.AddIdBookMap(200, 1);
        writer.AddIdBookMap(200, 2);
        REQUIRE(writer.StoreBookLoansDataInFile(TEST_BOOK_LOANS_FILE.string()) == 1);

        LoanManagement reader;
        CHECK(reader.ReadBookLoansDataFromFile(TEST_BOOK_LOANS_FILE.string()) == 1);
        CHECK(reader.ExistsKeyBookMap(200) == true);
        CHECK(reader.LoanIdBookMapExists(200, 1) == true);
        CHECK(reader.LoanIdBookMapExists(200, 2) == true);
    }

    filesystem::remove(TEST_BOOK_LOANS_FILE, ec);
}

TEST_CASE("LoanManagement::PrintLoans") {
    LoanManagement loans;
    Date start(1, 1, 2020);
    Date end(10, 1, 2020);
    Date delivered(0, 0, 0);

    SUBCASE("does not throw when empty") {
        CHECK_NOTHROW(loans.PrintLoans());
    }

    SUBCASE("does not throw when there are loans") {
        loans.Add(10, 20, start, end, delivered, LoanState::toPickUp);
        CHECK_NOTHROW(loans.PrintLoans());
    }
}

TEST_CASE("LoanManagement::PrintLoan") {
    LoanManagement loans;
    Date start(1, 1, 2020);
    Date end(10, 1, 2020);
    Date delivered(0, 0, 0);

    SUBCASE("returns 0 when loan does not exist") {
        CHECK(loans.PrintLoan(0) == 0);
    }

    SUBCASE("returns 1 when loan exists") {
        const int id = loans.Add(10, 20, start, end, delivered, LoanState::toPickUp);
        CHECK(loans.PrintLoan(id) == 1);
    }
}

TEST_CASE("LoanManagement::PrintUserLoans") {
    LoanManagement loans;
    Date start(1, 1, 2020);
    Date end(10, 1, 2020);
    Date delivered(0, 0, 0);

    SUBCASE("returns 0 when user key does not exist") {
        CHECK(loans.PrintUserLoans(100) == 0);
    }

    SUBCASE("returns 1 when user key exists") {
        const int id = loans.Add(10, 100, start, end, delivered, LoanState::toPickUp);
        REQUIRE(loans.AddIdUserMap(100, id) == 1);
        CHECK(loans.PrintUserLoans(100) == 1);
    }
}
