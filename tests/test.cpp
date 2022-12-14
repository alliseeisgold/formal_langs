#include "../src/Solver.h"
#include <gtest/gtest.h>
#include <map>
using std::string;
using std::map;
using namespace testing;

TEST(AlphaTest, CheckParseError) {
    string tests[] = {"a", "ab", "ab.", "a*", ".", "1", "+a", "eg."}; 
    for (const auto& test : tests) {
        Solver automat(test);
        long long answer = - 1; 
        try {
           	answer = (long long) automat.Solve('a', 1);
           	ASSERT_TRUE(answer >= 0 && answer <= NOT_FOUND);
        } catch (exception& error) {
        	std::cout << error.what() << std::endl;
        	ASSERT_FALSE(answer >= 0 && answer <= NOT_FOUND);
        }
    }
}

TEST(CheckerOfAnswer, NoExceptions) {
	struct {
		string alpha;
		char x;
		size_t k;
		size_t result;
	} tests[] = {
		{"ab+*c*.", 'a', 3, 3},
		{"bb*.a*.", 'a', 3, NOT_FOUND},
		{"ab.a*+", 'a', 2, 2},
		{"ab+c.aba.*.bac.+.+*", 'c', 1, NOT_FOUND},
		{"acb..bab.c.*.ab.ba.+.+*a.", 'b', 3, NOT_FOUND},
		{"acb..bab.c.*.ab.ba.+.+*a.", 'a', 2, NOT_FOUND},
		
	};
	for (const auto& test : tests) {
        Solver automat(test.alpha);
        long long answer = - 1; 
        try {
           	answer = (long long) automat.Solve(test.x, test.k);
           	ASSERT_TRUE(answer == test.result);
        } catch (exception& error) {
        	std::cout << error.what() << std::endl;
        	ASSERT_FALSE(answer == test.result);
        }
    }
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
