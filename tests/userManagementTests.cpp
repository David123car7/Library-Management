#include "doctest.h"
#include "../src/UserManagement/userManagement.h"

using namespace std;

TEST_CASE("Add User") {
    UserManagement x;

    SUBCASE("User added successfully") {
        CHECK_NOTHROW(x.Add("name", "gender", 18, "email", "111222333"));
    }

    SUBCASE("User add failed (name is empty)") {
        CHECK_THROWS_AS(
            x.Add("", "gender", 18, "email", "111222333"),
            std::invalid_argument
        );
    }

    SUBCASE("User add failed (gender is empty)") {
        CHECK_THROWS_AS(
            x.Add("name", "", 18, "email", "111222333"),
            std::invalid_argument
        );
    }

    SUBCASE("User add failed (age is invalid)") {
        CHECK_THROWS_AS(
            x.Add("name", "gender", -1, "email", "111222333"),
            std::invalid_argument
        );
    }

    SUBCASE("User add failed (email is empty)") {
        CHECK_THROWS_AS(
            x.Add("name", "gender", 18, "", "111222333"),
            std::invalid_argument
        );
    }

    SUBCASE("User add failed (phoneNumber is empty)") {
        CHECK_THROWS_AS(
            x.Add("name", "gender", 18, "email", ""),
            std::invalid_argument
        );
    }
}

TEST_CASE("Remove User"){
	UserManagement x;	

	SUBCASE("User removed sucessfully"){
		x.Add("name", "gender", 18, "email", "111222333");
		CHECK(x.Remove(0) == 1);
	}

	SUBCASE("User was not removed, it did not exist"){
		CHECK(x.Remove(0) == 0);
	}
}
