#include "doctest.h"
#include "../src/UserManagement/userManagement.h"

#include <filesystem>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

namespace {

const filesystem::path USERS_FILE = "data/users.dat";

vector<char> ReadAllBytes(const filesystem::path& filePath) {
    ifstream input(filePath, ios::binary);
    return vector<char>(istreambuf_iterator<char>(input), istreambuf_iterator<char>());
}

void WriteAllBytes(const filesystem::path& filePath, const vector<char>& bytes) {
    ofstream output(filePath, ios::binary | ios::trunc);
    output.write(bytes.data(), static_cast<streamsize>(bytes.size()));
}

struct UsersFileGuard {
    bool hadDataDir;
    bool hadUsersFile;
    vector<char> originalBytes;

    UsersFileGuard() {
        hadDataDir = filesystem::exists("data") && filesystem::is_directory("data");
        hadUsersFile = filesystem::exists(USERS_FILE);
        if (hadUsersFile) {
            originalBytes = ReadAllBytes(USERS_FILE);
        }
        filesystem::create_directories("data");
    }

    ~UsersFileGuard() {
        if (hadUsersFile) {
            WriteAllBytes(USERS_FILE, originalBytes);
        } else {
            error_code ec;
            filesystem::remove(USERS_FILE, ec);
        }

        if (!hadDataDir) {
            error_code ec;
            filesystem::remove_all("data", ec);
        }
    }
};

}

TEST_CASE("Add") {
    UserManagement users;

    SUBCASE("adds a valid user") {
        CHECK(users.Add("name", "gender", 18, "email", "111222333") == 0);
    }

    SUBCASE("throws when name is empty") {
        CHECK_THROWS_AS(users.Add("", "gender", 18, "email", "111222333"), invalid_argument);
    }

    SUBCASE("throws when gender is empty") {
        CHECK_THROWS_AS(users.Add("name", "", 18, "email", "111222333"), invalid_argument);
    }

    SUBCASE("throws when age is below allowed range") {
        CHECK_THROWS_AS(users.Add("name", "gender", -1, "email", "111222333"), invalid_argument);
    }

    SUBCASE("throws when age is above allowed range") {
        CHECK_THROWS_AS(users.Add("name", "gender", 121, "email", "111222333"), invalid_argument);
    }

    SUBCASE("throws when email is empty") {
        CHECK_THROWS_AS(users.Add("name", "gender", 18, "", "111222333"), invalid_argument);
    }

    SUBCASE("throws when phone number is empty") {
        CHECK_THROWS_AS(users.Add("name", "gender", 18, "email", ""), invalid_argument);
    }

    SUBCASE("accepts boundary ages") {
        CHECK(users.Add("age0", "gender", 0, "a@a.com", "111") == 0);
        CHECK(users.Add("age120", "gender", 120, "b@b.com", "222") == 1);
    }

    SUBCASE("assigns sequential ids") {
        CHECK(users.Add("u1", "gender", 20, "u1@mail.com", "100") == 0);
        CHECK(users.Add("u2", "gender", 21, "u2@mail.com", "200") == 1);
        CHECK(users.Add("u3", "gender", 22, "u3@mail.com", "300") == 2);
    }

    SUBCASE("next id follows highest current id after remove") {
        CHECK(users.Add("u1", "gender", 20, "u1@mail.com", "100") == 0);
        CHECK(users.Add("u2", "gender", 21, "u2@mail.com", "200") == 1);
        CHECK(users.Remove(1) == 1);
        CHECK(users.Add("u3", "gender", 22, "u3@mail.com", "300") == 1);
    }
}

