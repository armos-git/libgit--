#include "repo.h"
#include "commit.h"
#include "exception.h"

namespace Git {
    Commit::Commit(std::shared_ptr < Git::Repo > repo) {
        this->repo = repo;
        this->__message = std::shared_ptr < std::string> (new std::string);
    }

    std::shared_ptr < Commit > Commit::create(std::shared_ptr < Git::Repo >
                                              repo) {
        return std::shared_ptr < Commit > (new Commit(repo));
    }

    void Commit::message(const std::string & msg) {
        this->__message->assign(msg);
    }

    const std::shared_ptr < std::string > Commit::message() {
        return this->__message;
    }

    git_oid Commit::update() {
        git_signature *sig;
        git_index *index;
        git_oid tree_id, commit_id;
        git_tree *tree;

        Throw(git_signature_default(&sig, repo->ptr()));
        Throw(git_repository_index(&index, repo->ptr()));
        Throw(git_index_write_tree(&tree_id, index));
        git_index_free(index);

        git_tree_lookup(&tree, repo->ptr(), &tree_id);
        git_commit_create_v(&commit_id, repo->ptr(), "HEAD", sig, sig,
                            NULL, message()->c_str(), tree, 0);
        return commit_id;
    }
}
