#!/usr/bin/python3

import os
import subprocess


def get_current_repo():
    # get the root directory of current Git repo
    result = subprocess.run(['git', 'rev-parse', '--show-toplevel']
                , stdout=subprocess.PIPE, text=True)   
    # Return the result (trimmed to remove any leading/trailing whitespace)
    return result.stdout.strip()


def git_add_commit_push(commit_message):
    # Get credentials from environment variables
    username = os.getenv("GIT_USERNAME")
    password = os.getenv("GIT_PASSWORD")

    if not (username and password):
        raise ValueError("Git credentials not set in environment variables.")

    # Set the Git username and password for the current session
    os.environ["GIT_TERMINAL_PROMPT"] = "0"
    os.environ["GIT_ASKPASS"] = "/bin/echo"

    # Get the current Git repository
    repo_path = get_current_repo()

    # Git add, commit, and push
    subprocess.run(["git", "-C", repo_path, "add", "."])
    subprocess.run(["git", "-C", repo_path, "commit", "-m", commit_message])

    # Use Git credential caching for username and password
    git_push_command = [
        "git", "-C", repo_path, "push",
        f"https://{username}:{password}@github.com/{username}/{os.path.basename(repo_path)}.git",
        "main"
    ]
    subprocess.run(git_push_command)


if __name__ == "__main__":
    # Get commit message from command line arguments
    commit_message = input("Enter your commit message: ")

    # Call the function with the provided commit message
    git_add_commit_push(commit_message)
