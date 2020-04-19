commit_lint.check disable: [:subject_cap]

warn("PR is classed as Work in Progress") if github.pr_title.include? "[WIP]"
warn("Big PR") if git.lines_of_code > 500
