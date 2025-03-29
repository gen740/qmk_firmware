{
  description = "Flake shell";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/98b00b6947a9214381112bdb6f89c25498db4959";
  inputs.nixpkgs-latest.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs =
    {
      nixpkgs,
      nixpkgs-latest,
      flake-utils,
      ...
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        pkgs-latest = nixpkgs-latest.legacyPackages.${system};
      in
      {
        devShells.default = import ./shell.nix {
          inherit pkgs;
          extraPkgs = [
            pkgs-latest.pyright
            pkgs-latest.ruff
            pkgs-latest.taplo
          ];
        };
      }
    );
}
