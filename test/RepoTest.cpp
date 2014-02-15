#include "RepoTest.h"
#include "../src/repo.h"

using namespace boost::filesystem;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(RepoTest);

void RepoTest::setUp()
{
    path = unique_path();
    create_directories(path);
    repo = Git::Repo::init(path.string());
}

void RepoTest::tearDown()
{
    remove_all(path);
}

void RepoTest::testInit()
{
    Git::Repo::init(path.string());
}

void RepoTest::testConstructor()
{
    Git::Repo::open(path.string());
}

void RepoTest::testClone()
{
    boost::filesystem::path tmpdir = unique_path();
    repo->clone(tmpdir.string());
    remove_all(tmpdir);
}

void RepoTest::testLookup()
{
    //repo->lookup("HEAD");
}
