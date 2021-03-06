#ifndef GITPP_TEST

#define GITPP_TEST
#include <cppunit/extensions/HelperMacros.h>
#include "boost/filesystem.hpp"
#include "../src/Repository.h"

class CommitTest:public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(CommitTest);
    CPPUNIT_TEST(testCreate);
    CPPUNIT_TEST(testMessage);
    CPPUNIT_TEST_SUITE_END();
  private:
    boost::filesystem::path path;
    std::shared_ptr < Git::Repository > repo;

  public:
    void setUp();
    void tearDown();
    void testInit();
    void testCreate();
    void testMessage();
};

#endif                          // GITPP_TEST
