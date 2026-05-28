# Contributing Guide

This project welcomes developers to participate and contribute. Before contributing to the community, please refer to [cann-community](https://gitcode.com/cann/community) to understand the code of conduct, sign the CLA agreement, and learn about the contribution process for source repositories. The repository provides detailed information about prerequisites for contributing to the CANN open source project, including but not limited to:

1. How to submit a PR
2. Gitcode workflow
3. Pipeline trigger commands ([Interaction Reference](https://gitcode.com/cann/infrastructure/blob/main/docs/robot/robot使用指南.md))
4. Code review
5. Other considerations

For details, refer to [cann-community](https://gitcode.com/cann/community).

Additionally, developers should pay attention to the following points when preparing local code and submitting PRs:

1. When submitting a PR, carefully fill in the PR template with information about the business background, purpose, and solution.
2. Before submitting code using git, refer to the [pre-commit tool usage guide](docs/precommit_guide.md) to make your code submission more compliant and efficient.
3. If your modification is not a simple bug fix but involves adding features, interfaces, configuration parameters, or modifying code flow, you must discuss the solution through an Issue first to avoid your code being rejected. If you are unsure whether your modification qualifies as a "simple bug fix," you can also submit an Issue for discussion.
4. When submitting a PR, ensure your code follows the project's code standards. Refer to Google's [Open Source Code Standards](https://google.github.io/styleguide/), including but not limited to:
   - Code formatting
   - Comment standards
   - Variable naming conventions
   - Function naming conventions
   - Class naming conventions
   - Interface naming conventions
   - Configuration parameter naming conventions
   - Code flow standards
5. When submitting a PR, if there are multiple invalid commits, it is recommended to perform a rebase operation before submitting to merge multiple commits into one, maintaining code simplicity and readability. Refer to [git rebase](https://git-scm.com/docs/git-rebase). Additionally, commit messages must follow project code standards and clearly describe the intent and content of the change. Format: `<type>: <brief description>`. For example:

| Type | Description | Example |
|------|-------------|---------|
| feat | New feature | feat: Add user registration function |
| fix | Bug fix | fix: Fix login session expiration issue |
| docs | Documentation update | docs: Update API usage instructions |
| style | Code formatting adjustment (does not affect logic) | style: Adjust code indentation |
| refactor | Refactoring (not feature addition or fix) | refactor: Optimize user service class structure |
| perf | Performance optimization | perf: Reduce database query count |
| test | Test related | test: Add login function unit tests |
| chore | Build/toolchain changes | chore: Update webpack configuration |
| ci | CI configuration related | ci: Add automated testing process |

Developer contribution scenarios mainly include:

- Bug Fix

  If you discover certain bugs in this project and wish to fix them, you are welcome to create an Issue for feedback and tracking.

  You can follow the [Submit Issue/Handle Issue Task](https://gitcode.com/cann/community#提交Issue处理Issue任务) guide to create a `Bug-Report|Bug Feedback` type Issue to describe the bug, then enter `/assign` or `/assign @yourself` in the comment box to assign the Issue to yourself for processing.

- Feature Contribution

  If you discover certain missing features in this project and wish to add them, you are welcome to create an Issue for feedback and tracking.

  You can follow the [Submit Issue/Handle Issue Task](https://gitcode.com/cann/community#提交Issue处理Issue任务) guide to create a `Requirement|Feature Request` type Issue to explain the new feature and provide your design solution, then enter `/assign` or `/assign @yourself` in the comment box to assign the Issue to yourself for tracking and implementation.

- Documentation Correction

  If you discover certain documentation errors in this project, you are welcome to create an Issue for feedback and correction.

  You can follow the [Submit Issue/Handle Issue Task](https://gitcode.com/cann/community#提交Issue处理Issue任务) guide to create a `Documentation|Doc Feedback` type Issue to point out the documentation problem, then enter `/assign` or `/assign @yourself` in the comment box to assign the Issue to yourself to correct the corresponding documentation.

- Help Resolve Others' Issues

  If you have appropriate solutions for problems encountered by others in the community, you are welcome to comment and communicate in the Issue to help others solve problems and improve usability.

  If the corresponding Issue requires code modification, you can enter `/assign` or `/assign @yourself` in the Issue comment box to assign the Issue to yourself and track assistance in resolving the problem.
  