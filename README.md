## Publishing

Pushes to the default branch build and retain the package without publishing it.
To publish, run the **Publish** workflow manually from the default branch. A separate
job downloads that run's package without checking out or building repository code.

Before enabling publication, configure the `nuget-publish` environment with required
reviewers, prevent self-review, and restrict deployments to the default branch.
Store `NUGET_KEY` only as an environment secret, removing any repository-level or
organization-level copy available to this repository. Environment protection rules
must be configured in repository settings; declaring an environment in YAML does
not create approval rules. Review the selected commit and package before approving.

## Contributing

This project welcomes contributions and suggestions.  Most contributions require you to agree to a
Contributor License Agreement (CLA) declaring that you have the right to, and actually do, grant us
the rights to use your contribution. For details, visit https://cla.opensource.microsoft.com.

When you submit a pull request, a CLA bot will automatically determine whether you need to provide
a CLA and decorate the PR appropriately (e.g., status check, comment). Simply follow the instructions
provided by the bot. You will only need to do this once across all repos using our CLA.

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.