TEST_CASE("GetUser") {
    UserManagement users;

    SUBCASE("returns nullptr for missing id") {
        CHECK(users.GetUser(0) == nullptr);
    }

    SUBCASE("returns populated user for existing id") {
        const int id = users.Add("name", "gender", 18, "email@mail.com", "111222333");
        User* user = users.GetUser(id);
        REQUIRE(user != nullptr);
        CHECK(user->GetId() == static_cast<unsigned int>(id));
        CHECK(user->GetName() == "name");
        CHECK(user->GetGender() == "gender");
        CHECK(user->GetAge() == 18);
        CHECK(user->GetEmail() == "email@mail.com");
        CHECK(user->GetPhoneNumber() == "111222333");
    }

    SUBCASE("const overload returns user for existing id") {
        const int id = users.Add("name", "gender", 18, "mail@mail.com", "999999999");
        const UserManagement& constUsers = users;
        const User* user = constUsers.GetUser(id);
        REQUIRE(user != nullptr);
        CHECK(user->GetId() == static_cast<unsigned int>(id));
        CHECK(user->GetName() == "name");
    }

    SUBCASE("const overload returns nullptr for missing id") {
        const UserManagement& constUsers = users;
        CHECK(constUsers.GetUser(999) == nullptr);
    }
}

TEST_CASE("Remove") {
    UserManagement users;

    SUBCASE("returns 0 when user does not exist") {
        CHECK(users.Remove(0) == 0);
    }

    SUBCASE("returns 1 when user exists") {
        const int id = users.Add("name", "gender", 18, "email@mail.com", "111222333");
        CHECK(users.Remove(id) == 1);
    }

    SUBCASE("removes user from map") {
        const int id = users.Add("name", "gender", 18, "email@mail.com", "111222333");
        REQUIRE(users.GetUser(id) != nullptr);
        CHECK(users.Remove(id) == 1);
        CHECK(users.GetUser(id) == nullptr);
    }
}

TEST_CASE("UserExists") {
    UserManagement users;

    SUBCASE("returns false for missing id") {
        CHECK(users.UserExists(0) == false);
    }

    SUBCASE("returns true for existing id") {
        const int id = users.Add("name", "gender", 18, "mail@mail.com", "999999999");
        CHECK(users.UserExists(id) == true);
    }

    SUBCASE("returns false for id that was removed") {
        const int id = users.Add("name", "gender", 18, "mail@mail.com", "999999999");
        REQUIRE(users.UserExists(id) == true);
        REQUIRE(users.Remove(id) == 1);
        CHECK(users.UserExists(id) == false);
    }
}

TEST_CASE("StoreDataInFile") {
    UsersFileGuard guard;
    UserManagement users;

    SUBCASE("returns 1 when file is writable") {
        users.Add("name", "gender", 18, "email@mail.com", "111222333");
        CHECK(users.StoreDataInFile() == 1);
        CHECK(filesystem::exists(USERS_FILE));
    }

    SUBCASE("writes non-empty file after storing at least one user") {
        users.Add("name", "gender", 18, "email@mail.com", "111222333");
        REQUIRE(users.StoreDataInFile() == 1);
        CHECK(filesystem::file_size(USERS_FILE) > 0);
    }
}

TEST_CASE("ReadDataFromFile") {
    UsersFileGuard guard;

    SUBCASE("returns 0 when file does not exist") {
        error_code ec;
        filesystem::remove(USERS_FILE, ec);

        UserManagement users;
        CHECK(users.ReadDataFromFile() == 0);
    }

    SUBCASE("returns 1 and loads saved users") {
        UserManagement writer;
        const int firstId = writer.Add("name1", "gender", 18, "email1@mail.com", "111");
        const int secondId = writer.Add("name2", "gender", 19, "email2@mail.com", "222");
        REQUIRE(writer.StoreDataInFile() == 1);

        UserManagement reader;
        CHECK(reader.ReadDataFromFile() == 1);
        CHECK(reader.GetUser(firstId) != nullptr);
        CHECK(reader.GetUser(secondId) != nullptr);
    }
}

TEST_CASE("PrintUser") {
    UserManagement users;

    SUBCASE("returns 0 when user does not exist") {
        CHECK(users.PrintUser(0) == 0);
    }

    SUBCASE("returns 1 when user exists") {
        const int id = users.Add("name", "gender", 18, "email@mail.com", "111222333");
        CHECK(users.PrintUser(id) == 1);
    }
}

TEST_CASE("PrintUsers") {
    UserManagement users;

    SUBCASE("does not throw when no users exist") {
        CHECK_NOTHROW(users.PrintUsers());
    }

    SUBCASE("does not throw when users exist") {
        users.Add("name", "gender", 18, "email@mail.com", "111222333");
        CHECK_NOTHROW(users.PrintUsers());
    }
}
